#include <iostream>
#include "Directory.h"
#include "FileSystemElement.h"

using namespace std;

Directory::Directory(const string& name, std::weak_ptr<Directory> parentDir)
	: parentDir(parentDir)
{
	FileSystemElement::name = name;
	elements.clear();
}

Directory::~Directory()
{
}

const string Directory::getName() const
{
	return name;
}

const int Directory::getSize() const
{
	int size = 0;
	for (auto itr : elements) {
		size += itr.get()->getSize();
	}

	return size;
}

void Directory::print(const string& upper_path) const
{
	cout << upper_path << "/" << this->toString() << endl;
	for (auto itr : elements) {
		itr.get()->print(upper_path + "/" + name);
	}
}

void Directory::printOnlyItsElement()
{
	for (auto itr : elements) {
		if(!itr.get()->isFile())
			cout << itr.get()->getName() << "/" << endl;
		else
			cout << itr.get()->toString() << endl;
	}
}

void Directory::add(std::shared_ptr<FileSystemElement> element)
{
	elements.push_back(element);
}

void Directory::erase(std::string fileSystemName)
{
	for (auto itr = elements.begin(); itr != elements.end();)
	{
		if (!itr->get()->getName().compare(fileSystemName))
		{
			elements.erase(itr);
			break;
		}
		++itr;
	}
}

bool Directory::isFile() const
{
	return false;
}

std::weak_ptr<Directory> Directory::find(std::string dir)
{
	for (auto& element : elements)
	{
		if (!element.get()->getName().compare(dir)
			&& !element.get()->isFile())
			return std::dynamic_pointer_cast<Directory>(element);
	}

	return std::weak_ptr<Directory>();
}

std::weak_ptr<Directory> Directory::getParentDir()
{
	return parentDir;
}
