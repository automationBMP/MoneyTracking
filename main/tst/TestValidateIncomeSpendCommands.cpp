/*
	Author: Andrei Martinescu
	
	This file contains tests for function ValidateIncomeSpendCommands.
		
*/

#include "gtest/gtest.h"
#include "MainFunctions.h"
#include <string>

//the function returns a string array with amount on first pozition if 
//command is valid else returns a "" string

// Testing case income/spend with one parameter
TEST(ValidateIncomeSpendCommands, TestCase1_IncomeOneParameter)
{
	char * arguments [3] = {(char*)"moneytracker", (char*)"income", 
	(char*)"200"};
	std::string *actual = ValidateIncomeSpendCommands(3,arguments);
	std::string *expected = new std::string [1];
	*expected = "200";
	EXPECT_EQ(*expected,*actual);
}

// testing valid with 3 parameters
TEST(ValidateIncomeSpendCommands, TestCase2_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", 
	(char*)"10.50", (char*)"-c", (char*)"food"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "10.50";
	expected[1] = "-c";
	expected[2] = "food";
	EXPECT_EQ(expected[0],actual[0]);
	EXPECT_EQ(expected[1],actual[1]);
	EXPECT_EQ(expected[2],actual[2]);
	
}

// testing valid with 3 parameters
TEST(ValidateIncomeSpendCommands, TestCase3_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", 
	(char*)"10.50", (char*)"--category", (char*)"food"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "10.50";
	expected[1] = "--category";
	expected[2] = "food";
	EXPECT_EQ(expected[0],actual[0]);
	EXPECT_EQ(expected[1],actual[1]);
	EXPECT_EQ(expected[2],actual[2]);
}


// testing valid with 3 parameters
TEST(ValidateIncomeSpendCommands, TestCase4_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", 
	(char*)"10.50", (char*)"-w", (char*)"wallet"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "10.50";
	expected[1] = "-w";
	expected[2] = "wallet";
	EXPECT_EQ(expected[0],actual[0]);
	EXPECT_EQ(expected[1],actual[1]);
	EXPECT_EQ(expected[2],actual[2]);
	
}

// testing valid with 3 parameters
TEST(ValidateIncomeSpendCommands, TestCase5_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", 
	(char*)"10.50", (char*)"--wallet", (char*)"wallet"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "10.50";
	expected[1] = "--wallet";
	expected[2] = "wallet";
	EXPECT_EQ(expected[0],actual[0]);
	EXPECT_EQ(expected[1],actual[1]);
	EXPECT_EQ(expected[2],actual[2]);
}

// testing valid with 3 parameters
 TEST(ValidateIncomeSpendCommands, TestCase6_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", 
	(char*)"-c", (char*)"scholarship", (char*)"+20.00"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "-c";
	expected[1] = "scholarship";
	expected[2] = "+20.00";
	EXPECT_EQ(expected[2],actual[0]);
	EXPECT_EQ(expected[0],actual[1]);
	EXPECT_EQ(expected[1],actual[2]);
}

// testing valid with 3 parameters
 TEST(ValidateIncomeSpendCommands, TestCase7_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", 
	(char*)"-w", (char*)"wallet", (char*)"+20.00"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "-w";
	expected[1] = "wallet";
	expected[2] = "+20.00";
	EXPECT_EQ(expected[2],actual[0]);
	EXPECT_EQ(expected[0],actual[1]);
	EXPECT_EQ(expected[1],actual[2]);
}
// testing valid with 3 parameters
 TEST(ValidateIncomeSpendCommands, TestCase8_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", 
	(char*)"--category", (char*)"scholarship", (char*)"+20.00"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "--category";
	expected[1] = "scholarship";
	expected[2] = "+20.00";
	EXPECT_EQ(expected[2],actual[0]);
	EXPECT_EQ(expected[0],actual[1]);
	EXPECT_EQ(expected[1],actual[2]);
}
// testing valid with 3 parameters
 TEST(ValidateIncomeSpendCommands, TestCase9_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", 
	(char*)"--wallet", (char*)"scholarship", (char*)"+20.00"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "--wallet";
	expected[1] = "scholarship";
	expected[2] = "+20.00";
	EXPECT_EQ(expected[2],actual[0]);
	EXPECT_EQ(expected[0],actual[1]);
	EXPECT_EQ(expected[1],actual[2]);
}

//test 5 parameters valid
TEST(ValidateIncomeSpendCommands, TestCase10_IncomeFiveParameters)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"999", (char*)"--category", (char*)"bonus", 
	(char*)"-w", (char*)"my2.wallet"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "999";
	expected[1] = "--category";
	expected[2] = "bonus";
	expected[3] = "-w";
	expected[4] = "my2.wallet";
	EXPECT_EQ(expected[0],actual[0]);
	EXPECT_EQ(expected[1],actual[1]);
	EXPECT_EQ(expected[2],actual[2]);
	EXPECT_EQ(expected[3],actual[3]);
	EXPECT_EQ(expected[4],actual[4]);
}
//test 5 parameters valid
 TEST(ValidateIncomeSpendCommands, TestCase11_IncomeFiveParameters)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"--wallet", (char*)"my2.wallet", (char*)"111", 
	(char*)"--category", (char*)"bonus"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "--wallet";
	expected[1] = "my2.wallet";
	expected[2] = "111";
	expected[3] = "--category";
	expected[4] = "bonus";
	EXPECT_EQ(expected[2],actual[0]);
	EXPECT_EQ(expected[0],actual[1]);
	EXPECT_EQ(expected[1],actual[2]);
	EXPECT_EQ(expected[3],actual[3]);
	EXPECT_EQ(expected[4],actual[4]);
} 
//test 5 parameters valid
 TEST(ValidateIncomeSpendCommands, TestCase12_IncomeFiveParameters)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"--wallet", (char*)"my2.wallet", (char*)"111", 
	(char*)"--category", (char*)"bonus"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "--wallet";
	expected[1] = "my2.wallet";
	expected[2] = "111";
	expected[3] = "--category";
	expected[4] = "bonus";
	EXPECT_NE(expected[0],actual[0]);
	EXPECT_NE(expected[1],actual[1]);
	EXPECT_NE(expected[2],actual[2]);
	EXPECT_EQ(expected[3],actual[3]);
	EXPECT_EQ(expected[4],actual[4]);
} 
//test 5 parameters valid
 TEST(ValidateIncomeSpendCommands, TestCase13_IncomeFiveParameters)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"--wallet", (char*)"my2.wallet",  (char*)"--category", 
	(char*)"bonus", (char*)"111"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "--wallet";
	expected[1] = "my2.wallet";
	expected[2] = "--category";
	expected[3] = "bonus";
	expected[4] = "111";
	EXPECT_EQ(expected[4],actual[0]);
	EXPECT_EQ(expected[0],actual[1]);
	EXPECT_EQ(expected[1],actual[2]);
	EXPECT_EQ(expected[2],actual[3]);
	EXPECT_EQ(expected[3],actual[4]);
}  

//test 5 parameters valid
 TEST(ValidateIncomeSpendCommands, TestCas14_IncomeFiveParameters)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"--wallet", (char*)"my2.wallet",  (char*)"--category", 
	(char*)"bonus", (char*)"111"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "--wallet";
	expected[1] = "my2.wallet";
	expected[2] = "--category";
	expected[3] = "bonus";
	expected[4] = "111";
	EXPECT_NE(expected[0],actual[0]);
	EXPECT_NE(expected[1],actual[1]);
	EXPECT_NE(expected[2],actual[2]);
	EXPECT_NE(expected[3],actual[3]);
	EXPECT_NE(expected[4],actual[4]);
}
//test 5 parameters notvalid
 TEST(ValidateIncomeSpendCommands, TestCas15_IncomeFiveParametersNotValid)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"--wallet", (char*)"my2.wallet",  (char*)"--category", 
	(char*)"bonus", (char*)"asdfgh"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "--wallet";
	expected[1] = "my2.wallet";
	expected[2] = "--category";
	expected[3] = "bonus";
	expected[4] = "asdfgh";

	EXPECT_EQ("",*actual);
}
//test 5 parameters notvalid
 TEST(ValidateIncomeSpendCommands, TestCas16_IncomeFiveParametersNotValid)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"asdfgh" ,(char*)"--wallet", (char*)"my2.wallet",  
	(char*)"--category", (char*)"bonus"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "asdfgh";
	expected[1] = "--wallet";
	expected[2] = "my2.wallet";
	expected[3] = "--category";
	expected[4] = "bonus";
	EXPECT_NE(expected[0],actual[0]);
	EXPECT_NE(expected[1],actual[1]);
	EXPECT_NE(expected[2],actual[2]);
	EXPECT_NE(expected[3],actual[3]);
	EXPECT_NE(expected[4],actual[4]);

	EXPECT_EQ("",*actual);
}
//test 5 parameters notvalid
 TEST(ValidateIncomeSpendCommands, TestCas17_IncomeFiveParametersNotValid)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"asdfgh" ,(char*)"qwerty", (char*)"my2.wallet",  
	(char*)"--category", (char*)"bonus"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "asdfgh";
	expected[1] = "qwerty";
	expected[2] = "my2.wallet";
	expected[3] = "--category";
	expected[4] = "bonus";
	
	EXPECT_NE(expected[0],actual[0]);
	EXPECT_NE(expected[1],actual[1]);
	EXPECT_NE(expected[2],actual[2]);
	EXPECT_NE(expected[3],actual[3]);
	EXPECT_NE(expected[4],actual[4]);

	EXPECT_EQ("",*actual);
}
//test 5 parameters notvalid
 TEST(ValidateIncomeSpendCommands, TestCas18_IncomeFiveParametersNotValid)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"asdfgh" ,(char*)"qwerty", (char*)"123",  (char*)"--category", 
	(char*)"bonus"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "asdfgh";
	expected[1] = "qwerty";
	expected[2] = "123";
	expected[3] = "--category";
	expected[4] = "bonus";
	
	EXPECT_NE(expected[0],actual[0]);
	EXPECT_NE(expected[1],actual[1]);
	EXPECT_NE(expected[2],actual[2]);
	EXPECT_NE(expected[3],actual[3]);
	EXPECT_NE(expected[4],actual[4]);

	EXPECT_EQ("",*actual);
}
//test 5 parameters notvalid
 TEST(ValidateIncomeSpendCommands, TestCas19_IncomeFiveParametersNotValid)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"asdfgh" ,(char*)"qwerty", (char*)"zxcv",  (char*)"--category", 
	(char*)"bonus"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "asdfgh";
	expected[1] = "qwerty";
	expected[2] = "zxcv";
	expected[3] = "--category";
	expected[4] = "bonus";
	
	EXPECT_NE(expected[0],actual[0]);
	EXPECT_NE(expected[1],actual[1]);
	EXPECT_NE(expected[2],actual[2]);
	EXPECT_NE(expected[3],actual[3]);
	EXPECT_NE(expected[4],actual[4]);

	EXPECT_EQ("",*actual);
}
//test 5 parameters notvalid
 TEST(ValidateIncomeSpendCommands, TestCas20_IncomeFiveParametersNotValid)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"asdfgh" ,(char*)"qwerty", (char*)"zxcv",  (char*)"tyuiop", 
	(char*)"bonus"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "asdfgh";
	expected[1] = "qwerty";
	expected[2] = "zxcv";
	expected[3] = "tyuiop";
	expected[4] = "bonus";
	
	EXPECT_NE(expected[0],actual[0]);
	EXPECT_NE(expected[1],actual[1]);
	EXPECT_NE(expected[2],actual[2]);
	EXPECT_NE(expected[3],actual[3]);
	EXPECT_NE(expected[4],actual[4]);

	EXPECT_EQ("",*actual);
}
//test 5 parameters notvalid
 TEST(ValidateIncomeSpendCommands, TestCas21_IncomeFiveParametersNotValid)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", 
	(char*)"asdfgh" ,(char*)"qwerty", (char*)"zxcv",  (char*)"tyuiop", 
	(char*)"bnm"};
	std::string *actual = ValidateIncomeSpendCommands(7,arguments);
	std::string *expected = new std::string [5];
	expected[0] = "asdfgh";
	expected[1] = "qwerty";
	expected[2] = "zxcv";
	expected[3] = "tyuiop";
	expected[4] = "bnm";
	
	EXPECT_NE(expected[0],actual[0]);
	EXPECT_NE(expected[1],actual[1]);
	EXPECT_NE(expected[2],actual[2]);
	EXPECT_NE(expected[3],actual[3]);
	EXPECT_NE(expected[4],actual[4]);

	EXPECT_EQ("",*actual);
}

