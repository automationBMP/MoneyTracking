/*
	Author: Andrei Martinescu
	
	This file contains tests for main function ConvertPath.
		
*/

#include "gtest/gtest.h" 
#include "MainFunctions.h"
#include <cstring>

// test if the ConvertPath function returns the corect convert path
// the ConvertPath function actions only for \ operator

/* tests for corect convert path expected , original path contains \
case \ is not escape
TestCase1
*/
TEST(ConvertPath,TestCase1_CorectPathConversion)
{	
	std::string path = "C:\\learn";
	std::string actual = ConvertPath(path);
	std::string expected = "C:/learn";
	ASSERT_EQ(expected,actual);
}
//TestCase2
TEST(ConvertPath,TestCase2_CorectPathConversion)
{	
	std::string path = "C:\\learn\\some.wallet";
	std::string actual = ConvertPath(path);
	std::string expected = "C:/learn/some.wallet";
	ASSERT_EQ(expected,actual);
}
//TestCase3
TEST(ConvertPath,TestCase3_CorectPathConversion)
{	
	std::string path = "C:\\\\";
	std::string actual = ConvertPath(path);
	std::string expected = "C://";
	ASSERT_EQ(expected,actual);
}

/* tests for corect convert path expected , original path contains \
case with one \ in path
TestCase1
*/
TEST(ConvertPath,TestCase1_CorectPathConversionEscape)
{	
	std::string path = "C:\learn";
	std::string actual = ConvertPath(path);
	std::string expected = "C:learn";
	ASSERT_EQ(expected,actual);
}
//TestCase2
TEST(ConvertPath,TestCase2_CorectPathConversionEscape)
{	
	std::string path = "C:\learn\some.wallet";
	std::string actual = ConvertPath(path);
	std::string expected = "C:learnsome.wallet";
	ASSERT_EQ(expected,actual);
}
//TestCase3
TEST(ConvertPath,TestCase3_CorectPathConversionEscape)
{	
	std::string path = "C:\\";
	std::string actual = ConvertPath(path);
	std::string expected = "C:/";
	ASSERT_EQ(expected,actual);
}

/* tests for corect convert path expected , original path doesn't contains \
TestCase1
*/
TEST(ConvertPath,TestCase1_CorectPathConversion1)
{	
	std::string path = "my.wallet";
	std::string actual = ConvertPath(path);
	std::string expected = "my.wallet";
	ASSERT_EQ(expected,actual);
}



