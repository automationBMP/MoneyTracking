/*
	Author: Miau
	
	This file contains the implementation for the DoCreateWalet class
	
*/

#include "..\inc\DoCreateWallet.h"
#include "..\inc\PrintError.h"
#include "..\inc\Types.h"
#include <string>
#include <cstring>
#include <sys/stat.h>
#include <unistd.h> 
#include <fstream>
#include <iostream>

using namespace std;

DoCreateWallet::DoCreateWallet( std::string walletName,
								std::string defaultAmount):	
									walletName_m(walletName),
									defaultAmount_m(defaultAmount)
	{}

Error_E DoCreateWallet::CreateWalletFile()
{	
	
	string returnAmount=DoCreateWallet::AddDecimalsToDefaultAmount();
	defaultAmount_m=returnAmount;
	//DoCreateWallet::AddDecimalsToDefaultAmount)()
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
	walletFile << "\n";
	// closing the file
	walletFile.close();
	//printing the wallet created message
	PrintError::Print(CREATE_WALLET_MESSAGE,
						walletName_m,
						defaultAmount_m);
	return ALL_GOOD;
}

string DoCreateWallet::AddDecimalsToDefaultAmount()
{

	unsigned int pointPosition = 0;
	int i = 0;
	// searching for the position of the '.'
	do
	{
		
		if (defaultAmount_m[i] == '.')
		{
			pointPosition = i;
			//i = defaultAmount_m.length() + 1;
		}
		++i;
	}while (i < defaultAmount_m.length());
	
	// if no point is present
	if (pointPosition == 0)
	{
		defaultAmount_m += ".00";
	}
	
	//if the '.' is the last character
	if (pointPosition == defaultAmount_m.length() - 1)
	{
		defaultAmount_m += "00";
		//cout << defaultAmount_m << endl;
		
	}
	//if one decimal exists after the '.' character
	if (pointPosition == defaultAmount_m.length() - 2)
			{
		defaultAmount_m += "0";
		//cout << defaultAmount_m << endl;
		
	}
	//if more then 2 decimals exists
	
	if (pointPosition == defaultAmount_m.length() - 4)
	{
		unsigned int lastDecimal = defaultAmount_m[pointPosition + 3];
		//cout << "\n lastDecimal = " << lastDecimal;
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
std::string DoCreateWallet::RemoveStartingZeroes()
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

	}//case : 001
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
	}else return "0";
	
	//return defaultAmount_m;
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

		}//case : 001
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
			//defaultAmount_m =sign+defaultAmount_m;
			//return defaultAmount_m;		
		}
		if (defaultAmount_m != "0") 
		{
			defaultAmount_m = "+" + defaultAmount_m;
		}
		
	return defaultAmount_m;
}