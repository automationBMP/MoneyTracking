// author Tudor Chibulcutean, v0.3

#include "gtest/gtest.h"
#include "DoCreateWallet.h"
#include "GetBalance.h"

#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>

// function to return wallet as string
 std::string ReturnWalletString77(DoCreateWallet &wallet)
{
	//read moneytracker.config file
	std::ifstream ifs("WalletBalanceCategory");
	
	//the content of moneytracker.config is transfered to string content
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	ifs.close();
	return content;
}
//=============================================================================

/* TEST(TestGetBalanceCategory, ZeroAmountBalance)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalance","+10.00");
	wallet.CreateWalletFile();
	
	//convert file content to string
	std::string walletFile = ReturnWalletString(wallet);
	
	EXPECT_EQ("+0",balance.PrintBalance(walletFile,"salary"));
} */
//=============================================================================

/* TEST(TestGetBalanceCategory, NegAmountBalance)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalance","-200.55");
	wallet.CreateWalletFile();
	
	//convert file content to string
	std::string walletFile = ReturnWalletString(wallet);
	
	EXPECT_EQ("-200.55",balance.PrintBalance(walletFile,""));

} */
//=============================================================================

/* TEST(TestGetBalanceCategory, PosAmountBalance)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalance","+200.55");
	wallet.CreateWalletFile();
	
	//convert file content to string
	std::string walletFile = ReturnWalletString(wallet);
	
	EXPECT_EQ("+200.55",balance.PrintBalance(walletFile,""));
} */
//=============================================================================

/* TEST(TestGetBalanceCategory, IncomeAmountBalance)
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
	
	EXPECT_EQ("+1000.55",balance.PrintBalance(walletFile,""));
} */
//=============================================================================

TEST(TestGetBalanceCategory, SpendAmountBalance1)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("WalletBalanceCategory","+200.55");
	wallet.CreateWalletFile();
	
	//add income
	std::string amount = "100";
	std::string choice = "spend";
	std::string category1 = "donation";
	std::string wallet7 = "";
	DoCreateWallet wallet1("WalletBalanceCategory",amount);
	wallet1.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "700";
	choice = "spend";
	category1 = "donation";
	DoCreateWallet wallet2("WalletBalanceCategory",amount);
	wallet2.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString77(wallet);
	//std :: cout<<walletFile;
	
	EXPECT_EQ("-800",balance.PrintBalance(walletFile,"donation"));
}
