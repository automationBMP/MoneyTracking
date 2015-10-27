#include "gtest/gtest.h"
#include "DoCreateWallet.h"
#include "GetBalance.h"

#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>

// function to return wallet as string
 std::string ReturnWalletString(DoCreateWallet &wallet)
{
	//read moneytracker.config file
	std::ifstream ifs("main\\tst\\WalletBalance");
	
	//the content of moneytracker.config is transfered to string content
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	ifs.close();
	return content;
}
//=============================================================================

TEST(TestGetBalance, ZeroAmountBalance)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalance","+00.00");
	wallet.CreateWalletFile();
	
	//convert file content to string
	std::string walletFile = ReturnWalletString(wallet);
	
	EXPECT_EQ("+0",balance.PrintBalance(walletFile));
}
//=============================================================================

TEST(TestGetBalance, NegAmountBalance)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalance","-200.55");
	wallet.CreateWalletFile();
	
	//convert file content to string
	std::string walletFile = ReturnWalletString(wallet);
	
	EXPECT_EQ("-200.55",balance.PrintBalance(walletFile));

}
//=============================================================================

TEST(TestGetBalance, PosAmountBalance)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalance","+200.55");
	wallet.CreateWalletFile();
	
	//convert file content to string
	std::string walletFile = ReturnWalletString(wallet);
	
	EXPECT_EQ("+200.55",balance.PrintBalance(walletFile));
}
//=============================================================================

TEST(TestGetBalance, IncomeAmountBalance)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalance","+200.55");
	wallet.CreateWalletFile();
	
	//add income
	std::string amountt = "+100";
	std::string choise = "income";
	std::string category1 = "salary";
	DoCreateWallet wallet1("main\\tst\\WalletBalance",amountt);
	wallet1.AddLineInWalletFile(amountt, choise, category1);
	
	//add income
	amountt = "+700";
	choise = "income";
	category1 = "bonus";
	DoCreateWallet wallet2("main\\tst\\WalletBalance",amountt);
	wallet2.AddLineInWalletFile(amountt, choise, category1);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString(wallet);
	//std :: cout<<walletFile;
	
	EXPECT_EQ("+1000.55",balance.PrintBalance(walletFile));
}
//=============================================================================

TEST(TestGetBalance, SpendAmountBalance)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalance","+200.55");
	wallet.CreateWalletFile();
	
	//add income
	std::string amountt = "100";
	std::string choise = "spend";
	std::string category1 = "donation";
	DoCreateWallet wallet1("main\\tst\\WalletBalance",amountt);
	wallet1.AddLineInWalletFile(amountt, choise, category1);
	
	//add income
	amountt = "700";
	choise = "spend";
	category1 = "food";
	DoCreateWallet wallet2("main\\tst\\WalletBalance",amountt);
	wallet2.AddLineInWalletFile(amountt, choise, category1);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString(wallet);
	//std :: cout<<walletFile;
	
	EXPECT_EQ("-599.45",balance.PrintBalance(walletFile));
}
//=============================================================================