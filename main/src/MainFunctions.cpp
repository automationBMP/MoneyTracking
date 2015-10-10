#include "C:\learn\MoneyTracking\main\inc\MainFunctions.h"
#include <cstring>
#include <iostream>

using namespace std ;
bool checkArgc(int argc)
{
	bool flag = true ;
	
		if (argc <= 2) 
		{
			cout << "error: at least filename should be specified. ";
			flag =false;
		}
	return flag;	
}

string convertPath(string givenPath)
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

string convertPathToOriginal(string givenPath)
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

/* function return fileName from path
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

