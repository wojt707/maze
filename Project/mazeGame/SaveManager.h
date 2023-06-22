#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H
#pragma once

#include <filesystem>
#include <fstream>
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

	// Delete the copy constructor
	SaveManager(const SaveManager&) = delete;
	// Delete the copy assignment operator
	SaveManager& operator=(const SaveManager&) = delete;

	void saveToFile(std::shared_ptr<SaveableData> _dataToSave, std::string _fileName = "default");
	std::unique_ptr<SaveableData> loadFromFile();

	void setSaveDirectory(std::filesystem::path _saveDirectory);
	std::filesystem::path getSaveDirectory();
};

#endif // !SAVE_MANAGER_H
