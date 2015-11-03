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
	std::ifstream ifs("main\\tst\\WalletBalanceCategory");
	
	//the content of moneytracker.config is transfered to string content
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	ifs.close();
	return content;
}

//=============================================================================

TEST(TestGetBalanceCategory, SpendCategory)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalanceCategory","+200.55");
	wallet.CreateWalletFile();
	
	//add spend
	std::string amount = "100";
	std::string choice = "spend";
	std::string category1 = "donation";
	std::string wallet7 = "";
	DoCreateWallet wallet1("main\\tst\\WalletBalanceCategory",amount);
	wallet1.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add spend
	amount = "700";
	choice = "spend";
	category1 = "donation";
	DoCreateWallet wallet2("main\\tst\\WalletBalanceCategory",amount);
	wallet2.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString77(wallet);
	//std :: cout<<walletFile;
	
	EXPECT_EQ("-800",balance.PrintBalance(walletFile,"donation"));
}

//=============================================================================

TEST(TestGetBalanceCategory, IncomeCategory)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalanceCategory","+200.55");
	wallet.CreateWalletFile();
	
	//add income
	std::string amount = "100";
	std::string choice = "income";
	std::string category1 = "acategory";
	std::string wallet7 = "";
	DoCreateWallet wallet1("main\\tst\\WalletBalanceCategory",amount);
	wallet1.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "700";
	//choice = "income";
	category1 = "bcategory";
	DoCreateWallet wallet2("main\\tst\\WalletBalanceCategory",amount);
	wallet2.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString77(wallet);
	//std :: cout<<walletFile;
	
	EXPECT_EQ("+100",balance.PrintBalance(walletFile,"acategory"));
}

//=============================================================================

TEST(TestGetBalanceCategory, IncomeSpendSameCategory)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalanceCategory","+200.55");
	wallet.CreateWalletFile();
	
	//add spend
	std::string amount = "10";
	std::string choice = "spend";
	std::string category1 = "bcategory";
	std::string wallet7 = "";
	DoCreateWallet wallet1("main\\tst\\WalletBalanceCategory",amount);
	wallet1.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "9";
	choice = "income";
	category1 = "bcategory";
	DoCreateWallet wallet2("main\\tst\\WalletBalanceCategory",amount);
	wallet2.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString77(wallet);
	//std :: cout<<walletFile;
	
	EXPECT_EQ("-1",balance.PrintBalance(walletFile,"bcategory"));
}

//=============================================================================

TEST(TestGetBalanceCategory, IncomeSpendDifferentCategory)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalanceCategory","+200.55");
	wallet.CreateWalletFile();
	
	//add spend
	std::string amount = "10";
	std::string choice = "spend";
	std::string category1 = "category_f";
	std::string wallet7 = "";
	DoCreateWallet wallet1("main\\tst\\WalletBalanceCategory",amount);
	wallet1.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "9";
	choice = "income";
	category1 = "category_g";
	DoCreateWallet wallet2("main\\tst\\WalletBalanceCategory",amount);
	wallet2.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString77(wallet);
	//std :: cout<<walletFile;
	
	EXPECT_EQ("-10",balance.PrintBalance(walletFile,"category_f"));
}

//=============================================================================

TEST(TestGetBalanceCategory, IncomeSpendDifferentCategoryBalanceZero)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalanceCategory","+200.55");
	wallet.CreateWalletFile();
	
	//add spend
	std::string amount = "10";
	std::string choice = "spend";
	std::string category1 = "category_h";
	std::string wallet7 = "";
	DoCreateWallet wallet1("main\\tst\\WalletBalanceCategory",amount);
	wallet1.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "9";
	choice = "income";
	category1 = "category_i";
	DoCreateWallet wallet2("main\\tst\\WalletBalanceCategory",amount);
	wallet2.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "10";
	choice = "income";
	category1 = "category_h";
	DoCreateWallet wallet3("main\\tst\\WalletBalanceCategory",amount);
	wallet3.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString77(wallet);
	//std :: cout<<walletFile;
	
	EXPECT_EQ("+0",balance.PrintBalance(walletFile,"category_h"));
}