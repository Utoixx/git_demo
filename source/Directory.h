#pragma once
#include <string>
#include <vector>
#include "FileSystemElement.h"
#include <memory>

using namespace std;

class Directory : public FileSystemElement
{
private:
	vector<std::shared_ptr<FileSystemElement>> elements;
	std::weak_ptr<Directory> parentDir;

public:

	Directory(const string& name, std::weak_ptr<Directory> parentDir);
	~Directory();
	const string getName() const;
	const int getSize() const;
	void print(const string& upper_path) const;
	void printOnlyItsElement();
	void add(std::shared_ptr<FileSystemElement> element);
	void erase(std::string fileSystemName);
	bool isFile() const;

	std::weak_ptr<Directory> find(std::string dir);
	std::weak_ptr<Directory> getParentDir();
public:
	
protected:
	
private:
	Directory(const Directory&) = delete;
	Directory& operator=(const Directory&) = delete;
	Directory(Directory&&) = delete;
	Directory& operator=(Directory&&) = delete;
};
