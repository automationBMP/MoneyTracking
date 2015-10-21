/*
	Author: Andrei Martinescu
	
	This file contains implementation for main functions .
		
*/

#include "MainFunctions.h"
#include <string>
#include <iostream>
#include "Types.h"
#include "PrintError.h"
#include <fstream>
#include "DoCreateWallet.h" 
#include "ValidateCreate.h"
#include "ReadConfig.h"

using namespace std ;

// function for testing if we have enough arguments
bool CheckArgcNumbers(int const argc ,string const &argument)
{
	bool flag = true ;
	if ((argument == "create")&&(argc<=2))
		{
			//cout << "error: at least filename should be specified.\n";
			PrintError::Print(CREATE_NAME_MISSING,
											"create", "+00.00");
			flag =false;
		}
	else if ((argument == "income")&&(argc<=2))
		{
			//cout << "error: no ammount specified for 'income'.\n";
			PrintError::Print(NO_AMOUNT_SPECIFIED,
											"income", "+00.00");
			flag =false;		
		}
	else if ((argument == "spend")&&(argc<=2))
		{
			//cout << "error: no ammount specified for 'spend'.\n";
			PrintError::Print(NO_AMOUNT_SPECIFIED,
											"spend", "+00.00");
			flag =false;		
		}
	return flag;	
}

//function for converting path  Ex: C:\learn in C:/learn for validating
string ConvertPath(string &givenPath)
{
	for(unsigned int i = 0; i < givenPath.length(); i++)
	{
		if(givenPath[i] == '\\')
		{
			givenPath[i] = '/';
		}
	}
	
return givenPath;	
} 

//function for converting path to original
string ConvertPathToOriginal(string &givenPath)
{
	for(unsigned int i = 0; i < givenPath.length(); i++)
	{
		if(givenPath[i] == '/')
		{
			givenPath[i] = '\\';
		}
	}
return givenPath;	
} 
string ReturnFileasString()
{
	//read moneytracker.config file
	std::ifstream ifs("moneytracker.config");
	//check if is open
	
	//the content of moneytracker.config is transfered to string content
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	return content;
}

void ImpelmentCreate(int arc , char *argv[])
{
	int const nrArg = 2;
	// convert =argv[1] in string
	string stringArgumentNr2(argv[nrArg-1]);
	if (arc <= 2)
		{
			//cout << "error: at least filename should be specified.\n";
			PrintError::Print(CREATE_NAME_MISSING,
											"create", "+00.00");
		}
	else 
	{
		if (arc == 3) 
		{
			int const nrArg = 3;
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
			}
			else
			{	
				PrintError::Print(WALLET_ALREADY_EXISTS, reconvert,	amount);
			}
		} 
		else if (arc >= 4) 
		{
			// pozition 3
			int const nrArg = 3;
			// convert =argv[2] in string
			string 	stringArgumentNr3(argv[nrArg-1]);
			// convert path
			string convertP = ConvertPath(stringArgumentNr3);
			// convert =argv[3] in string
			string 	stringArgumentNr4(argv[nrArg]);
			//create object of class ValidateCreate
			ValidateCreate validate1(convertP, stringArgumentNr4);
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
}
void CommandInterpreter(int arc, char *argv[])
{
	int const nrArg = 2;
	// convert =argv[1] in string
	string stringArgumentNr2(argv[nrArg-1]);
	if (stringArgumentNr2 == "create")
	{
		ImpelmentCreate(arc, argv);
	}
	else if ((stringArgumentNr2 == "income")||(stringArgumentNr2 == "spend"))
	{
		ImplementIncomeSpend(arc, argv);
	}
/*  else if (stringArgumentNr2 == "balance")
	{
		ImpelmentBalance(arc, argv);
	}
*/	
}

void ImplementIncomeSpend(int arc, char *argv[])
{
	int const nrArg = 2;
	// convert =argv[1] in string
	string stringArgumentNr2(argv[nrArg-1]);
	if ((stringArgumentNr2 == "income")&&(arc<=2))
	{
		//cout << "error: no ammount specified for 'income'.\n";
		PrintError::Print(NO_AMOUNT_SPECIFIED,
										"income", "+00.00");
		//flag =false;		
	}
	else if ((stringArgumentNr2 == "spend")&&(arc<=2))
	{
		//cout << "error: no ammount specified for 'spend'.\n";
		PrintError::Print(NO_AMOUNT_SPECIFIED,
										"spend", "+00.00");
		//flag =false;		
	}
	if (arc >= 3) 
	{
			// pozition 3
			int const nrArg = 3;
			// convert =argv[2] in string
			string 	amount(argv[nrArg-1]);
			//check if amount is a positive number
			if ((amount[0] == '-') || (amount[0] == '0')) 
			{
			// if not positive print error
				if (stringArgumentNr2 == "income")
				{
					PrintError::Print(AMOUNT_NOT_POSITIVE_INCOME,
										stringArgumentNr2, amount);
				}
				else if (stringArgumentNr2 == "spend")
				{
					PrintError::Print(AMOUNT_NOT_POSITIVE_SPEND,
										stringArgumentNr2, amount);
				}
			}
			else 
			{			   
				//create object validate with parameters "defaut_wallet" 
				//and amount
				ValidateCreate validate("default_wallet",amount);
				// check if amount is a valid number
				bool flag1 = validate.IsValidNumber();
				if (flag1 == true)
				{	
					//read config file
					string contentConfigFile(ReturnFileasString());
					//create object ReadConfig for geting the wallet
					ReadConfig getWallet;
					string walletName = 
								getWallet.GetDefaultWallet(contentConfigFile);
								
					if (walletName == "Error")
					{	
						// if the method GetDefaultWallet return Error
						PrintError::Print(NO_DEFAULT_WALLET,
											"default wallet", amount);							
					}
					else if (walletName == "NoConfig")
					{	
						// if the method GetDefaultWallet return NoConfig
						PrintError::Print(COULD_NOT_OPEN_CONFIG,
											"default_wallet", amount);
					}
					else if (walletName == "") 
					{
						// if the method GetDefaultWallet return ""
						PrintError::Print(NO_DEFAULT_WALLET,
											"default_wallet", amount);
					}
					else 
					{
						//converting Path for validating
						string convertP = ConvertPath(walletName);
						//validating path
						ValidateCreate validate1(convertP,amount);
						bool flag = validate1.WalletExists();
						// reconvert path to original
						string reconvert = ConvertPathToOriginal(convertP);
						if (flag == true )
						{	
							//if valid path then add new line in wallet
							DoCreateWallet newWallet(reconvert,amount);	
							newWallet.AddLineInWalletFile(amount,
														stringArgumentNr2);
						}
						else 
						{
							//if path is not valid print error
							PrintError::Print(COULD_NOT_OPEN_PATH,
											reconvert, amount);
						}
					}
				}
					//if amount is not valid number print error
					else PrintError::Print(SHOULD_BE_POSITIVE,
											stringArgumentNr2, amount);
			}
	}	
}