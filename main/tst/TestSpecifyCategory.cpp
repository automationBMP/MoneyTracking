//Author ANdreeaIoanaStan,Tudor Chibulcutean v0.2

#include "gtest/gtest.h"
#include "ReadConfig.h"
#include "string"
#include <fstream>
#include "MainFunctions.h"
#include <ctime>


std::string readLastLine()
{
	std::string fileName;
	fileName = "mywallet";
	std::ifstream file(fileName.c_str());
	std::string lastLine;
	std::string line;
	if(file.is_open())
	{
		while(getline(file,line))
		{
			bool isEmpty = true;
			for(unsigned int i = 0; i< line.size(); i++)
			{
				char ch = line[i];
				isEmpty = isEmpty && isspace(ch);
			}
			if(!isEmpty)
			{
	
			lastLine = line; 
			}
		}
				
		file.close();
	}
	return lastLine;
}   

//Test 1
TEST(SpecifyCategory, IncomeCCategoryAmount)
{
	std::ofstream ifs("mywallet");
	char* argumente[5]= {(char*)"moneytracker", (char*)"income", (char*)"--category", (char*)"category1", (char*)"300"};
	ImplementIncomeSpend(5, argumente);
	time_t currentTime = time(NULL);
	std::stringstream ss;
    ss << currentTime;
    std::string currentTimeString = ss.str();
	std::string expectedLine = currentTimeString + ";" +
										   "+" + ";" +
										   "300.00" + ";" + 
										   "category1" + ";" +
										   "RON";
	std::string currentLine = readLastLine();
	EXPECT_EQ(expectedLine, currentLine);

}

//Test 2
TEST(SpecifyCategory, IncomeCategoryCategoryAmount)
{
	char* argumente[5]= {(char*)"moneytracker", (char*)"income", (char*)"--category", (char*)"category2", (char*)"300"};
	ImplementIncomeSpend(5, argumente);
	time_t currentTime = time(NULL);
	std::stringstream ss;
    ss << currentTime;
    std::string currentTimeString = ss.str();
	std::string expectedLine = currentTimeString + ";" +
										   "+" + ";" +
										   "300.00" + ";" + 
										   "category2" + ";" +
										   "RON";
	std::string currentLine = readLastLine();
	EXPECT_EQ(expectedLine, currentLine);

} 

//Test 3
TEST(SpecifyCategory, IncomeCategoryCategoryAfterAmount)
{
	char* argumente[5]= {(char*)"moneytracker",(char*) "income", (char*)"233", (char*)"--category", (char*)"category3"};
	ImplementIncomeSpend(5, argumente);
	time_t currentTime = time(NULL);
	std::stringstream ss;
    ss << currentTime;
    std::string currentTimeString = ss.str();
	std::string expectedLine = currentTimeString + ";" +
										   "+" + ";" +
										   "233.00" + ";" + 
										   "category3" + ";" +
										   "RON";
	std::string currentLine = readLastLine();
	EXPECT_EQ(expectedLine, currentLine);

}  

//Test 4
TEST(SpecifyCategory, SpendCategoryCategoryAfterAmount)
{
	char* argumente[5]= {(char*)"moneytracker",(char*) "spend", (char*)"243", (char*)"--category", (char*)"category4"};
	ImplementIncomeSpend(5, argumente);
	time_t currentTime = time(NULL);
	std::stringstream ss;
    ss << currentTime;
    std::string currentTimeString = ss.str();
	std::string expectedLine = currentTimeString + ";" +
										   "-" + ";" +
										   "243.00" + ";" + 
										   "category4" + ";" +
										   "RON";
	std::string currentLine = readLastLine();
	EXPECT_EQ(expectedLine, currentLine);
}  

//Test 5
TEST(SpecifyCategory, SpendCCategoryAmount)
{
	char* argumente[5]= {(char*)"moneytracker", (char*)"spend", (char*)"--category", (char*)"category5", (char*)"300"};
	ImplementIncomeSpend(5, argumente);
	time_t currentTime = time(NULL);
	std::stringstream ss;
    ss << currentTime;
    std::string currentTimeString = ss.str();
	std::string expectedLine = currentTimeString + ";" +
										   "-" + ";" +
										   "300.00" + ";" + 
										   "category5" + ";" +
										   "RON";
	std::string currentLine = readLastLine();
	EXPECT_EQ(expectedLine, currentLine);
}