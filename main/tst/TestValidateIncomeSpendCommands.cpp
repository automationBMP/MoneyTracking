/*
	Author: Andrei Martinescu
	
	This file contains tests for function ValidateIncomeSpendCommands.
		
*/

#include "gtest/gtest.h"
#include "MainFunctions.h"
#include <string>

// Testing case income/spend with one parameter
TEST(ValidateIncomeSpendCommands, TestCase1_IncomeOneParameter)
{
	char * arguments [3] = {(char*)"moneytracker", (char*)"income", (char*)"200"};
	std::string *actual = ValidateIncomeSpendCommands(3,arguments);
	std::string *expected = new std::string [1];
	*expected = "200";
	EXPECT_EQ(*expected,*actual);
}
TEST(ValidateIncomeSpendCommands, TestCase2_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", (char*)"10.50", (char*)"-c", (char*)"food"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "10.50";
	expected[1] = "-c";
	expected[2] = "food";
	EXPECT_EQ(expected[0],actual[0]);
	EXPECT_EQ(expected[1],actual[1]);
	EXPECT_EQ(expected[2],actual[2]);
	
}

TEST(ValidateIncomeSpendCommands, TestCase3_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", (char*)"10.50", (char*)"--category", (char*)"food"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "10.50";
	expected[1] = "--category";
	expected[2] = "food";
	EXPECT_EQ(expected[0],actual[0]);
	EXPECT_EQ(expected[1],actual[1]);
	EXPECT_EQ(expected[2],actual[2]);
}

 TEST(ValidateIncomeSpendCommands, TestCase4_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", (char*)"-c", (char*)"scholarship", (char*)"+20.00"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "-c";
	expected[1] = "scholarship";
	expected[2] = "+20.00";
	EXPECT_EQ(expected[2],actual[0]);
	EXPECT_EQ(expected[0],actual[1]);
	EXPECT_EQ(expected[1],actual[2]);
}

TEST(ValidateIncomeSpendCommands, TestCase5_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", (char*)"-w", (char*)"my2.wallet", (char*)"200"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "-w";
	expected[1] = "my2.wallet";
	expected[2] = "200";
	EXPECT_EQ(expected[2],actual[0]);
	EXPECT_EQ(expected[0],actual[1]);
	EXPECT_EQ(expected[1],actual[2]);
}

 TEST(ValidateIncomeSpendCommands, TestCase6_IncomeThreeParameters)
{
	char * arguments [5] = {(char*)"moneytracker", (char*)"income", (char*)"200", (char*)"--wallet", (char*)"my3.wallet"};
	std::string *actual = ValidateIncomeSpendCommands(5,arguments);
	std::string *expected = new std::string [3];
	expected[0] = "200";
	expected[1] = "--wallet";
	expected[2] = "my3.wallet";
	EXPECT_EQ(expected[0],actual[0]);
	EXPECT_EQ(expected[1],actual[1]);
	EXPECT_EQ(expected[2],actual[2]);
}

TEST(ValidateIncomeSpendCommands, TestCase7_IncomeFiveParameters)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", (char*)"999", (char*)"--category", (char*)"bonus", (char*)"-w", (char*)"my2.wallet"};
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

 TEST(ValidateIncomeSpendCommands, TestCase8_IncomeFiveParameters)
{
	char * arguments [7] = {(char*)"moneytracker", (char*)"income", (char*)"--wallet", (char*)"my2.wallet", (char*)"111", (char*)"--category", (char*)"bonus"};
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