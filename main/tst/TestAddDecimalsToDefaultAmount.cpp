/*
	Author: AndreeaIoanaStan
	
	This file contains the tests for AddDecimalsToDefaultAmount method
	
*/
	
#include "gtest/gtest.h" 

#include "..\inc\PrintError.h"
#include "..\inc\Types.h"
#include "..\inc\DoCreateWallet.h"


//TestCase1
TEST(AddDecimalsToDefaultAmount, NoPointPresent)
{
	DoCreateWallet wallet("WalletTest","+100");
	ASSERT_EQ(wallet.AddDecimalsToDefaultAmount, "+100.00")
}

//TestCase2
TEST(AddDecimalsToDefaultAmount, PointPresentLastPosition)
{
	DoCreateWallet wallet("WalletTest","100.");
	ASSERT_EQ(wallet.AddDecimalsToDefaultAmount, "+100.00")
}

//TestCase3
TEST(AddDecimalsToDefaultAmount, OneDecimalAfterPoint)
{
	DoCreateWallet wallet("WalletTest","1.3");
	ASSERT_EQ(wallet.AddDecimalsToDefaultAmount, "+1.30")
}

//TestCase4
TEST(AddDecimalsToDefaultAmount, TwoDecimalsAfterPoint)
{
	DoCreateWallet wallet("WalletTest","1.34");
	ASSERT_EQ(wallet.AddDecimalsToDefaultAmount, "+1.34")
}

//TestCase5
TEST(AddDecimalsToDefaultAmount, ThreeDecimalsAfterPoint)
{
	DoCreateWallet wallet("WalletTest","1.342");
	ASSERT_EQ(wallet.AddDecimalsToDefaultAmount, "+1.34")
}

//TestCase6
TEST(AddDecimalsToDefaultAmount, ThreeDecimalsAfterPoint2)
{
	DoCreateWallet wallet("WalletTest","1.345");
	ASSERT_EQ(wallet.AddDecimalsToDefaultAmount, "+1.35")
}

//TestCase7
TEST(AddDecimalsToDefaultAmount, Decimals99AfterPoint)
{
	DoCreateWallet wallet("WalletTest","18.99");
	ASSERT_EQ(wallet.AddDecimalsToDefaultAmount, "+19.00")
}

//TestCase8
TEST(AddDecimalsToDefaultAmount, Decimals99AfterAndBeforePoint)
{
	DoCreateWallet wallet("WalletTest","99.99");
	ASSERT_EQ(wallet.AddDecimalsToDefaultAmount, "+100.00")
}

//TestCase9
TEST(AddDecimalsToDefaultAmount, Decimals99AndMoreAfterPoint)
{
	DoCreateWallet wallet("WalletTest","184.9992321");
	ASSERT_EQ(wallet.AddDecimalsToDefaultAmount, "+185.00")
}

//TestCase10
TEST(AddDecimalsToDefaultAmount, Decimals99AfterPointOneCharacterBeforePoint)
{
	DoCreateWallet wallet("WalletTest","8.99");
	ASSERT_EQ(wallet.AddDecimalsToDefaultAmount, "+9.00")
}