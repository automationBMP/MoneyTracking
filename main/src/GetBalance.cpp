//this function should get the string from file as a parameter 
//and return balance
#include <string>
#include "GetBalance.h"
using namespace std;

bool GetBalance::CategoryExists()
{
	return categoryExists;
}

string GetBalance::PrintBalance(std::string &content, std::string category)
{
	categoryExists = false;
    double balance = 0.00;
	double balanceCategory = 0.00;
	double result;	
	string ss;
	
	//get the first line containing the initial amount and sign
	ss = content.substr(0,content.find("\n"));
	
	//divide sign from amount
	string amountsign = ss.substr(0,1);
	string amount = ss.substr(1, content.length());

	
	//initialize balance with the amount the wallet is created
	if (amountsign == "+")
		{
			balance = balance + atof(amount.c_str());
		}
	else
		{
			balance = balance - atof(amount.c_str());
		}
		
	//get the content without the first line	
	content = content.substr(content.find("\n")+1, std::string::npos);

	//s1 will take a line from the file
	string s1 = "";
	
	while (content.length()>2)
		{ 
			//get the first line from the string
			s1 = content.substr(0,content.find("\n"));	
			content = content.substr(content.find("\n")+1, std::string::npos);
					
			// get the content of file without epochTime
			s1 = s1.substr(s1.find(';') + 1, std::string::npos);
	
			// get the sign
			std::string sign = s1.substr(0, s1.find(";"));
		
			// get the content of file without epochTime and sign
			s1 = s1.substr(s1.find(';') + 1, std::string::npos);

			// get the amount
			std::string amount1 = s1.substr(0, s1.find(";"));
			//get the content of the file without epoch time, sign, amount
			s1 = s1.substr(s1.find(';') + 1, std::string::npos);
			
			// get the category
			std::string categoryInWallet = s1.substr(0, s1.find(";"));
			
			//convert amount from string into double
			result = atof(amount1.c_str());
			
			//calculate the balance for a certain category
			if (categoryInWallet == category)
			{
				categoryExists = true;
				
				//calculate balance
				if (sign == "+") 
				{
					balanceCategory = balanceCategory + result;
				}
				else
				{
					balanceCategory = balanceCategory - result;
				}
			}
			
			//calculate balance
			if (sign == "+")
				{
					balance = balance + result;
				}
			else
				{
					balance = balance - result;
				}
		}

	//convert duble balance to string balance
	
	if (categoryExists == true)
	{
		balance = balanceCategory;
	}
	
	stringstream convert; 
	convert << balance;
	
	string stringbalance;
	stringbalance = convert.str();
	
	//get the sign of balance: if it is - or no sign
	string balancesign = stringbalance.substr(0,1);
	if (balancesign != "-")
		{
			stringbalance = "+"+stringbalance;
		}
	//cout<<"the balance is: "<<stringbalance<<endl;
	return stringbalance;
}
