/*
	Author: Miau
	
	This file contains the implementation for the PrintError class
	
	It stores and prints any error encountered int the application
	
*/

#ifndef PRINTERROR_H
#define PRINTERROR_H

#include <string>
#include "Types.h"


class PrintError
{
public :
	//printing the desired error message
	static void Print(Error_E error, 
					std::string walletName_m,
					std::string defaultAmount_m);
};




#endif