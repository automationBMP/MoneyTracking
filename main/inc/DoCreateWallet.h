/*
	Author: Miau
	
	This file contains the interface for creating a new wallet.
	
	The class will create a wallet with the given amount of currency
	
*/



#ifndef DOCREATEWALLET_H
#define DOCREATEWALLET_H

#include <string>


class DoCreateWallet
{
private :
	// the name of the wallet
	 std::string walletName_m;
	// the default amount to be added to the wallet
	 std::string defaultAmount_m;
public :
	//constructor
	DoCreateWallet( std::string walletName,  std::string defaultAmount);
	// creating the wallet file and adding the default amount
	void CreateWalletFile();
	//adding 2 decimals if needed
	void AddDecimalsToDefaultAmount();
	std::string RemoveStartingZeroes();
};



#endif