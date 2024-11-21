#include "FileManager.h"
#include "File.h"
#include "utils.h"
#include "vector"
#include <iostream>

FileManager* FileManager::instance = nullptr;

FileManager::FileManager(): root(new Directory("/root", std::weak_ptr<Directory>()))
{
	currentDir = root;
}

FileManager* FileManager::GetInstance()
{
	if (instance == nullptr)
		instance = new FileManager();

	return instance;
}

int FileManager::mkdir(std::string dir)
{
	std::vector<std::string> arr = utils::split(dir, "/");
	auto oldCurrentDir = currentDir;
	int ret = 0;

	for (auto& itr : arr)
	{
		auto newCurrentDir = currentDir.lock().get()->find(itr);
		if (newCurrentDir.lock())
			currentDir = newCurrentDir;
		else
		{
			auto newDir = std::make_shared<Directory>(itr, currentDir);
			currentDir.lock().get()->add(newDir);
			currentDir = newDir;
		}
	}

	currentDir = oldCurrentDir;

	return ret;
}

int FileManager::touch(std::string file)
{
	std::vector<std::string> arr = utils::split(file, "/");
	auto fileName = arr.back();
	arr.pop_back();
	auto oldCurrentDir = currentDir;
	int ret = 0;

	for (auto& itr : arr)
	{
		auto newCurrentDir = currentDir.lock().get()->find(itr);
		if (newCurrentDir.lock())
			currentDir = newCurrentDir;
		else
		{
			auto newDir = std::make_shared<Directory>(itr, currentDir);
			currentDir.lock().get()->add(newDir);
			currentDir = newDir;
		}
	}

	auto fileObj =  std::make_shared<File>(fileName, 0);
	currentDir.lock().get()->add(fileObj);
	currentDir = oldCurrentDir;

	return 0;
}

int FileManager::rm(std::string file)
{
	std::vector<std::string> arr = utils::split(file, "/");
	auto last = arr.back();
	arr.pop_back();
	auto oldCurrentDir = currentDir;
	int ret = 0;

	for (auto& itr : arr)
	{
		auto newCurrentDir = currentDir.lock().get()->find(itr);
		if (newCurrentDir.lock())
			currentDir = newCurrentDir;
	}

	currentDir.lock().get()->erase(last);
	currentDir = oldCurrentDir;

	return 0;
}

int FileManager::print()
{
	currentDir.lock().get()->print("");
	return 0;
}

int FileManager::ls()
{
	currentDir.lock().get()->printOnlyItsElement();
	return 0;
}

int FileManager::cd(std::string dir)
{
	if (!dir.compare(".."))
	{
		auto parentDir = currentDir.lock().get()->getParentDir();
		if (parentDir.lock())
		{
			currentDir = parentDir;
		}

		return 0;
	}

	auto newCurrentDir = currentDir.lock().get()->find(dir);
	if (newCurrentDir.lock())
	{
		currentDir = newCurrentDir;
	}
	else
	{
		std::cout << "directory not found" << std::endl;
	}

	return 0;
}
