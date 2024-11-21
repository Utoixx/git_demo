#include <iostream>
#include "File.h"

using namespace std;

File::File(const string& name, const int size)
	: size(size)
{
	FileSystemElement::name = name;
}

File::~File()
{

}

const string File::getName() const
{
	return name;
}

const int File::getSize() const
{
	return size;
}

void File::print(const string& upper_path) const
{
	cout << upper_path << "/" << toString() << endl;
}

bool File::isFile() const
{
	return true;
}
