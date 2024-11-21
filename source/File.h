#pragma once
#include <string>
#include "FileSystemElement.h"

using namespace std;
class File : public FileSystemElement
{
private:
	const string name;
	const int size;
private:
	File(const File&) = delete;
	File& operator=(const File&) = delete;
	File(File&&) = delete;
	File& operator=(File&&) = delete;

public:
	File(const string& name, const int size);
	~File();
	const string getName() const;
	const int getSize() const;
	void print(const string& upper_path) const;
	bool isFile() const;
};
