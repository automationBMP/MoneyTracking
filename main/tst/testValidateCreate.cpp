
#include "gtest/gtest.h"
#include "C:/learn/MoneyTracking/main/inc/ValidateCreate.h"

// tests if the a file exists with relative path
TEST(FileExists, FileRelativePath)
{
	ValidateCreate validate("testValidateCreate.cpp");
	EXPECT_TRUE(validate.WalletExists());
	
	ValidateCreate validate2("missingFile.cpp");
	EXPECT_FALSE(validate2.WalletExists());
}

// tests if the a file exists with absolute path
TEST(FileExists, FileAbsolutePath)
{
	ValidateCreate validate("validPath/validFile");
	EXPECT_TRUE(validate.WalletExists());
	
	ValidateCreate validate2("validpath/missingFile");
	EXPECT_TRUE(validate2.WalletExists());
	
	ValidateCreate validate3("invalidPath");
	EXPECT_TRUE(validate3.WalletExists());
}