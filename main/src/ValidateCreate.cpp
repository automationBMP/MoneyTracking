//Co-authors - Andreea Stan, Tudor Chibulcutean, v0.2

// validate CreateWallet implementation 

#include "ValidateCreate.h"
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include "PrintError.h"

using namespace std;

// implementation of constructor without amount
ValidateCreate :: ValidateCreate(string walletName)
{
	walletName_m = walletName;
	amount_m = +00.00;
}

// implementation of constructor with wallet name and amount
ValidateCreate :: ValidateCreate(string walletName, string amount)
{
	walletName_m = walletName;
	amount_m = amount;
}


// implementation of wallet exists function
bool ValidateCreate::WalletExists() 
{
	string walletName = walletName_m;
	
    ifstream f(walletName.c_str());
	
	// check if wallet exists
	/*if (f.good())
	{
		// print error if wallet exists
		PrintError::Print(WALLET_ALREADY_EXISTS,
						walletName_m,
						amount_m);
		cout << "error: wallet " 
			 << walletName 
			 << " already exists! ";*/
	//}
	
	// return if true wallet exists and false if it doesn't exist
	return f.good();
}

// implementation of is valid number function
bool ValidateCreate::IsValidNumber()
{
	string amount = amount_m;
	unsigned int position=0;
	bool isValid = false;
	
	//test if the first element is '+' or '-'
	if ((amount[0] == '+') || (amount[0] == '-'))
	{
		//if the element is '+' or '-' increase the position
		position = 1; 
	}
	
	//go through the string
	for(; position < amount.size(); position++)
	{
		
		//test each position to be in 0..9 interval
		if(amount[position] <= '9' && amount[position] >= '0')
		{
			isValid = true;
		} 
		
		//test if '.' is found 
		else if (amount[position] == '.') 
		{
			//if '.' is found increase the position
			position = position + 1; 
			
			//go through each position after the '.' 
			for(; position < amount.size(); position++)
			{
				//test each position after the '.' to be in 0..9 interval
				if(amount[position] <= '9' && amount[position] >= '0')
				{
					isValid = true;
				} 
				else
				{
					isValid = false;
					break;
				}
			}
		}
		
		//if the string elements are not in 0..9 interval return false
		else
		{
			isValid = false;
			break;
		}
	}
	
	//print error
	if (isValid == false)
	{
		PrintError::Print(CREATE_INITIAL_AMMOUNT_INVALID,
						walletName_m,
						amount_m);
		//cout <<"error: "<< amount << " is not a valid initial amount." << endl;
	    //cout<< "Creating "<< walletName_m <<" aborted.";
	}
	return isValid;
}
