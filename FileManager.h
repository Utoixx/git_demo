#pragma once
#include "Directory.h"
#include <string>
#include <memory>

class FileManager
{
protected:
	FileManager();
	static FileManager* instance;
	std::shared_ptr<Directory> root;
	std::weak_ptr<Directory> currentDir;

public:
	FileManager(FileManager& other) = delete;
    void operator=(const FileManager&) = delete;

	static FileManager* GetInstance();
	int mkdir(std::string dir);
	int touch(std::string file);
	int rm(std::string file);
	int ls();
	int cd(std::string dir);
	int print();
};

