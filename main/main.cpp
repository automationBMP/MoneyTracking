/*
	Author: Andrei Martinescu
	
	This file contains main implementation for MoneyTracking application.
		
*/

#include <iostream> 
#include <string>
#include "MainFunctions.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2) 
	{
		cout << "error: No command specified." << endl;
	}
	else 
	{
		CommandInterpreter(argc, argv);
	}
	
return 0; 
}