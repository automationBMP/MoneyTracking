// Author Tudor Chibulcutean, v0.2

#include "gtest/gtest.h"
#include "DoCreateWallet.h"

#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
//using namespace std;

// function to return wallet as string
 std::string ReturnWalletasString(DoCreateWallet wallet)
{
	//read moneytracker.config file
	std::ifstream ifs("WalletTest");
	
	//the content of moneytracker.config is transfered to string content
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	
	return content;
}

// function to return time, sign, amount, category and currency
/* std::string ReturnContent()
{
	
} */

// TestAddLineinWallet implementation

TEST(TestAddLineinWallet, Income)
{
	// Create Wallet
	DoCreateWallet wallet("WalletTest","33");
	wallet.CreateWalletFile();
	
	// Add Income
	Error_E a = wallet.AddLineInWalletFile("+100", "income");
	time_t result = time(0);
	
	// return wallet as string
	std::string walletFile = ReturnWalletasString(wallet);
	
	// get the content of file without initial amount (first line)
	walletFile = walletFile.substr(walletFile.find("\n") + 1, std::string::npos);
	
	// convert the time to char
	char buffer [33];
	itoa (result,buffer,10);
	
	// get the epochTime as string
	std::string epochTime = walletFile.substr(0, walletFile.find(';'));
	
	EXPECT_EQ(buffer, epochTime);
	
	// get the content of file without epochTime
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the sign
	std::string sign = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("+", sign);
	
	// get the content of file without epochTime and sign
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the amount
	std::string amount = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("100", amount);
	
	// get the content of file without epochTime and sign and amount
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the category
	std::string category = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("salary", category);
	
	// get the content of file without epochTime and sign and amount and category
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the currency
	std::string currency = walletFile.substr(0, walletFile.find("\n"));
	
	std::cout << "\n\n" << currency << "\n\n";
	
	EXPECT_EQ("RON", currency);
	
}

TEST(TestAddLineInWallet, Spend)
{
	// Create Wallet
	DoCreateWallet wallet("WalletTest","33");
	wallet.CreateWalletFile();
	
	time_t result = time(0);
	
	// Add Spending
	Error_E b = wallet.AddLineInWalletFile("+99", "spend");
	
	// return wallet as string
	std::string walletFile = ReturnWalletasString(wallet);
	
	// get the content of file without initial amount (first line)
	walletFile = walletFile.substr(walletFile.find("\n") + 1, std::string::npos);
	
	// convert the time to char
	char buffer [33];
	itoa (result,buffer,10);
	
	// get the epochTime as string
	std::string epochTime = walletFile.substr(0, walletFile.find(';'));
	
	EXPECT_EQ(buffer, epochTime);
	
	// get the content of file without epochTime
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the sign
	std::string sign = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("-", sign);
	
	// get the content of file without epochTime and sign
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the amount
	std::string amount = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("99", amount);
	
	// get the content of file without epochTime and sign and amount
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the category
	std::string category = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("other", category);
	
	// get the content of file without epochTime and sign and amount and category
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the currency
	std::string currency = walletFile.substr(0, walletFile.find("\n"));
	
	EXPECT_EQ("RON", currency);
}