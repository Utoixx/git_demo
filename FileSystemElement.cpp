#include "FileSystemElement.h"
#include "iostream"

FileSystemElement::FileSystemElement()
{
}

FileSystemElement::~FileSystemElement()
{
}

const string FileSystemElement::toString() const
{
	if(isFile())
		return getName() + " (" + to_string(getSize()) + ")";
	else
		return getName() + "/";
}