/*
	Author: Andrei Martinescu
	
	This file contains implementation for main functions .
		
*/

#include "MainFunctions.h"
#include <string>
#include <iostream>
#include "Types.h"
#include "PrintError.h"
#include <fstream>

using namespace std ;

// function for testing if we have enough arguments
bool CheckArgcNumbers(int const argc ,string const &argument)
{
	bool flag = true ;
	if ((argument == "create")&&(argc<=2))
		{
			//cout << "error: at least filename should be specified.\n";
			PrintError::Print(CREATE_NAME_MISSING,
											"create", "+00.00");
			flag =false;
		}
	else if ((argument == "income")&&(argc<=2))
		{
			//cout << "error: no ammount specified for 'income'.\n";
			PrintError::Print(NO_AMOUNT_SPECIFIED,
											"income", "+00.00");
			flag =false;		
		}
	else if ((argument == "spend")&&(argc<=2))
		{
			//cout << "error: no ammount specified for 'spend'.\n";
			PrintError::Print(NO_AMOUNT_SPECIFIED,
											"spend", "+00.00");
			flag =false;		
		}
	return flag;	
}

//function for converting path  Ex: C:\learn in C:/learn for validating
string ConvertPath(string &givenPath)
{
	for(unsigned int i = 0; i < givenPath.length(); i++)
	{
		if(givenPath[i] == '\\')
		{
			givenPath[i] = '/';
		}
	}
	
return givenPath;	
} 

//function for converting path to original
string ConvertPathToOriginal(string &givenPath)
{
	for(unsigned int i = 0; i < givenPath.length(); i++)
	{
		if(givenPath[i] == '/')
		{
			givenPath[i] = '\\';
		}
	}
return givenPath;	
} 
string ReturnFileasString()
{
	//read moneytracker.config file
	std::ifstream ifs("moneytracker.config");
	
	//the content of moneytracker.config is transfered to string content
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	return content;
}