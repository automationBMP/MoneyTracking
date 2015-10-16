//Co-authors - Andreea Stan, Tudor Chibulcutean, v0.2

#include "ReadConfig.h"

#include <fstream>
#include <string>
#include <iostream>

//implementation of ReturnFileasString
std::string ReadConfig::ReturnFileasString()
{
	//read moneytracker.config file
	std::ifstream ifs("C:\\learn\\MoneyTracking\\moneytracker.config");
	
	//the content of moneytracker.config is transfered to string content
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	
	std::cout << content <<std::endl;
	return content;
}

//implementation of GetDefaultWallet
std::string ReadConfig::GetDefaultWallet()
{
	//the value returned by ReturnFileasString is transfered to string content
	std::string content = ReturnFileasString();
	
	//if no default wallet is found an empty string is returned
	if(content.find("default_wallet") == std::string::npos)
        return "Error";
	
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
			return "";
		}
	}
}