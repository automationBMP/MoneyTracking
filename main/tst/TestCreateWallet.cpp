/*
	Author: AndreeaIoanaStan
	
	This file contains tests for checking if a new wallet is created
	
*/

#include "gtest/gtest.h"

#include "TestHelperCreateWallet.h"

TEST(TestCreateWallet, FileContent)
{
	DoCreateWallet wallet("WalletTest","+100");
	DoCreateWallet wallet("yetother" , "-1021.23");
	DoCreateWallet wallet("noWallet");
	DoCreateWallet wallet("yetother" , "-0021.23");
	
	EXPECT_EQ("+100.00 RON" , ReadWallet("my.wallet"));
	EXPECT_EQ("-1021.23 RON" , ReadWallet("yetother"));
	EXPECT_EQ("+00.00 RON" , ReadWallet("noWallet"));
	EXPECT_EQ("-21.23 RON" , ReadWallet("my.wallet"));
}

TEST(TestCreateWallet, CreateFile)
{
	DoCreateWallet wallet("newWallet");
	DoCreateWallet wallet("C:/Learn/MoneyTracking/WalletTest.txt","+100");
	
	EXPECT_EQ(true , walletCreated("newWallet"));
	EXPECT_EQ(true , walletCreated("C:/Learn/MoneyTracking/WalletTest.txt"));
}