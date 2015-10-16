/*
	Author: Andrei Martinescu
	
	This file contains main implementation for MoneyTracking application.
		
*/

#include <iostream> 
#include <cstring>
#include "DoCreateWallet.h" 
#include "ValidateCreate.h"
#include "MainFunctions.h"
#include "ReadConfig.h"
#include "PrintError.h"
#include "Types.h"

using namespace std;

int main(int argc, char* argv[]) { 

	/*// check if we have enough arguments
	bool flag2 = CheckArgcNumbers(argc ,argv[1]);
	//cout << argc <<endl;	
	if (flag2 == true) 
	{	//check if we have 3 arguments
		if (argc == 3) 
		{
			// element nr 2 on pozition 1 
			int nrArg = 2;
			// convert =argv[1] in string
			string stringArgumentNr2(argv[nrArg-1]);
			if (stringArgumentNr2 == "create") 
			{
				// element nr 3 on pozition 2 
				int nrArg = 3;
				// convert =argv[2] in string
				string 	stringArgumentNr3(argv[nrArg-1]);
				// convert path
				string convertP = ConvertPath(stringArgumentNr3);
				//create object of class ValidateCreate
				ValidateCreate validate(convertP);
				//return bool if wallet exist
				bool flag = validate.WalletExists();
				if (flag == false) 
					{
					//default amount = 00.00;
					string amount = "+00.00";
					//recreate path to initial 
					string reconvert = ConvertPathToOriginal(convertP);
					//apeal function create new wallet with amount 00.00
					DoCreateWallet newWallet(reconvert, amount);
					newWallet.CreateWalletFile();
				//	newWallet.AddLineInWalletFile("+200","income");
					}
			
			}
		}
		//check if we have 4 arguments
		else if (argc == 4) 
			{
				// pozition 2 
				int nrArg = 2;
				// convert =argv[1] in string
				string stringArgumentNr2(argv[nrArg-1]);
				if (stringArgumentNr2 == "create") 
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
					if (flag == false) 
					{
						bool flag1 = validate1.IsValidNumber();
						if (flag1 == true)
						{
							//recreate path to initial 
							string reconvert = ConvertPathToOriginal(convertP);
						    //apeal function create new wallet 
							DoCreateWallet newWallet(reconvert, 
														stringArgumentNr4);
							newWallet.CreateWalletFile();
						}
					}						
				}
			}		
	}*/
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
					
					PrintError::Print(WALLET_ALREADY_EXISTS,
						reconvert,
						amount);
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
					}
					else
						{
							PrintError::Print(WALLET_ALREADY_EXISTS,
											reconvert,
											stringArgumentNr4);
					}					
			}	
		}
		else if (stringArgumentNr2 == "income"||stringArgumentNr2 == "spend") 
		{ 
			if (argc == 3) 
			{
				// pozition 3
				int nrArg = 3;
				// convert =argv[2] in string
				string 	amount(argv[nrArg-1]);
				//cout << amount <<endl;
				//cout << amount[0] <<endl;
				if ((amount[0] == '-') || (amount[0] == '0')) 
				{
				 cout << "error: " << stringArgumentNr2 << " should be higher than 0.\n";
				}
				
				else 
				{
			   
			   //creeam obiectul de tip validate cu suma aflata pe poz 3 si calea ==suma
				ValidateCreate validate(amount,amount);
				bool flag1 = validate.IsValidNumber();
				cout << amount <<endl;
				
				if (flag1 == true)
					{	//create object class ReadConfig for apealing Getdefault Wallet
						ReadConfig getWallet;
						string walletName = getWallet.GetDefaultWallet();
						if (walletName!="Error")
						{
							//converting Path for validating
							string convertP = ConvertPath(walletName);
							ValidateCreate validate1(walletName,amount);
							bool flag = validate1.WalletExists();
							// reconvert path
							string reconvert = ConvertPathToOriginal(convertP);
							if (flag == true )
								{	
									DoCreateWallet newWallet(reconvert,amount);	
									newWallet.AddLineInWalletFile(amount,stringArgumentNr2);
								}
							else cout <<"error: no default wallet "
							  <<"configured in 'moneytracker.config'\n";
						}
						else cout <<"error: could not open configuration "
								  <<"'moneytracker.config'\n";
					}
				}
			}
		}
	}
   return 0; 
}
