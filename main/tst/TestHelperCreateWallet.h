/*
	Author: AndreeaIoanaStan
	
	This file contains helper functions used for testing if a new wallet is 
	created 
	
*/

#ifndef TESTHELPERCREATEWALLET_H
#define TESTHELPERCREATEWALLET_H

#include <fstream>
#include <string>

#include "C:\learn\MoneyTracking\main\inc\DoCreateWallet.h"


using namespace std;

//calls DoCreateWallet method from DoCreateWallet class
void HelperCreateWallet(const string walletName, const string amount = "+00.00")
{
	WalletEntity newWallet;
	newWallet.createWallet(walletName, amount);
}

//helper function for reading from the file created and return the content
string ReadWallet(const string walletName)
{
	
	ifstream wallet(walletName.c_str());
	
	string walletContent;
	
	//read from the given file
	getline(wallet,walletContent);
	
	return walletContent;
}

//helper function for checking if the file has been created
bool WalletCreated(const string walletName)
{
	bool isCreated = false;
	ifstream wallet(walletName.c_str());
	
	if(wallet.good())
	{
		wallet.close();
		isCreated = true;
	}
	else 
	{
		isCreated = false;
	}
	
	return isCreated;
}

#endif