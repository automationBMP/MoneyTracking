/*
	Author: Andrei Martinescu
	
	This file contains tests for main function CheckArgcNumbers.
		
*/

#include "gtest/gtest.h" 
#include "MainFunctions.h"
#include <string>
std::string const create = "create";
std::string const income = "income";
std::string const spend = "spend";
// test if we have enough arguments 

// not enough arguments tests
//TestCase1 // "create"
TEST(CheckArgcNumbers,TestCase1_NotEnoughArgcCreate)
{	
	bool actual = CheckArgcNumbers(0,create);
	bool expected = false;
	EXPECT_EQ(expected,actual);
}
//TestCase2
TEST(CheckArgcNumbers,TestCase2_NotEnoughArgcCreate)
{	
	bool actual = CheckArgcNumbers(1,create);
	bool expected = false;
	EXPECT_EQ(expected,actual);
}
//TestCase3
TEST(CheckArgcNumbers,TestCase3_NotEnoughArgcCreate)
{	
	bool actual = CheckArgcNumbers(2,create);
	bool expected = false;
	EXPECT_EQ(expected,actual);
}
//TestCase1 // "income"
TEST(CheckArgcNumbers,TestCase1_NotEnoughArgcIncome)
{
	bool actual = CheckArgcNumbers(0,income);
	bool expected = false;
	EXPECT_EQ(expected,actual);
}
//TestCase2
TEST(CheckArgcNumbers,TestCase2_NotEnoughArgcIncome)
{
	bool actual = CheckArgcNumbers(1,income);
	bool expected = false;
	EXPECT_EQ(expected,actual);
}
//TestCase3
TEST(CheckArgcNumbers,TestCase3_NotEnoughArgcIncome)
{
	bool actual = CheckArgcNumbers(2,income);
	bool expected = false;
	EXPECT_EQ(expected,actual);
}

//TestCase1 // "spend"
TEST(CheckArgcNumbers,TestCase1_NotEnoughArgcSpend)
{
	bool actual = CheckArgcNumbers(0,spend);
	bool expected = false;
	EXPECT_EQ(expected,actual);
}
//TestCase2
TEST(CheckArgcNumbers,TestCase2_NotEnoughArgcSpend)
{	
	bool actual = CheckArgcNumbers(1,spend);
	bool expected = false;
	EXPECT_EQ(expected,actual);
}
//TestCase3
TEST(CheckArgcNumbers,TestCase3_NotEnoughArgcSpend)
{
	bool actual = CheckArgcNumbers(2,spend);
	bool expected = false;
	EXPECT_EQ(expected,actual);
}


// enough arguments tests
//TestCase1 
TEST(CheckArgcNumbers,TestCase1_EnoughArgcCreate)
{
	bool actual = CheckArgcNumbers(3,create);
	bool expected = true;
	EXPECT_EQ(expected,actual);
}
//TestCase2
TEST(CheckArgcNumbers,TestCase1_EnoughArgcIncome)
{
	bool actual = CheckArgcNumbers(3,income);
	bool expected = true;
	EXPECT_EQ(expected,actual);
}
//TestCase3
TEST(CheckArgcNumbers,TestCase1_EnoughArgcSpend)
{
	bool actual = CheckArgcNumbers(3,spend);
	bool expected = true;
	EXPECT_EQ(expected,actual);
}
//TestCase4
TEST(CheckArgcNumbers,TestCase2_EnoughArgcCreate)
{	
	bool actual = CheckArgcNumbers(4,create);
	bool expected = true;
	EXPECT_EQ(expected,actual);
}
//TestCase5
TEST(CheckArgcNumbers,TestCase2_EnoughArgcIncome)
{	
	bool actual = CheckArgcNumbers(4,income);
	bool expected = true;
	EXPECT_EQ(expected,actual);
}
//TestCase6
TEST(CheckArgcNumbers,TestCase2_EnoughArgcSpend)
{
	bool actual = CheckArgcNumbers(4,spend);
	bool expected = true;
	EXPECT_EQ(expected,actual);
}