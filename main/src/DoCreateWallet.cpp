/*
	Author: Miau
	
	This file contains the implementation for the DoCreateWalet class
	
*/

#include "DoCreateWallet.h"
#include "PrintError.h"
#include "Types.h"
#include <string>
#include <sys/stat.h>
#include <unistd.h> 
#include <fstream>
#include <iostream>
#include <ctime>
#include "MainFunctions.h"
#include "ReadConfig.h"

using namespace std;

DoCreateWallet::DoCreateWallet( std::string walletName,
								std::string defaultAmount):	
									walletName_m(walletName),
									defaultAmount_m(defaultAmount)
	{}

Error_E DoCreateWallet::CreateWalletFile()
{	
	//apeal function add decimals
	string returnAmount=DoCreateWallet::AddDecimalsToDefaultAmount();
	defaultAmount_m=returnAmount;
	// creating and opening the file
	ofstream walletFile(walletName_m.c_str());
	//adding the sign if is missing
	if (defaultAmount_m[0] != '+' && defaultAmount_m[0] != '-')
	{
		defaultAmount_m = '+' + defaultAmount_m;
	}
	// removing the starting 0's if an amount is given
	if (defaultAmount_m != "+00.00" )
	{
		DoCreateWallet::RemoveStartingZeroes();
	}
	//checking if the file was created
	if (!walletFile.good())
	{
		PrintError::Print(PATH_DOES_NOT_EXIST,
						walletName_m,
						defaultAmount_m);
		return PATH_DOES_NOT_EXIST;
	}
	// removing the starting 0's if an amount is given
	if (defaultAmount_m != "+00.00" )
	{
		DoCreateWallet::RemoveStartingZeroes();
	}
	// writing the initial amount in the wallet file
	walletFile << defaultAmount_m << " RON";
	if (!walletFile.good())
	{
		PrintError::Print(WRITE_TO_FILE,
						walletName_m,
						defaultAmount_m);
		return WRITE_TO_FILE;
	}
	// closing the file
	walletFile << endl;
	walletFile.close();
	//printing the wallet created message
	PrintError::Print(CREATE_WALLET_MESSAGE,
						walletName_m,
						defaultAmount_m);
	return ALL_GOOD;
}

Error_E DoCreateWallet::AddLineInWalletFile(string &amount, string &ArgNr2, string &category, string &wallet)
{	
	//apeal function add decimals
	amount=DoCreateWallet::AddDecimalsToDefaultAmount();
	defaultAmount_m = amount;
	//create variable for epoch time
	time_t result = time(0);
	//converting epoch time in text
	char buffer [80];
	struct tm *tmp;
	tmp = gmtime(&result);
	strftime (buffer,80,"Transaction time: %a, %d %b %Y %X",tmp);
	string printline;
	//check if we have sign + before number
	if (defaultAmount_m[0] == '+')
		{
		defaultAmount_m = defaultAmount_m.substr(1,defaultAmount_m.length()-1);
		}
	else defaultAmount_m = defaultAmount_m.substr(0,defaultAmount_m.length());
	// if argument ArgNr2 is income 
	if (ArgNr2 == "income") 
		{	
			if (wallet.length() == 0) 
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
			cout << "Income '" << category << "' in an amount of " 
			     << defaultAmount_m << " RON was registered to " << "'"<<walletName<< "'."<<endl;
			cout << buffer << " GMT" << endl;
			}
			else 
			{
				cout << "Income '" << category << "' in an amount of " 
			     << defaultAmount_m << " RON was registered to " << "'"<<wallet<< "'."<<endl;
			cout << buffer << " GMT" << endl;
			}
			printline += printline + ";" + "+" + ";" 				
					     + defaultAmount_m +";" +category + ";"+ "RON";
		}
	// if argument ArgNr2 is spend
	else if (ArgNr2 == "spend") 
		{
			if (wallet.length() == 0) 
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
			cout << "Spending '" << category << "' in an amount of " 
			     << defaultAmount_m << " RON was registered to " << "'"<<walletName<< "'."<<endl;
			cout << buffer << " GMT" << endl;
			}
			else 
			{
				cout << "Spending '" << category << "' in an amount of " 
			     << defaultAmount_m << " RON was registered to " << "'"<<wallet<< "'."<<endl;
			cout << buffer << " GMT" << endl;
			}
			printline += printline+";" + "-" + ";" 
						 + defaultAmount_m +";" + category + ";"+ "RON";
		}
	ofstream myfile (walletName_m.c_str(),ios::app);
	if (myfile.is_open())
	{
	myfile << result;
	myfile << printline;
	myfile << endl;
    myfile.close();
	}
	return ALL_GOOD;
}

string DoCreateWallet::AddDecimalsToDefaultAmount()
{

	int pointPosition = -1;
	int i = 0;
	// searching for the position of the '.'
	do
	{
		if (defaultAmount_m[i] == '.')
		{
			pointPosition = i;
			i = defaultAmount_m.length() + 1;
		}
		++i;
	}while (i < (int)defaultAmount_m.length());
	
	// if no point is present
	if (pointPosition == -1)
	{
		defaultAmount_m += ".00";
	}
	// if point is first caracter
	/*if (pointPosition == 0)
	{
		defaultAmount_m = "0" + defaultAmount_m;
	}*/
	
	//if the '.' is the last character
	if (pointPosition == (int)defaultAmount_m.length() - 1)
	{
		defaultAmount_m += "00";		
	}
	//if one decimal exists after the '.' character
	if (pointPosition == (int)defaultAmount_m.length() - 2)
	{
		defaultAmount_m += "0";
	}
	//if more then 2 decimals exists
	
	if (pointPosition == (int)defaultAmount_m.length() - 4)
	{
		unsigned int lastDecimal = defaultAmount_m[pointPosition + 3];
		defaultAmount_m[defaultAmount_m.length() - 1] = ' ';
		i = pointPosition + 2;
		
		if (lastDecimal > 52)
		{
			// changing the 9's to 0's after the .
			while (defaultAmount_m[i] == '9')
			{
				defaultAmount_m[i] = '0';
				--i;
			}
			if (defaultAmount_m[i] == '.')
			{
				//changig the 9's before the .
				--i;
				while (defaultAmount_m[i] == '9')
				{
					defaultAmount_m[i] = '0';
					--i;
				}
				
				//if the number had only 9's and no sign, a 1 will be added
				if (i == -1)
				{
					defaultAmount_m = "1" + defaultAmount_m;
					
				}else 
				//if the number had only 9's and a sign, a 1 will be added
				if ((i == 0) && 
								((defaultAmount_m[0] == '+') || 
								(defaultAmount_m[0] == '-') ))
				{
					defaultAmount_m = defaultAmount_m[0] + defaultAmount_m;
					defaultAmount_m[1] = '1';
				}else
				//adding 1 to the proper digit after the .
				{
					++defaultAmount_m[i];
				}
			}else
			// adding 1 to the proper digit before the .
			{
				++defaultAmount_m[i];
			}			
		}		
	}	
	// checking if last item of string is ' ' and delete
	if (defaultAmount_m[defaultAmount_m.length() - 1] == ' ') 
	{
		defaultAmount_m = 
				defaultAmount_m.substr(0,defaultAmount_m.length() - 1);
	}
	return defaultAmount_m;
}

// removing the 0's from the begining
string DoCreateWallet::RemoveStartingZeroes()
{
	unsigned int start = 0, i = 0;
	char sign ;
	//searching for an existing sign
	if (defaultAmount_m[0] == '+' || defaultAmount_m[0] == '-')
	{
		sign = defaultAmount_m[0];
		start = 1;
		i = start;
		// counting the start 0's
		while (defaultAmount_m[i] == '0')
		{
			++i;
		}
		// case : 000.7
		if ((defaultAmount_m[i] == '.') && (i < defaultAmount_m.length()))
		{
			defaultAmount_m = 
				defaultAmount_m.substr (i-1,defaultAmount_m.length()-i+1);

		}
		//case : 001
		else if (i < defaultAmount_m.length())
		{
			defaultAmount_m = 
				defaultAmount_m.substr (i,defaultAmount_m.length()-i);
		}
		//case: 0000
		else 
		{
			defaultAmount_m = 
				defaultAmount_m.substr (i-1,defaultAmount_m.length()-i+1);
		}
		if (defaultAmount_m != "0") 
		{
		return defaultAmount_m = sign + defaultAmount_m;
		}
		else return "0";

	}else 
		{
			start = 0;
			i = start;
			// counting the start 0's
			while (defaultAmount_m[i] == '0')
			{
			++i;
			}
			// case : 000.7
			if ((defaultAmount_m[i] == '.') && (i < defaultAmount_m.length()))
			{
				defaultAmount_m = 
					defaultAmount_m.substr (i-1,defaultAmount_m.length()-i+1);

			}
			//case : 001
			else if (i < defaultAmount_m.length())
			{
				defaultAmount_m = 
					defaultAmount_m.substr (i,defaultAmount_m.length()-i);
			}
			//case: 0000
			else 
			{
				defaultAmount_m = 
					defaultAmount_m.substr (i-1,defaultAmount_m.length()-i+1);
			}		
		}
		if (defaultAmount_m != "0") 
		{
			defaultAmount_m = "+" + defaultAmount_m;
		}
	return defaultAmount_m;
}