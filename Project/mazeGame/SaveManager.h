#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H
#pragma once

#include <filesystem>
#include <fstream>
#include <regex>
#include <ranges>
#include <memory>
#include <string>
#include <iostream>

#include "SaveableData.h"

class SaveManager
{
private:
	std::filesystem::path saveDirectory;
public:
	SaveManager();
	SaveManager(std::filesystem::path& _saveDirectory);

	// Delete the copy constructor
	SaveManager(const SaveManager&) = delete;
	// Delete the copy assignment operator
	SaveManager& operator=(const SaveManager&) = delete;

	void saveToFile(std::shared_ptr<SaveableData> _dataToSave, std::string _fileName = "default") const;
	std::shared_ptr<SaveableData> loadFromFile(std::string& _fileName) const;
	std::shared_ptr<SaveableData> loadFromPath(std::filesystem::path& _pathToSaveFile) const;

	void setSaveDirectory(std::filesystem::path& _saveDirectory);
	std::filesystem::path getSaveDirectory() const;
};

#endif // !SAVE_MANAGER_H
