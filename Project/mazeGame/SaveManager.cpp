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

void SaveManager::saveToFile(std::shared_ptr<SaveableData> _dataToSave, std::string _fileName)
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

	std::ofstream savingFile(filePath);

	if (!savingFile.is_open())
	{
		throw std::runtime_error("Couldn't open the file: " + filePath.string());
	}

	savingFile << "level\n" << _dataToSave->level << '\n';
	savingFile << "isCompleted\n" << _dataToSave->isLevelCompleted << '\n';
	savingFile << "playerX\n" << _dataToSave->playerPosition.x << '\n';
	savingFile << "playerY\n" << _dataToSave->playerPosition.y << '\n';
	savingFile << "playerAngle\n" << _dataToSave->playerAngle << '\n';
	savingFile << "mapWidth\n" << _dataToSave->mapWidth << '\n';
	savingFile << "mapHeight\n" << _dataToSave->mapHeight << '\n';
	savingFile << "map\n";

	for (unsigned int i = 0; i < _dataToSave->mapHeight; i++)
	{
		for (unsigned int j = 0; j < _dataToSave->mapWidth; j++)
		{
			savingFile << _dataToSave->map[i * _dataToSave->mapWidth + j];
		}
		savingFile << "\n";
	}

	savingFile.close();
	std::cout << "SUCCESS" << std::endl;
}

std::unique_ptr<SaveableData> SaveManager::loadFromFile()
{
	return nullptr;
}

void SaveManager::setSaveDirectory(std::filesystem::path _saveDirectory)
{
	this->saveDirectory = _saveDirectory;
}

std::filesystem::path SaveManager::getSaveDirectory()
{
	return this->saveDirectory;
}
