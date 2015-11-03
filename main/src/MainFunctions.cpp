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
									balance.PrintBalance(contentWalletFile, 
									category);
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
						 << "' is registered in '"
						 << walletName
						 << "'."
						 << endl;
				}  
				else if (validCommand == true)
					
				//if no category is introduced print balance for the whole wallet
				{
				cout << "Balance for '" 
					 << walletName 
					 << "' is " 
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
	// creating string with name of config
	std::string configString = "moneytracker.config";
	// obtain the content of config
	std::string printConfig = ReturnFileasString(configString);
	std::string content;
	bool flag1 = true;
	bool flag2 = true;
	bool flag3 = true;
	bool flag4 = true;
	bool flag5 = true;
	int pozition = 0;
	size_t l=0;
	//create a string array with  2 pozitions
	std::string * arguments = new string[2];
	// if only 2 arguments (moneytracker config) print config
	if (arc == 2) 
	{
		cout << printConfig;
	}
	// else validate the commands
	else if (arc > 2)
	{
		// create a string array with elements from argv from poz 2
		string *argument = new string [arc-2];
		int j = 0;
		for (int i =2; i<arc; i++)
		{
			argument[j] = argv[i];
			j++;
		}
		// check case we have 3 parameters and one is == , print error
		for (int i =0; i<arc-2; i++)
		{
			if (argument[i] == "==")
			{
			    cout << "error: invalid parameters for 'config'."<<endl;
				flag1 = false;
				break;
			}
		}
		
		//check if we don't have 4 arguments and one has = at the end
		std::string stringCheck = argument[0];
		if ((stringCheck[stringCheck.length()-1]== '=')&&(arc != 4))
		{
			    cout << "error: invalid parameters for 'config'."<<endl;
				flag2 = false;
			
		}
		//check if one parameter has = at the end and the other parameter 
		//contain =
		std::string stringCheckk = argument[0];
		if ((stringCheck[stringCheck.length()-1]== '=')
			&&(stringCheck[stringCheck.length()-2]== '='))
		{
			    cout << "error: invalid parameters for 'config'."<<endl;
				flag3 = false;
			
		}

		// validate case
		if (((arc == 3) || (arc == 4) || (arc == 5))&&(flag1==true)
			&&(flag2==true)&&(flag3==true))
		{
			//obtain a string with all parameters
			for (int i =0; i<arc-2; i++)
			{
				content = content + argument[i];
			}
			//check for = sign
			for (size_t i=0; i<content.length(); i++)
			{
				if (content[i] == '=') 
				{
					pozition = i;
					break;
				}
			}
			//check if we don't have sign =
			for (size_t i=0; i<content.length(); i++)
			{
				if (content[i] != '=') 
				{
					l++;
				}
			}
			//print error if we don't have sign =
			if ((l == content.length())&&(flag1==true)&&
			(flag2==true)&&(flag3==true))
			{
				cout << "error: invalid parameters for 'config'."<<endl;
				flag4 = false;
			}
			// obtain first parameter and second
			arguments[0] = content.substr(0,pozition);
			arguments[1] = content.substr(pozition+1,
			content.length()-pozition-1);
		}
		// print error if we don't have enough arguments
		else if ((flag1==true)&&(flag2==true)&&(flag3==true)&&(flag4==true))
		{
			std::cout <<"error: invalid parameters for 'config'." <<endl;
			flag5 = false;
		}
		// check for validating the arguments
		for (int i =0; i<2; i++)
		{
			
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
					// check if first parameter is correct
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

							std:: string changeValue = arguments[1];
							//check if second parameter is null
							if ((changeValue == "")&&(flag1==true)
								&&(flag2==true)&&(flag3==true)&&
							(flag4==true)&&(flag5==true))
							{
								cout << "error: invalid parameters for 'config'."
								<< endl;
								break;
							}
							// else change config
							else
							{
							ConfigFile changeConfig(printConfig, changeValue, 
							checkIfCorect);
							std::string newConfig = changeConfig.ChangeConfigFile();
							changeConfig.ReWriteConfigFile(); 
							break;
							}
						}
					// else if first parameter is not correct print error
					else 
					{
						if ((flag1==true)&&(flag2==true)&&(flag3==true)
							&&(flag4==true)&&(flag5==true))
						{
						cout << "'" 
							 << checkIfCorect
							 << "'"
							 << " is not a valid configuration value.\n";
							 break;
						}
					}   
				}
				//else we don't found a match for first parameter in config
				//print error
				else if ((flag1==true)&&(flag2==true)&&(flag3==true)
					&&(flag4==true)&&(flag5==true))
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
	// create string array with argc-2 nr of elements
	string *arguments = new string [argc-2];
	int j = 0;
	// adding the arguments from command line in string array
	 for (int i =2; i<argc; i++)
	{
		arguments[j] = argv[i];
		j++;
	} 
	int k = 0;
	int pozition = 0;
	bool flag = false;
	// cheack if we have enough arguments
	while (k <= argc-3) 
	{
		//case we have 3 arguments EX: moneytracker income 200
		if ((argc-3)==0)
		{
			ValidateCreate validateNumber("default_wallet",arguments[k]);
			bool flag2 = validateNumber.IsValidNumber();
			// if valid command
			if (flag2 == true)
			{	
				pozition = k;
				flag = true;
				k = argc;				
			}
			// else print error
			else 
			{
				//PrintError::Print(SHOULD_BE_POSITIVE,
				//					argv[1], argv[2]);
				cout << "error: invalid parameters for '" 
				     << argv[1] 
				     << "'."
					 << endl;
				k = argc;
			}
		}
		//case we have 5 arguments EX: moneytracker income -c category 200
		else if ((argc-3)==2)
		{
			//check if first argument is a valid number
			ValidateCreate validateNumber("default_wallet",arguments[k]);
			bool flag2 = validateNumber.IsValidNumber();
			// if true
			if (flag2 == true)
			{
				//check second argument
				if ((arguments[k+1]=="-c")
					||(arguments[k+1]=="--category")
					||(arguments[k+1]=="-w")
					||(arguments[k+1]=="--wallet"))
				{
					pozition = k;
					k = argc;
					flag = true;
				}
				//if second argument not valid print error
				else 
				{
					cout << "error: invalid parameters for '" 
					     << argv[1] 
					     << "'."
						 << endl;

					k = argc;
				}
			}
			//check if the 3 'th argument is a valid number
			else 
			{
				ValidateCreate validateNumber("default_wallet",arguments[2]);
				bool flag2 = validateNumber.IsValidNumber();
				k = 2;
				if (flag2 == true)
				{
					//if valid check first argument
					if ((arguments[k-2]=="-c")
						||(arguments[k-2]=="--category")
						||(arguments[k-2]=="-w")
						||(arguments[k-2]=="--wallet"))
					{
						pozition = k;
						k = argc;
						flag = true;
					}
					// else error
					else 
					{
						cout << "error: invalid parameters for '" 
						     << argv[1] 
						     << "'."
							 << endl;
						k = argc;
						
					}
				}
				// if not valid number print error
				else 
				{
					cout << "error: invalid parameters for '"
   					     << argv[1] 
					     << "'."
						 << endl;
					k = argc;
				}
			}	
		}
		//case we have 7 arguments EX: moneytracker income -c 
		//category -w wallet 200
		else if ((argc-3)==4)
		{
			ValidateCreate validateNumber("default_wallet",arguments[k]);
			bool flag2 = validateNumber.IsValidNumber();
			// check if first argument is valid
			if (flag2 == true)
			{	
				if ((arguments[k+1] != arguments[k+3])
					&&((arguments[k+1]=="-c")
					||(arguments[k+1]=="--category")
					||(arguments[k+1]=="-w")
					||(arguments[k+1]=="--wallet"))
					&&((arguments[k+3]=="-c")
				    ||(arguments[k+3]=="--category")
				    ||(arguments[k+3]=="-w")
				    ||(arguments[k+3]=="--wallet")))
				{	
					pozition = k;
					k = argc;
					flag = true;
				}
				//else print error
				else 
				{
					cout << "error: invalid parameters for '" 
					     << argv[1] 
						 << "'."
						 << endl;
					k = argc;
					
				}
			}
			//else if 3'th argument is valid number
			else 
			{
				ValidateCreate validateNumber("default_wallet",arguments[2]);
				bool flag2 = validateNumber.IsValidNumber();
				k = 2;
				//check if first argument and last ar valid commands
				if (flag2 == true)
				{
					if ((arguments[k-2] != arguments[k+1])&&
					((arguments[k-2]=="-c")
					||(arguments[k-2]=="--category")
					||(arguments[k-2]=="-w")
					||(arguments[k-2]=="--wallet"))
					&&((arguments[k+1]=="-c")
					||(arguments[k+1]=="--category")
					||(arguments[k+1]=="-w")
					||(arguments[k+1]=="--wallet")))
					{
						pozition = k;
						k = argc;
						flag = true;
					}
					//else print error
					else 
					{
						cout << "error: invalid parameters for '" 
						     << argv[1] 
							 << "'."
							 << endl;
						k = argc;
					}
				}
				//else check if last argument is a valid number
				else 
				{
					ValidateCreate validateNumber("default_wallet", arguments[4]);
					bool flag2 = validateNumber.IsValidNumber();
					k = 4;
					//check if argument on first and 3'th position ar valid
					if (flag2 == true)
					{
						if ((arguments[k-2] != arguments[k-4])
						&&((arguments[k-2]=="-c")
						||(arguments[k-2]=="--category")
						||(arguments[k-2]=="-w")
						||(arguments[k-2]=="--wallet"))
						&&((arguments[k-4]=="-c")
						||(arguments[k-4]=="--category")
						||(arguments[k-4]=="-w")
						||(arguments[k-4]=="--wallet")))
						{
							pozition = k;
							k = argc;
							flag = true;
						}
						//else print error
						else 
						{
							cout << "error: invalid parameters for '" 
							     << argv[1] 
								 << "'."<<endl;
							k = argc;
						}
					}
					//else if not valid print error
					else 
					{
						cout << "error: invalid parameter for '" 
						     << argv[1] 
							 << "'."
							 << endl;
						k = argc;
										
					}
				}
			}		
		}
		//else not a valid command
		else 
		{
			cout << "error: invalid parameters for '" 
			     << argv[1] 
				 << "'."
				 << endl;
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
				newWallet.AddLineInWalletFile(amount, incomeOrSpend, category 
				,wallettt);
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

