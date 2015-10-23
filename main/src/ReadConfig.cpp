//Co-authors - Andreea Stan, Tudor Chibulcutean, v0.2

#include "ReadConfig.h"

#include <string>
#include <iostream>
#include <PrintError.h>
#include "Types.h"

//implementation of GetDefaultWallet
std::string ReadConfig::GetDefaultWallet(std::string &contentConfigFile)
{
	//the value returned by ReturnFileasString is transfered to string content
	//std::string content = ReturnFileasString();
	std::string content = contentConfigFile;
	if (content == "NotOpen") 
	{
		return content;
	}
	else if (content.length() == 0) 
	{
		//std::cout << "empty\n";
		// if content is zero than ifstream couldn't open config file
		return "EmptyConfig";//empty config or doesn't exist
	}
	else
	{
	//if (content.length() > 0) 
	//{
		//if no default wallet is found an empty string is returned
		if(content.find("default_wallet") == std::string::npos)
				return "NoDefaultWalletFound";	
		//else return the name of the default wallet
		else 
		{
			//get the position of "default_wallet"
			size_t defaultWalletPosition = content.find("default_wallet");
		
			//get the position of the new line character of the default_wallet line
			size_t endlinePosition = content.find("\n", defaultWalletPosition);
		
			//get the position after "default_wallet" 
			int i = defaultWalletPosition + 14;
		
			//skip spaces, tabs and equal sign until the first character from 
			//wallet name is found 
			while (content[i] == ' ' || content[i] == '\t' || content [i] == '=')
			{ 
				i++;
			}
		
			//if new line character is not reached return the name of the wallet
			if (content[i] != '\n')
			{
				int j = endlinePosition-1;
			
				//skip spaces, tabs and equal sign until the last character from 
				//wallet name is found 
				while (content[j] == ' ' || content[j] == '\t' || content [j] == '=')
				{ 
					j--;
				} 
			
				//calculates the length of the wallet name
				int lengthWallet = j - i; 
			
				//return the name of the wallet
				return content.substr (i, lengthWallet+1);	
			}
		
			//return an empty string if no wallet name is found
			else
			{
				return "NoWalletNameFound";
			}
		}
	}
	
}