/*
	Author: Andrei Martinescu
	
	This file contains header for main functions .
		
*/

#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H
#include <string>


// validate nr of arguments return true if we have enough arguments
bool CheckArgcNumbers(int const argc,std::string const &argument);

// convert path  Ex: C:\learn in C:/learn for validating 
// returns the convert path
std::string ConvertPath(std::string &givenPath);

// reconvert path to original
// returns the original path
std::string ConvertPathToOriginal(std::string &givenPath);

//function read config file
// returns all content of file
std::string ReturnFileasString(const std::string &filename);

//function validate commands for income/spend
std::string* ValidateIncomeSpendCommands(int argc, char* argv[]);

//function command interpreter of command line arguments
void CommandInterpreter(int arc, char *argv[]);

//implement for 3 arguments Create
void ImplementCreateThreeArguments(int arc,char *argv[]);

//implement for 4 arguments Create
void ImplementCreateFourArguments(int arc,char *argv[]);

//implement Create , apeals functions implement for 3 and 4 argumnents functions
void ImpelmentCreate(int arc, char *argv[]);

//implement balance 
void ImpelmentBalance(int arc, char *argv[]);

//Implement income Spend function
void ImplementIncomeSpend(int arc, char *argv[]);

//Implement Config function
void ImplementConfig(int arc, char *argv[]);

//Heplper function print error if negative income
void PrintIncomeSpendNegative(std::string, std::string);


void PrintNoAmountSpecified(std::string);

//print in  wallet
void PrintInFileIfWalletFound(std::string, std::string, 
						std:: string, std:: string);
#endif