/*
	Author: Miau
	
	This file contains the implementation for the DoCreateWalet class
	
*/

#include "..\inc\DoCreateWallet.h"

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

void DoCreateWallet::CreateWalletFile()
{
	// creating and opening the file
	ofstream walletFile(walletName_m.c_str());
	//checking if the file was created
	if (!walletFile.good())
	{
		cout << "\nError, the path dowsn't exist";
		return;
	}
	// writint the initial amount in the wallet file
	walletFile << defaultAmount_m << "  RON";
	if (!walletFile.good())
	{
		cout << "\nError, while writing in the file";
		return;
	}
	
	// closing the file
	walletFile.close();
	//printing the wallet created message
	cout 	<< "\n" 
			<< walletName_m 
			<< " created with the initial amount of "
			<< defaultAmount_m
			<< " RON";
}

void DoCreateWallet::AddDecimalsToDefaultAmount()
{
	unsigned int pointPosition = 0;
	int i = 0;
	// searching for the position of the '.'
	do
	{
		++i;
		if (defaultAmount_m[i] == '.')
		{
			pointPosition = i;
			i = defaultAmount_m.length() + 1;
		}
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
		cout << defaultAmount_m << endl;
		
	}
	//if more then 2 decimals exists
	cout << "\n i = " << i;
	cout << "\n pointPosition  " << pointPosition;
	if (pointPosition == defaultAmount_m.length() - 4)
	{
		unsigned int lastDecimal = defaultAmount_m[pointPosition + 3];
		cout << "\n lastDecimal = " << lastDecimal;
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
				cout << "\n i = " << i;
				//if the number had only 9's and no sign, a 1 will be added
				if (i == -1)
				{
					defaultAmount_m = "1" + defaultAmount_m;
					cout << "\n i = " << i;
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

		cout << "\n defaultAmount_m = " << defaultAmount_m;
		
	}	
}