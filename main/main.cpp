/*
	Author: Andrei Martinescu
	
	This file contains main implementation for MoneyTracking application.
		
*/

#include <iostream> 
#include <string>
#include "DoCreateWallet.h" 
#include "ValidateCreate.h"
#include "MainFunctions.h"
#include "ReadConfig.h"
#include "PrintError.h"
#include "Types.h"

using namespace std;

int main(int argc, char* argv[])
 { 
	// check if we have enough arguments
	bool flag2 = CheckArgcNumbers(argc ,argv[1]);
	//cout << argc <<endl;	
	if (flag2 == true) 
	{
	int nrArg = 2;
	// convert =argv[1] in string
	string stringArgumentNr2(argv[nrArg-1]);
	if (stringArgumentNr2 == "create")
		{
		if (argc == 3) 
		{
		int nrArg = 3;
			// convert =argv[2] in string
			string 	stringArgumentNr3(argv[nrArg-1]);
			// convert path
			string convertP = ConvertPath(stringArgumentNr3);
			//create object of class ValidateCreate
			ValidateCreate validate(convertP);
			//return bool if wallet exist
			bool flag = validate.WalletExists();
			//default amount = 00.00;
			string amount = "+00.00";
			//recreate path to initial 
			string reconvert = ConvertPathToOriginal(convertP);
			//apeal function create new wallet with amount 00.00
			DoCreateWallet newWallet(reconvert, amount);
			if (flag == false) 
				{
				
				newWallet.CreateWalletFile();
				//	newWallet.AddLineInWalletFile("+200","income");
				}
			else
				{	
					PrintError::Print(WALLET_ALREADY_EXISTS, reconvert,	amount);
				}
		} 
		else if (argc >= 4) 
			{
					// pozition 3
					int nrArg = 3;
					// convert =argv[2] in string
					string 	stringArgumentNr3(argv[nrArg-1]);
					// convert path
					string convertP = ConvertPath(stringArgumentNr3);
					// convert =argv[3] in string
					string 	stringArgumentNr4(argv[nrArg]);
					//create object of class ValidateCreate
					ValidateCreate validate1(convertP, stringArgumentNr4);
					//cout << convert << endl;
					//return bool if wallet exist
					bool flag = validate1.WalletExists();
					//recreate path to initial 
					string reconvert = ConvertPathToOriginal(convertP);
					//apeal function create new wallet 
					DoCreateWallet newWallet(reconvert, 
														stringArgumentNr4);
					if (flag == false) 
					{
						bool flag1 = validate1.IsValidNumber();
						
						if (flag1 == true)
						{
							newWallet.CreateWalletFile();
						}
						else 
						{
							PrintError::Print(CREATE_INITIAL_AMMOUNT_INVALID,
												reconvert, stringArgumentNr4);	
						}
					}
					else
						{
							PrintError::Print(WALLET_ALREADY_EXISTS,
											reconvert, stringArgumentNr4);
					}					
			}	
		}
		else if (stringArgumentNr2 == "income"||stringArgumentNr2 == "spend") 
		{ 
			if (argc >= 3) 
			{
				// pozition 3
				int nrArg = 3;
				// convert =argv[2] in string
				string 	amount(argv[nrArg-1]);
				//cout << amount <<endl;
				//cout << amount[0] <<endl;
				if ((amount[0] == '-') || (amount[0] == '0')) 
				{
				 PrintError::Print(AMOUNT_NOT_POSITIVE,
											"default_wallet", amount);
				}
				else 
				{			   
			   //creeam obiectul de tip validate cu suma aflata pe poz 3 si calea ==suma
				ValidateCreate validate("default_wallet",amount);
				bool flag1 = validate.IsValidNumber();
				//cout << amount <<endl;
				
				if (flag1 == true)
					{	
						//read config file
						string contentConfigFile(ReturnFileasString());
						//create object class ReadConfig for apealing Getdefault Wallet
						ReadConfig getWallet;
						string walletName = getWallet.GetDefaultWallet(contentConfigFile);
						if (walletName=="Error")
						{
							PrintError::Print(NO_DEFAULT_WALLET,
											"default wallet", amount);							
							
						}
						else if (walletName=="NoConfig")
						{
							PrintError::Print(COULD_NOT_OPEN_CONFIG,
											"default_wallet", amount);
						}
						else if (walletName=="") 
						{
							PrintError::Print(NO_DEFAULT_WALLET,
											"default_wallet", amount);
						}
						else 
						{
							//converting Path for validating
							string convertP = ConvertPath(walletName);
							ValidateCreate validate1(convertP,amount);
							bool flag = validate1.WalletExists();
							// reconvert path
							string reconvert = ConvertPathToOriginal(convertP);
							if (flag == true )
								{	
									DoCreateWallet newWallet(reconvert,amount);	
									newWallet.AddLineInWalletFile(amount,stringArgumentNr2);
								}
							else 
							{
								PrintError::Print(COULD_NOT_OPEN_PATH,
											reconvert, amount);
							}
							
						}
					}
					else PrintError::Print(SHOULD_BE_POSITIVE,
											"default_wallet", amount);
				}
			}
		}
	}
   return 0; 
}
