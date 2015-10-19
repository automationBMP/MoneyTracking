#include "gtest/gtest.h" 

#include "PrintError.h"
#include "Types.h"
#include "DoCreateWallet.h"


//Testing the removal of the zeros at the start of the number
//RemoveStartingZeroes tests

//with sign testcases
//TestCase1
TEST(RemoveStartingZeroes,TestCase1_Signed)
{
	DoCreateWallet wallet("WalletTestName","+000.1");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"+0.1");
}
//TestCase2
TEST(RemoveStartingZeroes,TestCase2_Signed)
{
	DoCreateWallet wallet("WalletTestName","+009.0");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"+9.0");
}
//TestCase3
TEST(RemoveStartingZeroes,TestCase3_Signed)
{
	DoCreateWallet wallet("WalletTestName","-000");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"0");
}

//without sign
//TestCase1
TEST(RemoveStartingZeroes,TestCase1_Unsigned)
{
	DoCreateWallet wallet("WalletTestName","000.1");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"+0.1");
}
//TestCase2
TEST(RemoveStartingZeroes,TestCase2_Unsigned)
{
	DoCreateWallet wallet("WalletTestName","009.0");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"+9.0");
}
//TestCase3
TEST(RemoveStartingZeroes,TestCase3_Unsigned)
{
	DoCreateWallet wallet("WalletTestName","000");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"0");
}
