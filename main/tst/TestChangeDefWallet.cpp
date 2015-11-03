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
			std::cout << std::endl 
					  << std::endl 
					  << lineStr 
					  << std::endl 
					  << std::endl;
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
	char* argumente[4]= {(char*)"moneytracker", (char*)"config", 
	(char*)"default_wallet=", (char*)"mywallet"};
	ImplementConfig(4, argumente);
	std::string expected = "default_wallet = mywallet";
	EXPECT_EQ(expected, ReturnWalletNameLine());
}

//Test 2
TEST(ChangeDefWallet, SpacesBeforeEqualDefaultWallet)
{
	char* argumente[5]= {(char*)"moneytracker", (char*)"config", 
	(char*)"default_wallet", (char*)"=", (char*)"mywallet"};
	ImplementConfig(5, argumente);
	std::string expected = "default_wallet = mywallet";
	EXPECT_EQ(expected, ReturnWalletNameLine());
}

/* //Test 3
TEST(ChangeDefWallet, ErrorTooManyArgumentsAfterConfig)
{
	char* argumente[6]= {(char*)"moneytracker", (char*)"config", 
	(char*)"tesallet", (char*)"testwllet", (char*)"default_wallet",
	(char*)"testwallet"};
	ImplementConfig(6, argumente);
	std::string expected = "default_wallet = testwallet";
	EXPECT_EQ(expected, ReturnWalletNameLine());
}

//Test 4
TEST(ChangeDefWallet, CorectDefaultWallet)
{
	char* argumente[4]= {(char*)"moneytracker", (char*)"config", 
	(char*)"default_wallet=", (char*)"testwallet"};
	ImplementConfig(4, argumente);
	std::string expected = "default_wallet = testwallet";
	EXPECT_EQ(expected, ReturnWalletNameLine());
}

//Test 5
TEST(ChangeDefWallet, CorectDefaultWallet)
{
	char* argumente[4]= {(char*)"moneytracker", (char*)"config", 
	(char*)"default_wallet=", (char*)"testwallet"};
	ImplementConfig(4, argumente);
	std::string expected = "default_wallet = testwallet";
	EXPECT_EQ(expected, ReturnWalletNameLine());
}

//Test 6
TEST(ChangeDefWallet, CorectDefaultWallet)
{
	char* argumente[4]= {(char*)"moneytracker", (char*)"config", 
	(char*)"default_wallet=", (char*)"testwallet"};
	ImplementConfig(4, argumente);
	std::string expected = "default_wallet = testwallet";
	EXPECT_EQ(expected, ReturnWalletNameLine());
} */