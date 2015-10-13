/*
	Author: Andrei Martinescu
	
	This file contains tests for methos IsValidNumber.
		
*/

#include "gtest/gtest.h" 
#include "PrintError.h"
#include "Types.h"
#include "ValidateCreate.h"

//Testing if the number is a valid number
//IsValidNumber tests

//with sign testcases
//TestCase1
TEST(IsValidNumber,TestCase1_Signed)
{
	ValidateCreate wallet("IsValidNumberTest","+1000");
	ASSERT_EQ(wallet.IsValidNumber(),true);
}
//TestCase2
TEST(IsValidNumber,TestCase2_Signed)
{
	ValidateCreate wallet("IsValidNumberTest","-1000");
	ASSERT_EQ(wallet.IsValidNumber(),true);
}
//TestCase3
TEST(IsValidNumber,TestCase3_Signed)
{
	ValidateCreate wallet("IsValidNumberTest","+00012.24");
	ASSERT_EQ(wallet.IsValidNumber(),true);
}
//TestCase4
TEST(IsValidNumber,TestCase4_Signed)
{
	ValidateCreate wallet("IsValidNumberTest","-00012.24");
	ASSERT_EQ(wallet.IsValidNumber(),true);
}
//TestCase5
TEST(IsValidNumber,TestCase5_Signed)
{
	ValidateCreate wallet("IsValidNumberTest","+00012,24");
	ASSERT_EQ(wallet.IsValidNumber(),false);
}
//TestCase6
TEST(IsValidNumber,TestCase6_Signed)
{
	ValidateCreate wallet("IsValidNumberTest","-00012,24");
	ASSERT_EQ(wallet.IsValidNumber(),false);
}
//TestCase7
TEST(IsValidNumber,TestCase7_Signed)
{
	ValidateCreate wallet("IsValidNumberTest","+22.125");
	ASSERT_EQ(wallet.IsValidNumber(),true);
}
//TestCase8
TEST(IsValidNumber,TestCase8_Signed)
{
	ValidateCreate wallet("IsValidNumberTest","-22.125");
	ASSERT_EQ(wallet.IsValidNumber(),true);
}
//TestCase9
TEST(IsValidNumber,TestCase9_Signed)
{
	ValidateCreate wallet("IsValidNumberTest","+22,125");
	ASSERT_EQ(wallet.IsValidNumber(),false);
}
//TestCase10
TEST(IsValidNumber,TestCase10_Signed)
{
	ValidateCreate wallet("IsValidNumberTest","-22,125");
	ASSERT_EQ(wallet.IsValidNumber(),false);
}

//without sign
//TestCase1
TEST(IsValidNumber,TestCase1_Unsigned)
{
	ValidateCreate wallet("IsValidNumberTest","1000");
	ASSERT_EQ(wallet.IsValidNumber(),true);
}
//TestCase2
TEST(IsValidNumber,TestCase2_Unsigned)
{
	ValidateCreate wallet("IsValidNumberTest","22.12");
	ASSERT_EQ(wallet.IsValidNumber(),true);
}
//TestCase3
TEST(IsValidNumber,TestCase3_Unsigned)
{
	ValidateCreate wallet("IsValidNumberTest","22.125");
	ASSERT_EQ(wallet.IsValidNumber(),true);
}
//TestCase4
TEST(IsValidNumber,TestCase4_Unsigned)
{
	ValidateCreate wallet("IsValidNumberTest","22,12");
	ASSERT_EQ(wallet.IsValidNumber(),false);
}
//TestCase5
TEST(IsValidNumber,TestCase5_Unsigned)
{
	ValidateCreate wallet("IsValidNumberTest","22,125");
	ASSERT_EQ(wallet.IsValidNumber(),false);
}

//test case not numbers 
//TestCase1
TEST(IsValidNumber,TestCase1_NotNumber)
{
	ValidateCreate wallet("IsValidNumberTest","number");
	ASSERT_EQ(wallet.IsValidNumber(),false);
}
