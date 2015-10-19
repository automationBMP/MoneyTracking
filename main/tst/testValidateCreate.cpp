
#include "gtest/gtest.h"
#include "ValidateCreate.h"

// tests if the a file exists with relative path
TEST(FileExists, FileRelativePath)
{
	ValidateCreate validate("moneytracker.exe");
	EXPECT_TRUE(validate.WalletExists());
	
	ValidateCreate validate2("missingFile.cpp");
	EXPECT_FALSE(validate2.WalletExists());
}

// tests if the a file exists with absolute path
TEST(FileExists, FileAbsolutePath)
{
	ValidateCreate validate("main\\tst\\TestValidateCreate.cpp");
	EXPECT_TRUE(validate.WalletExists());
	
	ValidateCreate validate2("main\\tst\\missingFile");
	EXPECT_FALSE(validate2.WalletExists());
	
	ValidateCreate validate3("main\\tst\\src\\TestValidateCreate.cpp");
	EXPECT_FALSE(validate3.WalletExists());
}
