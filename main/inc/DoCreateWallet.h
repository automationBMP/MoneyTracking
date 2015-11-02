/*
	Author: Miau
	
	This file contains the interface for creating a new wallet.
	
	The class will create a wallet with the given amount of currency
	
*/

#ifndef DOCREATEWALLET_H
#define DOCREATEWALLET_H

#include <string>
#include "PrintError.h"
#include "Types.h"

class DoCreateWallet
{
private :
	// the name of the wallet
	 std::string walletName_m;
	// the default amount to be added to the wallet
	 std::string defaultAmount_m;
public :
	//constructor
	DoCreateWallet(std::string walletName,  std::string defaultAmount);
	// creating the wallet file and adding the default amount
	Error_E CreateWalletFile();
	Error_E AddLineInWalletFile(std::string &amount , std::string &ArgNr2, std::string &category, std::string &wallet);
	//adding 2 decimals if needed
	std::string AddDecimalsToDefaultAmount();
	//removes any extra zero from the start of the number
	std::string RemoveStartingZeroes();
};
#endif