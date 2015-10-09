/*
	Author: Miau
	
	This file contains the implementation for the PrintError class
	
	It stores and prints any error encountered int the application
	
*/

#include "..\inc\PrintError.h"
#include "..\inc\Types.h"

#include <iostream>
		
void PrintError::Print(Error_E error, 
									std::string walletName_m,
									std::string defaultAmount_m)
{
	switch (error)
	{
		case WRITE_TO_FILE:
			std::cout 	<< "\n error while writing " 
						<< defaultAmount_m 
						<< " to wallet "
						<< walletName_m;
		break;
		case WALLET_ALREADY_EXISTS:
			std::cout 	<< "\n error: wallet "
						<< walletName_m
						<< " already exists";	
		break;
		case CREATE_NAME_MISSING:
			std::cout	<< "\n error: at least filename"
						<< " should be specified.";
		break;			
		case CREATE_INITIAL_AMMOUNT_INVALID:
			std::cout 	<< "\n error: "
						<< defaultAmount_m 
						<< " is not a valid initial ammount."
						<< "\n Creating " 
						<< walletName_m
						<< " aborted.";
		break;
		case PATH_DOES_NOT_EXIST:
			std::cout 	<< "\n error : The given path doesn't exist";
		break;
	}
}
