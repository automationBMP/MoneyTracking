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
	expected[0] = "200";
	EXPECT_EQ(expected,actual);
}