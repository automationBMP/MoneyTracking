// validate Create Wallet function

#ifndef VALIDATECREATE_H
#define VALIDATECREATE_H
#include <string>

// class that validates create wallet
class ValidateCreate
{
private:
	// declaration of wallet name and amount
	std::string walletName_m;
	std::string amount_m;
	ValidateCreate();

public:
	// constructor with no amount
	ValidateCreate(std::string walletName);
	
	// constructor with wallet name and amount
	ValidateCreate(std::string walletName, std::string amount);
	
	//function to verify if the wallet exists
	bool WalletExists();
	
	// function to verify if amount is validate
	bool IsValidNumber();
};

#endif