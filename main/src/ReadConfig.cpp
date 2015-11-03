//Co-authors - Andreea Stan, Tudor Chibulcutean, v0.2

#include "ReadConfig.h"

#include <string>
#include <iostream>
#include <PrintError.h>
#include "Types.h"
#include <cstdio>
#include <algorithm>

//implementation of GetDefaultWallet
std::string ReadConfig::GetDefaultWallet(std::string &contentConfigFile, std::string &checkVariable)
{
	//the value returned by ReturnFileasString is transfered to string content
	//std::string content = ReturnFileasString();
	std::string checkVariablePlusEqual = checkVariable + "=";
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
		if(content.find(checkVariable) == std::string::npos)
				return "NoDefaultWalletFound";	
		//else return the name of the default wallet
		else 
		{
			
			// create a variable string for manipulate the content 
			std:: string workContent = content;
			size_t beginNextLine=0;
			// create a variable string for manipulate the lines from content 
			std::string workLine;
			size_t lineNumber = 1;
			bool flag = false;
			// create a variable string for comparing the string 
			//with the elements from config
			std::string defaultCheck;
			for (size_t j=0;j<=workContent.length()+1;j++)
			{	
				//move to pozition '\n' or end of string
				 if ((workContent[j] == '\n')||(j==workContent.length()))
				{
					// obtain the line
					workLine = workContent.substr(beginNextLine,j-beginNextLine);
					
					// if we don't find the string in the line then count the line
					if ( workLine.find(checkVariable) == std::string::npos)
					{
						 ++lineNumber;
					}
					else 
					{
						// erase space and tabs ;
						workLine.erase(std::remove(workLine.begin(),workLine.end(),' '),workLine.end());
						workLine.erase(std::remove(workLine.begin(),workLine.end(),'\t'),workLine.end());
						
						// obtain the string for comparing
						defaultCheck = workLine.substr(0,workLine.find('=')); 
						if (defaultCheck == checkVariable)
						{
							flag =true;
							break;
						}
						else 
						{
							// if we didn't find the exact string count the line
							++lineNumber;
						} 
					}
					// initializate the pozition for the begining of next line
					beginNextLine = j+1; 
				}
			}
			// if we found the exact string in config
			if (flag == true)
			{
				workContent.erase(std::remove(workContent.begin(),workContent.end(),' '),workContent.end());
				workContent.erase(std::remove(workContent.begin(),workContent.end(),'\t'),workContent.end());
				size_t pozitionAfterSignEqual = 0;
				size_t pozitionSignNextLine = 0;
				size_t countLineNumbers = 0;
				for (size_t j=0; j<=content.length()+1; j++)
				{
					// check pozition for =
					if (workContent[j] == '=') 
					{
						pozitionAfterSignEqual = j+1;
					}
					// check pozition for '\n' or and of content
					else if ((workContent[j] == '\n')||(j==workContent.length()))
					{
						pozitionSignNextLine = j;
						//cout the lines
						++countLineNumbers;
					}
					if (lineNumber == countLineNumbers)
					{
						break;
					}
				}
				std::string walletName = workContent.substr(pozitionAfterSignEqual,pozitionSignNextLine-pozitionAfterSignEqual);
				if (walletName.length() == 0)
				{
					return "NoWalletNameFound";
				}
				else 
				{
					return walletName;
				}
			}
			else 
			{
				return "NoDefaultWalletFound";
			}
		}

	}	
}