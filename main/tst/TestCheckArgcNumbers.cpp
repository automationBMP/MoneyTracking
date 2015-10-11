/*
	Author: Andrei Martinescu
	
	This file contains tests for main function CheckArgcNumbers.
		
*/

#include "gtest/gtest.h" 
#include "C:\learn\MoneyTracking\main\inc\MainFunctions.h"

// test if we have enough arguments 

// not enough arguments tests
//TestCase1
TEST(CheckArgcNumbers,TestCase1_NotEnoughArgc)
{	
	bool actual = CheckArgcNumbers(0);
	bool expected = false;
	ASSERT_EQ(expected,actual);
}
//TestCase2
TEST(CheckArgcNumbers,TestCase2_NotEnoughArgc)
{	
	bool actual = CheckArgcNumbers(1);
	bool expected = false;
	ASSERT_EQ(expected,actual);
}
//TestCase3
TEST(CheckArgcNumbers,TestCase3_NotEnoughArgc)
{	
	bool actual = CheckArgcNumbers(2);
	bool expected = false;
	ASSERT_EQ(expected,actual);
}

// enough arguments tests
//TestCase1
TEST(CheckArgcNumbers,TestCase1_EnoughArgc)
{	
	bool actual = CheckArgcNumbers(3);
	bool expected = true;
	ASSERT_EQ(expected,actual);
}
//TestCase2
TEST(CheckArgcNumbers,TestCase2_EnoughArgc)
{	
	bool actual = CheckArgcNumbers(4);
	bool expected = true;
	ASSERT_EQ(expected,actual);
}
//TestCase3
TEST(CheckArgcNumbers,TestCase3_EnoughArgc)
{	
	bool actual = CheckArgcNumbers(5);
	bool expected = true;
	ASSERT_EQ(expected,actual);
}

//false test
TEST(CheckArgcNumbers,TestCase1_FalseNotEnoughArgc)
{	
	bool actual = CheckArgcNumbers(0);
	bool expected = true;
	ASSERT_EQ(expected,actual);
}





