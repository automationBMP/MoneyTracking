/*
	Author: Miau
	
	This file contains the implementation for the PrintError class
	
	It stores and prints any error encountered int the application
	
*/

#include "PrintError.h"
#include "Types.h"
#include <iostream>
		
void PrintError::Print(Error_E error, 
									std::string const &walletName_m,
									std::string const &defaultAmount_m)
{
	switch (error)
	{
		case WRITE_TO_FILE:
			std::cout 	<<"error while writing " 
						<< defaultAmount_m 
						<< " to wallet "
						<< walletName_m
						<< "\n";
		break;
		case WALLET_ALREADY_EXISTS:
			std::cout 	<<"error: wallet "
						<< walletName_m
						<< " already exists!"	
						<< "\n";
		break;
		case CREATE_NAME_MISSING:
			std::cout	<<"error: at least filename"
						<< " should be specified."
						<< "\n";
		break;			
		case CREATE_INITIAL_AMMOUNT_INVALID:
			std::cout 	<<"error: "
						<< defaultAmount_m 
						<< " is not a valid initial ammount."
						<< "\n"
						<<"Creating " 
						<< walletName_m
						<< " aborted."
						<< "\n";
		break;
		case PATH_DOES_NOT_EXIST:
			std::cout 	<<"error : The given path doesn't exist"
						<< "\n";
		break;
		case CREATE_WALLET_MESSAGE:
			std::cout 	<< walletName_m 
						<< " created with the initial amount of "
						<< defaultAmount_m
						<< " RON"
						<< "\n";
		break;				
		case AMOUNT_NOT_POSITIVE:
			std::cout	<< "error: "
						<< walletName_m
						<< " should be higher than 0"
						<< ".\n";
		break;
		case NO_DEFAULT_WALLET:
			std::cout	<< "error: no default wallet "
						<< "configured in 'moneytracker.config'"
						<< "\n";
		break;
		case COULD_NOT_OPEN_CONFIG:
			std::cout	<< "error: could not open configuration "
					    << "'moneytracker.config'"
						<< "\n";
		break;
		case SHOULD_BE_POSITIVE:
			std::cout	<< "error: parameter for 'income' "
						<< "should be a positive number"
						<< "\n";
		break;
		case NO_AMOUNT_SPECIFIED_FOR_INCOME:
			std::cout	<< "error: no ammount specified for 'income'."
						<< "\n";
		break;
		case NO_AMOUNT_SPECIFIED_FOR_SPEND:
			std::cout	<< "error: no ammount specified for 'spend'."
						<< "\n";
		break;
		case COULD_NOT_OPEN_PATH:
			std::cout	<< "error: could not open "
						<< "'"
						<< walletName_m
						<< "'"
						<< " to register transaction"
						<< "\n";
		break;
		case ALL_GOOD:
			std::cout	<< "";
		
		break;
	}
}
