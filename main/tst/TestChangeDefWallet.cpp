//Author: AndreeaIoanaStan, v0.3

#include "gtest/gtest.h"
#include "ReadConfig.h"
#include "string"
#include <fstream>
#include "MainFunctions.h"

std::string ReturnWalletNameLine()
{
	std::string fileName;
	fileName = "moneytracker.config";
	std::ifstream file(fileName.c_str());
	//std::string lastLine;
	std::string line;
	if(file.is_open())
	{
		while(getline(file,line))
		{
			bool isEmpty = true;
			for(unsigned int i = 0; i< line.size(); i++)
			{
				char ch = line[i];
				isEmpty = isEmpty && isspace(ch);
			}
			size_t lineStr = line.find("default_wallet ");
			std::cout << std::endl << std::endl << lineStr << std::endl << std::endl;
			if ( lineStr != std::string::npos)
			{
				return line;
				break;
			}
			else
			{
				
			}
			/* if(!isEmpty)
			{
	
			lastLine = line; 
			} */
		}
				
		file.close();
	}
	return line;
}

//Test 1
TEST(ChangeDefWallet, CorectDefaultWallet)
{
	char* argumente[4]= {(char*)"moneytracker", (char*)"config", (char*)"default_wallet=", (char*)"testwallet"};
	ImplementConfig(4, argumente);
	std::string expected = "default_wallet = testwallet";
	EXPECT_EQ(expected, ReturnWalletNameLine());
}