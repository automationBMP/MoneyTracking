/*
	Author: Andrei Martinescu
	
	This file contains tests for main function ConvertPathToOriginal.
		
*/

#include "gtest/gtest.h" 
#include "MainFunctions.h"
#include <cstring>

// test if the ConvertPathToOriginal function returns the corect convert path
// the ConvertPathToOriginal function actions only for / operator

// tests for corect convert path expected , original path contains /
//TestCase1
TEST(ConvertPathToOriginal,TestCase1_CorectPathConversion1)
{	
	std::string path = "C:/learn";
	std::string actual = ConvertPathToOriginal(path);
	std::string expected = "C:\\learn";
	ASSERT_EQ(expected,actual);
}
//TestCase2
TEST(ConvertPathToOriginal,TestCase2_CorectPathConversion1)
{	
	std::string path = "C:/learn/some.wallet";
	std::string actual = ConvertPathToOriginal(path);
	std::string expected = "C:\\learn\\some.wallet";
	ASSERT_EQ(expected,actual);
}

//TestCase3
TEST(ConvertPathToOriginal,TestCase3_CorectPathConversion1)
{	
	std::string path = "C://";
	std::string actual = ConvertPathToOriginal(path);
	std::string expected = "C:\\\\";
	ASSERT_EQ(expected,actual);
}

/* tests for corect convert path expected , original path contains \
case \ is escape
TestCase1
*/
TEST(ConvertPath,TestCase1_CorectPathConversionEscape1)
{	
	std::string path = "C:/learn";
	std::string actual = ConvertPath(path);
	std::string expected = "C:\learn";
	ASSERT_NE(expected,actual);
}
//TestCase2
TEST(ConvertPath,TestCase2_CorectPathConversionEscape1)
{	
	std::string path = "C:/learn/some.wallet";
	std::string actual = ConvertPath(path);
	std::string expected = "C:\learn\some.wallet";
	ASSERT_NE(expected,actual);
}
//TestCase3
TEST(ConvertPath,TestCase3_CorectPathConversionEscape1)
{	
	std::string path = "C://";
	std::string actual = ConvertPath(path);
	std::string expected = "C:\\";
	ASSERT_NE(expected,actual);
}

/* tests for corect convert path expected , original path doesn't contains
TestCase1 */
TEST(ConvertPathToOriginal,TestCase1_CorectPathConversion11)
{	
	std::string path = "my.wallet";
	std::string actual = ConvertPathToOriginal(path);
	std::string expected = "my.wallet";
	ASSERT_EQ(expected,actual);
}
