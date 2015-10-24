//Author: AndreeaIoanaStan, v0.1

#include "gtest/gtest.h"
#include "DoCreateWallet.h"
#include <fstream>
#include <string>

using namespace std;
//helper function for reading from the file created and return the content
string ReadWallet(const string &walletName)
{
	
	ifstream wallet(walletName.c_str());
	
	std::string walletContent;
	
	//read from the given file
	getline(wallet,walletContent);
	wallet.close();
	
	return walletContent;
}

//helper function for checking if the file has been created
bool WalletCreated(const string &walletName)
{
	bool isCreated = false;
	ifstream wallet(walletName.c_str());
	
	if(wallet.good())
	{
		wallet.close();
		isCreated = true;
	}
	else 
	{
		isCreated = false;
	}
	wallet.close();
	return isCreated;
}

TEST(TestCreateWallet, FileContent)
{
	DoCreateWallet wallet("my.wallet", "+100");
	wallet.CreateWalletFile();
	DoCreateWallet wallet1("yetother", "-1021.23");
	wallet1.CreateWalletFile();
	//DoCreateWallet wallet4("noWallet","0");
	//wallet4.CreateWalletFile();
	DoCreateWallet wallet3("my.wallet1" , "-0021.23");
	wallet3.CreateWalletFile();
	
	EXPECT_EQ("+100.00 RON" , ReadWallet("my.wallet"));
	EXPECT_EQ("-1021.23 RON" , ReadWallet("yetother"));
	//EXPECT_EQ("+0.0 RON" , ReadWallet("noWallet"));
	EXPECT_EQ("-21.23 RON" , ReadWallet("my.wallet1"));
}

TEST(TestCreateWallet, CreateFile)
{
	DoCreateWallet wallet("newWallet","+100");
	wallet.CreateWalletFile();
	DoCreateWallet wallet1("main/tst/WalletTest.txt","+100");
	wallet1.CreateWalletFile();	
	EXPECT_EQ(true , WalletCreated("newWallet"));
	EXPECT_EQ(true , WalletCreated("main/tst/WalletTest.txt"));
	EXPECT_NE(true , WalletCreated("main/src/WalletTest.txt"));
	EXPECT_NE(true , WalletCreated("inexistent.txt"));
}