//Author: Andrei Martinescu, v0.2

#include "MainFunctions.h"
#include <string>
#include <iostream>
#include "Types.h"
#include "PrintError.h"
#include <fstream>
#include "DoCreateWallet.h" 
#include "ValidateCreate.h"
#include "ReadConfig.h"
#include <cstring>
#include "GetBalance.h"
#include "ConfigFile.h"


using namespace std ;

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

string ReturnFileasString(const string &filename)
{
	//string filename1 = filename;
	//read moneytracker.config file
	std::ifstream ifs(filename.c_str());
	//check if is open
	if (!ifs.is_open()) 
	{  
		return "NotOpen";
	}
	else 
	{	//the content of moneytracker.config is transfered to string content
		std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
		ifs.close();
		return content;
	}
	
}

//function implementCreateForThreeArguments
void ImplementCreateThreeArguments(int arc,char *argv[])
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
void ImplementCreateFourArguments(int arc,char *argv[])
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

void ImplementBalance (int arc, char *argv[])
{
	std::string str = "moneytracker.config";
	std::string category = "";
	bool validCommand = true;
	//const char *cstr = str.c_str();
		string contentConfigFile(ReturnFileasString(str));
		ReadConfig getWallet;
		std::string defaultEntry = "default_wallet";
		string walletName = 
				getWallet.GetDefaultWallet(contentConfigFile, defaultEntry);
		//check if wallet name is valid
		if ((walletName == "NoDefaultWalletFound") ||
											(walletName == "EmptyConfig")
											||
											(walletName == "NoWalletNameFound"))
		{	
			PrintError::Print(NO_DEFAULT_WALLET,"default wallet", "+00.00");							
		}
		else if (walletName == "NotOpen")
		{	
			// if the method GetDefaultWallet return NoConfig
			PrintError::Print(COULD_NOT_OPEN_CONFIG,"default_wallet", "+00.00");
		}
		else 
		{
			//if a category is introduced after balance 
			if ((arc > 2) && (arc < 5))
			{
				if ((strcmp(argv[2],"-c")) == 0||(strcmp(argv[2],"--category") == 0))
				{
					if (arc == 3)
					{
						validCommand = false;
						PrintError::Print(INVALID_PARAMETER,"balance", "+00.00");
					}
					else
					{
						category = argv[3]; 
					}
				}
				else
				{
					validCommand = false;
					PrintError::Print(INVALID_PARAMETER,"balance", "+00.00");
				}
			}
			else if (arc > 4)
			{
				validCommand = false;
				PrintError::Print(INVALID_PARAMETER,"balance", "+00.00");
			}
			
			string convertP = ConvertPath(walletName);
			//validating path
			ValidateCreate validate1(convertP,"+00.00");
			bool flag = validate1.WalletExists();
			// reconvert path to original
			string reconvert = ConvertPathToOriginal(convertP);
			if (flag == true )
			{	
				//if valid path then add new line in wallet
				string contentWalletFile(ReturnFileasString(walletName));
				GetBalance balance;
				string balanceFromWallet = 
									balance.PrintBalance(contentWalletFile, category);
				// add decimals to balance 
				DoCreateWallet addDecimals(walletName, balanceFromWallet);
				string balanceWithdecimals = 
									addDecimals.AddDecimalsToDefaultAmount();
				
				//if the category exists print balance for the specified category
				if (balance.CategoryExists()) 
				{
					cout << "Balance for '" 
					 << category 
					 << "' in '"
					 << walletName 
					 << "' is " 
					 << balanceWithdecimals 
					 << " RON."
				     << endl;	
				}
				
				//if the category introduced is not found in the wallet file
				//print message 
				 else if (category != "")
				{
					cout << "No transaction with category '" 
						 << category 
						 << "' is registered in "
						 << walletName
						 << "."
						 << endl;
				}  
				else if (validCommand == true)
					
				//if no category is introduced print balance for the whole wallet
				{
				cout << "Balance for " 
					 << walletName 
					 << " is " 
					 << balanceWithdecimals 
					 << " RON."
				     << endl;
				}					 
			}
			else 
			{
				//if path is not valid print error
				PrintError::Print(COULD_NOT_OPEN_PATH_BALANCE, 
														reconvert, "+00.00");
			}
		
		}
}

void ImplementConfig(int arc, char *argv[])
{
	std::string configString = "moneytracker.config";
	std::string printConfig = ReturnFileasString(configString);
	std::string content;
	int pozition = 0;
	size_t l=0;
	std::string * arguments = new string[2];
	if (arc == 2) 
	{
		cout << printConfig;
	}
	else if (arc > 2)
	{
		string *argument = new string [arc-2];
		int j = 0;
		for (int i =2; i<arc; i++)
		{
			argument[j] = argv[i];
			j++;
		}
		if ((arc == 3) || (arc == 4) || (arc == 5))
		{
	       // cout << argument [0]<<endl;
			for (int i =0; i<arc-2; i++)
			{
				content = content + argument[i];
			}
			//cout << content<<endl;
			//content.erase(std::remove(content.begin(),content.end(),' '),content.end());
			//cout << content<<endl;
			for (size_t i=0; i<content.length(); i++)
			{
				//cout << content<<endl;
				if (content[i] == '=') 
				{
					pozition = i;
					//cout << pozition << endl;
					break;
				}
			}
			for (size_t i=0; i<content.length(); i++)
			{
				//cout << content<<endl;
				if (content[i] != '=') 
				{
					l++;
				}
			}
			if (l == content.length())
			{
				cout << "invalid parameters for config"<<endl;
			}
			
			arguments[0] = content.substr(0,pozition);
			arguments[1] = content.substr(pozition+1,content.length()-pozition-1);
			//cout << arguments [0] << endl;
			//cout << arguments [1] << endl;
		}
		else 
		{
			std::cout <<"invalid parameters for config." <<endl;
		}
		for (int i =0; i<2; i++)
		{
			 //std:: string checkIfCorect = arguments[i].substr(0,arguments[i].find('='));
			 std:: string checkIfCorect = arguments[0];
			 if ((arguments[i].find("default_wallet") != std::string::npos)||
				(arguments[i].find("default_currency") != std::string::npos)||
				(arguments[i].find("default_income_category") != std::string::npos)||
				(arguments[i].find("default_spending_category") != std::string::npos)||
				(arguments[i].find("currencies") != std::string::npos)||
				(arguments[i].find("rate_EUR_RON") != std::string::npos)||
				(arguments[i].find("rate_RON_EUR") != std::string::npos)||
				(arguments[i].find("rate_USD_RON") != std::string::npos)||
				(arguments[i].find("rate_EUR_USD") != std::string::npos))
				{
					//cout << arguments[i].find("default_wallet") <<endl;
					if ((checkIfCorect == "default_wallet")||
						(checkIfCorect == "default_currency")||
						(checkIfCorect == "default_income_category")||
						(checkIfCorect == "default_spending_category")||
						(checkIfCorect == "currencies")||
						(checkIfCorect == "rate_EUR_RON")||
						(checkIfCorect == "rate_RON_EUR")||
						(checkIfCorect == "rate_USD_RON")||
						(checkIfCorect == "rate_EUR_USD"))
						{
							// apeal function change
							//size_t pozEquals = arguments[i].find('=');
							//size_t lengthOfCommandWithoutFirstParameter = arguments[i].length()-arguments[i].find('=');
							//std:: string changeValue = arguments[i].substr(pozEquals+1,lengthOfCommandWithoutFirstParameter);
							//cout << changeValue <<endl;
							//cout << checkIfCorect <<endl;
							std:: string changeValue = arguments[1];
							if (changeValue == "")
							{
								cout << "Invalid parameters for config" << endl;
								break;
							}
							else
							{
							ConfigFile changeConfig(printConfig, changeValue, checkIfCorect);
							std::string newConfig = changeConfig.ChangeConfigFile();
							changeConfig.ReWriteConfigFile(); 
							break;
							}
						}
					else 
					{
						cout << "'" 
							 << checkIfCorect
							 << "'"
							 << " is not a valid configuration value.\n";
							 break;
					}   
				} 
				else 
				{
					cout << "'" 
						 << checkIfCorect
						 << "'"
						 << " is not a valid configuration value.\n";
					break;
				}
		}
	}
}

std::string* ValidateIncomeSpendCommands(int argc, char* argv[])
{
	// implement for default categorry
	string *arguments = new string [argc-2];
	int j = 0;
	 for (int i =2; i<argc; i++)
	{
		arguments[j] = argv[i];
		j++;
	} 
	int k = 0;
	int pozition = 0;
	bool flag = false;
	while (k <= argc-3) 
	{
		if ((argc-3)==0)
		{
			ValidateCreate validateNumber("default_wallet",arguments[k]);
			bool flag2 = validateNumber.IsValidNumber();
			if (flag2 == true)
			{	
				pozition = k;
				flag = true;
				k = argc;				
			}
			else 
			{
				//PrintError::Print(SHOULD_BE_POSITIVE,
				//					argv[1], argv[2]);
				cout << "error: invalid parameters for '" << argv[1] << "'."<<endl;
				k = argc;
			}
		}
		else if ((argc-3)==2)
		{
			//cout << "enter";
			ValidateCreate validateNumber("default_wallet",arguments[k]);
			bool flag2 = validateNumber.IsValidNumber();
			if (flag2 == true)
			{
				if ((arguments[k+1]=="-c")||(arguments[k+1]=="--category")||(arguments[k+1]=="-w")||(arguments[k+1]=="--wallet"))
				{
					pozition = k;
					k = argc;
					flag = true;
				}
				else 
				{
					cout << "error: invalid parameters for '" << argv[1] << "'."<<endl;
					//cout << "Not a valid comand for " << argv[1] << endl;
					k = argc;
				}
			}
			else 
			{
				ValidateCreate validateNumber("default_wallet",arguments[2]);
				bool flag2 = validateNumber.IsValidNumber();
				k = 2;
				if (flag2 == true)
				{
					if ((arguments[k-2]=="-c")||(arguments[k-2]=="--category")||(arguments[k-2]=="-w")||(arguments[k-2]=="--wallet"))
					{
						pozition = k;
						k = argc;
						flag = true;
					}
					else 
					{
						cout << "error: invalid parameters for '" << argv[1] << "'."<<endl;
						//cout << "Not a valid comand for " << argv[1] << endl;
						k = argc;
						
					}
				}
				else 
				{
					cout << "error: invalid parameters for '" << argv[1] << "'."<<endl;
					//cout << "Not a valid comand for " << argv[1] << endl;
					k = argc;
				}
			}	
		}
		else if ((argc-3)==4)
		{
			ValidateCreate validateNumber("default_wallet",arguments[k]);
			bool flag2 = validateNumber.IsValidNumber();
			if (flag2 == true)
			{	
				if ((arguments[k+1] != arguments[k+3])&&((arguments[k+1]=="-c")||(arguments[k+1]=="--category")||(arguments[k+1]=="-w")||(arguments[k+1]=="--wallet"))
								&&((arguments[k+3]=="-c")||(arguments[k+3]=="--category")||(arguments[k+3]=="-w")||(arguments[k+3]=="--wallet")))
				{	
					pozition = k;
					k = argc;
					flag = true;
				}
				else 
				{
					cout << "error: invalid parameters for '" << argv[1] << "'."<<endl;
					//cout << "Not a valid comand for " << argv[1] << endl;
					k = argc;
					
				}
			}
			else 
			{
				ValidateCreate validateNumber("default_wallet",arguments[2]);
				bool flag2 = validateNumber.IsValidNumber();
				k = 2;
				if (flag2 == true)
				{
					if ((arguments[k-2] != arguments[k+1])&&((arguments[k-2]=="-c")||(arguments[k-2]=="--category")||(arguments[k-2]=="-w")||(arguments[k-2]=="--wallet"))
								&&((arguments[k+1]=="-c")||(arguments[k+1]=="--category")||(arguments[k+1]=="-w")||(arguments[k+1]=="--wallet")))
					{
						pozition = k;
						k = argc;
						flag = true;
					}
					else 
					{
						cout << "error: invalid parameters for '" << argv[1] << "'."<<endl;
						//cout << "Not a valid comand for " << argv[1] << endl;
						k = argc;
					}
				}
				else 
				{
					ValidateCreate validateNumber("default_wallet",arguments[4]);
					bool flag2 = validateNumber.IsValidNumber();
					k = 4;
					if (flag2 == true)
					{
						if ((arguments[k-2] != arguments[k-4])&&((arguments[k-2]=="-c")||(arguments[k-2]=="--category")||(arguments[k-2]=="-w")||(arguments[k-2]=="--wallet"))
									&&((arguments[k-4]=="-c")||(arguments[k-4]=="--category")||(arguments[k-4]=="-w")||(arguments[k-4]=="--wallet")))
						{
							pozition = k;
							k = argc;
							flag = true;
						}
						else 
						{
							//cout << "Not a valid comand for " << argv[1] << endl;
							cout << "error: invalid parameters for '" << argv[1] << "'."<<endl;
							k = argc;
						}
					}
					else 
					{
						//cout << "Not a valid comand for " << argv[1] << endl;
						cout << "error: invalid parameter for '" << argv[1] << "'."<<endl;
						k = argc;
										
					}
				}
			}		
		}
		else 
		{
			//cout << "Not a valid command for " << argv[1] << endl;
			cout << "error: invalid parameters for '" << argv[1] << "'."<<endl;
			k = argc;
		} 
	}

	

std::string * newArguments = new string [argc-2];
if (flag == true) {
newArguments[0] = arguments[pozition];
}
int iterator = 1;
if (flag == true) 
{
	for (int i=0 ; i<=argc-3; i++)
	{
		if (i != pozition) 
		{
			newArguments[iterator] = arguments[i] ;
			iterator++;
		}
	}
}

/* for (int i=0 ; i<=argc-3; i++)
{
	cout << newArguments[i] << endl;
}  */
/* else
{
	cout << "no valid " << endl;
} */

return newArguments;
}

//function command interpreter
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
	else if (stringArgumentNr2 == "balance")
	{
		ImplementBalance(arc, argv);
	}
	else if (stringArgumentNr2 == "config")
	{
		ImplementConfig(arc, argv);
	}
	else 
	{
		cout << "error: invalid command !\n";
	}
	
}

//implement create commands and apeal functions for comands
void ImpelmentCreate(int arc , char *argv[])
{
	int const nrArg = 2;
	// convert =argv[1] in string
	string stringArgumentNr2(argv[nrArg-1]);
	if (arc <= 2)
		{
			PrintError::Print(CREATE_NAME_MISSING, "create", "+00.00");
		}
	else 
	{
		if (arc == 3) 
		{
			ImplementCreateThreeArguments(arc, argv);
			
		} 
		else if (arc == 4) 
		{
			ImplementCreateFourArguments(arc, argv);	
		}
		else if (arc > 4)
		{
			PrintError::Print(INVALID_PARAMETER,
							"create", "+00.00");
		}
	}
}


//print errors if the amount is <= 0
void PrintIncomeSpendNegative(string incomeOrSpend, string amount)
{
	if (incomeOrSpend == "income")
	{
		PrintError::Print(AMOUNT_NOT_POSITIVE_INCOME,
							incomeOrSpend, amount);
	}
	else if (incomeOrSpend == "spend")
	{
		PrintError::Print(AMOUNT_NOT_POSITIVE_SPEND,
							incomeOrSpend, amount);
	}
}

//print error if no amount is specified
void PrintNoAmountSpecified(string incomeOrSpend)
{
	if (incomeOrSpend == "income")
		{
			PrintError::Print(NO_AMOUNT_SPECIFIED,
											"income", "+00.00");	
		}
		else if (incomeOrSpend == "spend")
		{
			PrintError::Print(NO_AMOUNT_SPECIFIED,
											"spend", "+00.00");	
		}
}

void PrintInFileIfWalletFound(string amount, 
						      string incomeOrSpend, 
							  string category,
							  string wallet)
{	
	if(wallet == "")
	{
		std::string str = "moneytracker.config";
		//const char *cstr = str.c_str();
		string contentConfigFile(ReturnFileasString(str));
		//read config file
		//string moneytrackerConfig = "moneytracker.config";
		//string contentConfigFile(ReturnFileasString(moneytrackerConfig));
		//create object ReadConfig for geting the wallet
		ReadConfig getWallet;
		string variable = "default_wallet";
		string walletName = 
					getWallet.GetDefaultWallet(contentConfigFile, variable);
		// if return NoDefaultWalletFound or EmptyConfig or NoWalletNameFound		
		if ((walletName == "NoDefaultWalletFound") ||
												(walletName == "EmptyConfig")
												||
												(walletName == "NoWalletNameFound"))
		{	
			PrintError::Print(NO_DEFAULT_WALLET,"default wallet", amount);							
		}
		else if (walletName == "NotOpen")
		{	
			// if the method GetDefaultWallet return NoConfig
			PrintError::Print(COULD_NOT_OPEN_CONFIG,"default_wallet", "+00.00");
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
				std::string wallettt;
				newWallet.AddLineInWalletFile(amount, incomeOrSpend, category ,wallettt);
			}
			else 
			{
				//if path is not valid print error
				PrintError::Print(COULD_NOT_OPEN_PATH, reconvert, amount);
			}
		}
	}
	else
	{
		//converting Path for validating
		string convertP = ConvertPath(wallet);
		//validating path
		ValidateCreate validate1(convertP,amount);
		bool flag = validate1.WalletExists();
		// reconvert path to original
		string reconvert = ConvertPathToOriginal(convertP);
		if (flag == true )
		{	
			//if valid path then add new line in wallet
			DoCreateWallet newWallet(reconvert,amount);	
			newWallet.AddLineInWalletFile(amount, incomeOrSpend, category, wallet);
		}
		else 
		{
			//if path is not valid print error
			PrintError::Print(COULD_NOT_OPEN_PATH, reconvert, amount);
		}
	}
}

// removing the 0's from the begining
string RemoveStartingZeroes(string wallet)
{
	unsigned int start = 0, i = 0;
	char sign ;
	//searching for an existing sign
	if (wallet[0] == '+' || wallet[0] == '-')
	{
		sign = wallet[0];
		start = 1;
		i = start;
		// counting the start 0's
		while (wallet[i] == '0')
		{
			++i;
		}
		// case : 000.7
		if ((wallet[i] == '.') && (i < wallet.length()))
		{
			wallet = 
				wallet.substr (i-1,wallet.length()-i+1);

		}
		//case : 001
		else if (i < wallet.length())
		{
			wallet = 
				wallet.substr (i,wallet.length()-i);
		}
		//case: 0000
		else 
		{
			wallet = 
				wallet.substr (i-1,wallet.length()-i+1);
		}
		if (wallet != "0") 
		{
		return wallet = sign + wallet;
		}
		else return "0";

	}else 
		{
			start = 0;
			i = start;
			// counting the start 0's
			while (wallet[i] == '0')
			{
			++i;
			}
			// case : 000.7
			if ((wallet[i] == '.') && (i < wallet.length()))
			{
				wallet = 
					wallet.substr (i-1,wallet.length()-i+1);

			}
			//case : 001
			else if (i < wallet.length())
			{
				wallet = 
					wallet.substr (i,wallet.length()-i);
			}
			//case: 0000
			else 
			{
				wallet = 
					wallet.substr (i-1,wallet.length()-i+1);
			}		
		}
		if (wallet != "0") 
		{
			wallet = "+" + wallet;
		}
	return wallet;
}

void ImplementIncomeSpend(int argc, char *argv[])
{
	string stringArgumentNr2(argv[1]);
	string category = "";
	string wallet = "";
	//cout << "DSFs";
	if (argc<=2)
	{
		PrintNoAmountSpecified(stringArgumentNr2);
	}
	else
	{
		//set the default category
		if (stringArgumentNr2 == "income")
		{
			category = "salary";
		}
		else if (stringArgumentNr2 == "spend")
		{
			category = "other";
		}
	}
	
	// get parameters for income/spend
	string* parameters = ValidateIncomeSpendCommands(argc, argv);
	 
 	for (int i = 0; i < (argc - 2) ; i++)
	{
		if (parameters[i] == "-c" || 
			parameters[i] == "--category")
		{
			category = parameters[++i];
		}
		else if (parameters[i] == "-w"|| 
				 parameters[i] == "--wallet")
		{
			wallet = parameters[++i];
		}
		else 
		{}
	}
	
	string amount = parameters[0];
	
	if (argc < 8 && parameters->length() > 0) // <8
	{		
		// if there is no amount specified print error
		if (amount == "")
		{
			PrintError::Print(NO_AMOUNT_SPECIFIED, argv[1], amount);
		}
		
		// if there is an amount specified
		else 
		{
			// if amount is negative or 0 print error
			if (amount[0] == '-' || amount == "0" || amount == "0.0") 
			{
				PrintIncomeSpendNegative(argv[1], amount);
			}
			
			// if amount is positive
			else if (amount == "00.00")
			{
				//create object validate with parameters "default_wallet" 
				//and amount
				ValidateCreate validate("default_wallet", amount);
				
				// check if amount is a valid number
				if (validate.IsValidNumber() == true)
				{
					PrintInFileIfWalletFound(amount,
											 argv[1], 
											 category,
											 wallet);
				}
				//if amount is not valid number print error
				else PrintError::Print(SHOULD_BE_POSITIVE,
									   argv[1], 
									   amount);
			}
			else 
			{
				DoCreateWallet amountWithZeroes(wallet, amount);
				amount = amountWithZeroes.RemoveStartingZeroes();
				
				//create object validate with parameters "default_wallet" 
				//and amount
				ValidateCreate validate("default_wallet", amount);
				
				// check if amount is a valid number
				if (validate.IsValidNumber() == true)
				{
					
					PrintInFileIfWalletFound(amount,
											 argv[1], 
											 category,
											 wallet);
				}
				//if amount is not valid number print error
				else PrintError::Print(SHOULD_BE_POSITIVE,
									   argv[1], 
									   amount);
			}
		}
	}
	else if (parameters->length() == 0)
	{
	}
}

/* void ImplementIncomeSpend(int argc, char* argv[])
{
	// get parameters for income/spend
	string* parameters = getParametersIncomeSpend(argc - 2, &argv[2]);
	string amount = parameters[0];
	string category = parameters[1];
	string wallet = parameters[2];
	
	if (category == "")
	{
		if (strcmp(argv[1], "income") == 0)
		{
			category = "salary";
		}
		else
		{
			category = "other";
		}
	}
	else
	{}
	
	// if there are invalid parameters print error
	if(amount == "error")
	{
		PrintError::Print(INVALID_PARAMETER, argv[1], amount);
	}
	
	// if there is no amount specified print error
	else if (amount == "")
	{
		PrintError::Print(NO_AMOUNT_SPECIFIED, argv[1], amount);
	}
	
	// if there is an amount specified
	else 
	{
		// if amount is negative or 0 print error
		if ((amount[0] == '-') || (amount[0] == '0')) 
		{
			PrintIncomeSpendNegative(argv[1], amount);
		}
		
		// if amount is positive
		else
		{
			//create object validate with parameters "default_wallet" 
			//and amount
			ValidateCreate validate("default_wallet", amount);
			
			// check if amount is a valid number
			if (validate.IsValidNumber() == true)
			{
				PrintInFileIfWalletFound(amount,
										 argv[1], 
										 category,
										 wallet);
			}
			//if amount is not valid number print error
			else PrintError::Print(SHOULD_BE_POSITIVE,
								   argv[1], 
								   amount);
		}
	}
	
} */