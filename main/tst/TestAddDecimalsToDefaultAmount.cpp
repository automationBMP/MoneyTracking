/*
	Author: AndreeaIoanaStan
	
	This file contains the tests for AddDecimalsToDefaultAmount method
	
*/
	
#include "gtest/gtest.h" 

#include "..\inc\PrintError.h"
#include "..\inc\Types.h"
#include "..\inc\DoCreateWallet.h"
#include <cstring>


//TestCase1
TEST(AddDecimalsToDefaultAmount, NoPointPresent)
{
	DoCreateWallet wallet("WalletTest","+100");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+100.00");
}

//TestCase2
TEST(AddDecimalsToDefaultAmount, PointPresentLastPosition)
{
	DoCreateWallet wallet("WalletTest","100.");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+100.00");
}

//TestCase3
TEST(AddDecimalsToDefaultAmount, OneDecimalAfterPoint)
{
	DoCreateWallet wallet("WalletTest","1.3");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+1.30");
}

//TestCase4
TEST(AddDecimalsToDefaultAmount, TwoDecimalsAfterPoint)
{
	DoCreateWallet wallet("WalletTest","1.34");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+1.34");
}

//TestCase5
TEST(AddDecimalsToDefaultAmount, ThreeDecimalsAfterPoint)
{
	DoCreateWallet wallet("WalletTest","1.342");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+1.34");
}

//TestCase6
TEST(AddDecimalsToDefaultAmount, ThreeDecimalsAfterPoint2)
{
	DoCreateWallet wallet("WalletTest","1.345");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+1.35");
}

//TestCase7
TEST(AddDecimalsToDefaultAmount, Decimals99AfterPoint)
{
	DoCreateWallet wallet("WalletTest","18.99");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+18.99");
}

//TestCase8
TEST(AddDecimalsToDefaultAmount, Decimals99AfterAndBeforePoint)
{
	DoCreateWallet wallet("WalletTest","99.99");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+99.99");
}

//TestCase9
TEST(AddDecimalsToDefaultAmount, Decimals99AndMoreAfterPoint)
{
	DoCreateWallet wallet("WalletTest","184.999");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+185.00");
}

//TestCase10
TEST(AddDecimalsToDefaultAmount, Decimals99AfterPointOneCharacterBeforePoint)
{
	DoCreateWallet wallet("WalletTest","+8.99");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+8.99");
}
/*//TestCase11
TEST(AddDecimalsToDefaultAmount, PointPresentAndTwoDecimals)
{
	DoCreateWallet wallet("WalletTest",".12");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+0.12");
}

//TestCase12
TEST(AddDecimalsToDefaultAmount, PointPresentAndOneDecimals)
{
	DoCreateWallet wallet("WalletTest",".1");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	ASSERT_EQ(returnAmount, "+0.10");
}*/