#include <iostream>
#include "FileManager.h"
#include "utils.h"
#include <string>

using namespace std;

void printUsage()
{
	std::cout << "***********Usage*********" << std::endl;
	std::cout << "ls - list all file in current folder" << std::endl;
	std::cout << "mkdir [<directory>] - create new directory" << std::endl;
	std::cout << "touch [<file_name>] - create new file" << std::endl;
	std::cout << "rm [<file_name>] - delete file or directory" << std::endl;
	std::cout << "print - print file system tree from current index" << std::endl;
	std::cout << "cd [<path>]" << std::endl;
}

int main(int argc, char* argv[]) {

	FileManager* fileMgr = FileManager::GetInstance();
	fileMgr->print();
	while (true)
	{
		std::cout << "++++++++++++++++++++";
		std::string inputLine;
		std::cout << "Enter cmd: ";
		std::getline(std::cin, inputLine);
		std::vector<std::string> args = utils::split(inputLine, " ");
		if (!args.at(0).compare("help"))
		{
			printUsage();
		}
		else if (!args.at(0).compare("print"))
		{
			fileMgr->print();
		}
		else if (!args.at(0).compare("ls"))
		{
			fileMgr->ls();
		}
		else if (!args.at(0).compare("mkdir"))
		{
			fileMgr->mkdir(args.at(1));
		}
		else if (!args.at(0).compare("touch"))
		{
			fileMgr->touch(args.at(1));
		}
		else if (!args.at(0).compare("rm"))
		{
			fileMgr->rm(args.at(1));
		}
		else if (!args.at(0).compare("print"))
		{
			fileMgr->print();
		}
		else if (!args.at(0).compare("cd"))
		{
			fileMgr->cd(args.at(1));
		}
	}

	return 0;
}
