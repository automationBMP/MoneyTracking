//Author: AndreeaIoanaStan, v0.2

#include "gtest/gtest.h"
#include "ReadConfig.h"
#include "string"
#include <fstream>

//helper function to copy a file's content into a string
std::string ReturnFileAsStringHelper(std::ifstream &configFile)
{	
	//the content of moneytracker.config is transfered to string content
    std::string content( (std::istreambuf_iterator<char>(configFile) ),
                       (std::istreambuf_iterator<char>()    ) );
	
	return content;
}

//Test 1 
TEST(GetWalletName, NoDefaultWallet)
{
	std::ifstream configFile("main\\tst\\ConfigFiles\\no_default_wallet.config");
	std::string content = ReturnFileAsStringHelper(configFile);
	ReadConfig wallet;
	std::string actual = "Error";
	
	EXPECT_EQ(actual, wallet.GetDefaultWallet(content));
}

//Test 2 
TEST(GetWalletName, SpacesBeforeDefWallet)
{
	std::ifstream configFile("main\\tst\\ConfigFiles\\spaces_before_def_wallet.config");
	std::string content = ReturnFileAsStringHelper(configFile);
	ReadConfig wallet;
	std::string actual = "mywallet";
	
	EXPECT_EQ(actual, wallet.GetDefaultWallet(content));
}

//Test 3 
TEST(GetWalletName, SpacesAfterDefWallet)
{
	std::ifstream configFile("main\\tst\\ConfigFiles\\spaces_after_def_wallet.config");
	std::string content = ReturnFileAsStringHelper(configFile);
	ReadConfig wallet;
	std::string actual = "mywallet";
	
	EXPECT_EQ(actual, wallet.GetDefaultWallet(content));
}

//Test 4
TEST(GetWalletName, EmptyAfterDefWallet)
{
	std::ifstream configFile("main\\tst\\ConfigFiles\\empty_after_def_wallet.config");
	std::string content = ReturnFileAsStringHelper(configFile);
	ReadConfig wallet;
	std::string actual = "";
	
	EXPECT_EQ(actual, wallet.GetDefaultWallet(content));
}

//Test 5
TEST(GetWalletName, EmptyAfterEqual)
{
	std::ifstream configFile("main\\tst\\ConfigFiles\\empty_after_equal.config");
	std::string content = ReturnFileAsStringHelper(configFile);
	ReadConfig wallet;
	std::string actual = "";
	
	EXPECT_EQ(actual, wallet.GetDefaultWallet(content));
}

//Test 6
TEST(GetWalletName, MoreDefWallet)
{
	std::ifstream configFile("main\\tst\\ConfigFiles\\more_def_wallet.config");
	std::string content = ReturnFileAsStringHelper(configFile);
	ReadConfig wallet;
	std::string actual = "mywallet";
	
	EXPECT_EQ(actual, wallet.GetDefaultWallet(content));
}

//Test 7
TEST(GetWalletName, NoConfig)
{
	std::ifstream configFile("main\\tst\\ConfigFiles\\no_config.config");
	std::string content = ReturnFileAsStringHelper(configFile);
	ReadConfig wallet;
	std::string actual = "NoConfig";
	
	EXPECT_EQ(actual, wallet.GetDefaultWallet(content));
}