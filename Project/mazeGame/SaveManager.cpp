#include "SaveManager.h"

SaveManager::SaveManager()
{
	this->saveDirectory = std::filesystem::current_path() / "saves";
	if (!std::filesystem::exists(this->saveDirectory))
	{
		std::filesystem::create_directory(this->saveDirectory);
		std::cout << "saves directory created" << std::endl;
	}
	std::cout << "SaveManager created" << std::endl;
	std::cout << this->saveDirectory << std::endl;
}

SaveManager::SaveManager(std::filesystem::path& _saveDirectory)
	:saveDirectory(_saveDirectory)
{
	if (!std::filesystem::exists(this->saveDirectory))
	{
		std::filesystem::create_directory(this->saveDirectory);
		std::cout << "saves directory created" << std::endl;
	}
	std::cout << "SaveManager created" << std::endl;
	std::cout << this->saveDirectory << std::endl;
}

void SaveManager::saveToFile(std::shared_ptr<SaveableData> _dataToSave, std::string _fileName) const
{
	std::filesystem::path filePath(this->saveDirectory / ((_fileName.empty()) ? "default" : _fileName));
	std::string extension = filePath.extension().string();

	if (extension.empty() || extension != ".txt")
	{
		extension = ".txt";
		filePath.replace_extension(extension);
	}

	int counter = 1;
	while (std::filesystem::exists(filePath))
	{
		std::string stem = filePath.stem().string();
		auto it = std::ranges::find(stem | std::views::reverse, '_');
		if (it != stem.rend())
			stem.erase(it.base() - 1, stem.end());

		filePath.replace_filename(stem + '_' + std::to_string(counter) + extension);
		counter++;
	}

	std::ofstream saveFile(filePath);

	if (!saveFile.is_open())
	{
		throw std::runtime_error("Couldn't open the file: " + filePath.string());
	}

	saveFile << "level " << _dataToSave->level << '\n'
		<< "isCompleted " << _dataToSave->isLevelCompleted << '\n'
		<< "playerX " << _dataToSave->playerPosition.x << '\n'
		<< "playerY " << _dataToSave->playerPosition.y << '\n'
		<< "playerAngle " << _dataToSave->playerAngle << '\n'
		<< "mapWidth " << _dataToSave->mapWidth << '\n'
		<< "mapHeight " << _dataToSave->mapHeight << '\n'
		<< "map ";

	for (unsigned int i = 0; i < _dataToSave->mapHeight * _dataToSave->mapWidth; i++)
	{
		saveFile << _dataToSave->map[i];
	}

	saveFile.close();
	std::cout << "saving to file SUCCESS" << std::endl;
}

std::shared_ptr<SaveableData> SaveManager::loadFromFile(std::string& _fileName) const
{
	std::filesystem::path filePath(this->saveDirectory / _fileName);

	return this->loadFromPath(filePath);
}

std::shared_ptr<SaveableData> SaveManager::loadFromPath(std::filesystem::path& _pathToSaveFile) const
{
	if (!std::filesystem::exists(_pathToSaveFile))
	{
		throw std::runtime_error("The file: " + _pathToSaveFile.string() + " doesn't exist");
	}

	std::ifstream saveFile(_pathToSaveFile);

	if (!saveFile.is_open())
	{
		throw std::runtime_error("Couldn't open the file: " + _pathToSaveFile.string());
	}

	std::stringstream buffer;
	buffer << saveFile.rdbuf();
	std::string fileContent = buffer.str();

	std::shared_ptr<SaveableData> loadedData = std::make_shared<SaveableData>();

	const std::regex saveDataRegex(
		R"(\s*level\s+(\d+))"
		R"(\s*isCompleted\s+([01]))"
		R"(\s*playerX\s+([-+]?\d+(?:[.]\d+)?))"
		R"(\s*playerY\s+([-+]?\d+(?:[.]\d+)?))"
		R"(\s*playerAngle\s+(\d+(?:[.]\d+)?))"
		R"(\s*mapWidth\s+(\d+))"
		R"(\s*mapHeight\s+(\d+))"
		R"(\s*map\s+([01]+))"
	);

	std::smatch match;

	if (!std::regex_match(fileContent, match, saveDataRegex))
	{
		throw std::runtime_error("Invalid file content: " + fileContent);
	}

	loadedData->level = std::stoi(match[1].str());
	loadedData->isLevelCompleted = (match[2].str() == "1");
	loadedData->playerPosition.x = std::stof(match[3].str());
	loadedData->playerPosition.y = std::stof(match[4].str());
	loadedData->playerAngle = std::stof(match[5].str());
	loadedData->mapWidth = std::stoi(match[6].str());
	loadedData->mapHeight = std::stoi(match[7].str());

	const std::string& mapData = match[8].str();
	if (mapData.size() != loadedData->mapWidth * loadedData->mapHeight)
	{
		throw std::runtime_error("Map size: " + std::to_string(mapData.size()) + " is not equal to mapWidth * mapHeight:" + std::to_string(loadedData->mapWidth * loadedData->mapHeight));
	}

	loadedData->map = std::make_shared<bool[]>(loadedData->mapWidth * loadedData->mapHeight);

	std::ranges::transform(mapData, loadedData->map.get(), [](char c) { return (c == '1'); });

	saveFile.close();

	std::cout << "loading from file SUCCESS" << std::endl;

	return loadedData;
}

void SaveManager::setSaveDirectory(std::filesystem::path& _saveDirectory)
{
	this->saveDirectory = _saveDirectory;
}

std::filesystem::path SaveManager::getSaveDirectory() const
{
	return this->saveDirectory;
}
