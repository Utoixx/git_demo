#pragma once
#include <string>

using namespace std;
class FileSystemElement
{
public:
	FileSystemElement();
	virtual ~FileSystemElement();
	virtual const string getName() const = 0;
	virtual const int getSize() const = 0;
	virtual bool isFile() const = 0;
	virtual void print(const string& upper_path) const = 0;
	virtual const string toString() const;
	
};
