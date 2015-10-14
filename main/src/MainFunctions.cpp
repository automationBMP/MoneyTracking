/*
	Author: Andrei Martinescu
	
	This file contains implementation for main functions .
		
*/

#include "MainFunctions.h"
#include <cstring>
#include <iostream>

using namespace std ;

// function for testing if we have enough arguments
bool CheckArgcNumbers(int argc)
{
	bool flag = true ;
	
		if (argc <= 2) 
		{
			cout << "error: at least filename should be specified.\n";
			flag =false;
		}
	return flag;	
}

//function for converting path  Ex: C:\learn in C:/learn for validating
string ConvertPath(string givenPath)
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
string ConvertPathToOriginal(string givenPath)
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

/* function return fileName from path for future feature's
string FileName(string givenPath)
{  string fileName; 

	for(unsigned int i = givenPath.length(); i >0; i--)
	{
		if(givenPath[i] == '/')
		{	
			for (unsigned int j = i+1; j < givenPath.length(); j++)
			{	
			fileName+=givenPath[j];
			}
			break;
			//cout << fileName;
		}
	}
	return fileName;
	
//return givenPath;	
	
}*/

