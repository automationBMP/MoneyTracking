#include <iostream> 
#include <cstring>
#include "C:\learn\MoneyTracking\main\inc\DoCreateWallet.h" 
#include "C:\learn\MoneyTracking\main\inc\ValidateCreate.h"

using namespace std;
bool checkArgc(int argc);
//string  createArg(int nrArg,string argvNr);

string convertPath(string givenPath);
string fileName(string givenPath);

int main(int argc, char* argv[]) { 

	// check if we have enough arguments
	bool flag2=checkArgc(argc);
	//cout << argc <<endl;
	
	if (flag2==true) 
	{	//check if we have 3 arguments
		if (argc == 3) 
		{
			// pozition 2 
			int nrArg = 2;
			// convert =argv[1] in string
			string stringArgumentNr2(argv[nrArg-1]);
			if (stringArgumentNr2 == "create") 
			{
				// pozition 3
				int nrArg = 3;
				// convert =argv[2] in string
				string 	stringArgumentNr3(argv[nrArg-1]);
				// convert path
				string convert=convertPath(stringArgumentNr3);
				//create object of class ValidateCreate
				ValidateCreate validate(convert);
				//return bool if wallet exist
				bool flag =validate.WalletExists();
				if (flag == false) 
					{
					//default ammount = 00.00;
					string ammount = "+00.00";
					//apeal function create new wallet with ammount 00.00
					DoCreateWallet newWallet(convert,ammount);
					newWallet.CreateWalletFile();
					}
			
			}
		}
		//check if we have 4 arguments
		else if (argc == 4) 
			{
				// pozition 2 
				int nrArg = 2;
				// convert =argv[1] in string
				string stringArgumentNr2(argv[nrArg-1]);
				if (stringArgumentNr2 == "create") 
				{
					// pozition 3
					int nrArg = 3;
					// convert =argv[2] in string
					string 	stringArgumentNr3(argv[nrArg-1]);
					// convert path
					string convert=convertPath(stringArgumentNr3);
					//create object of class ValidateCreate
					string ammount = "00.00";
					// convert =argv[3] in string
					string 	stringArgumentNr4(argv[nrArg]);
					// convert path
					string convert1=convertPath(stringArgumentNr4);
					ValidateCreate validate1(convert,convert1);
					//return bool if wallet exist
					bool flag =validate1.WalletExists();
					if (flag == false) 
					{
						bool flag1 = validate1.IsValidNumber();
						if (flag1 == true)
						{
							//apeal function create new wallet with ammount 00.00
							DoCreateWallet newWallet(convert,convert1);
							newWallet.CreateWalletFile();
						}
					}						
				}
			}		
	}
   
   return 0; 
}

bool checkArgc(int argc)
{
	bool flag = true ;
	
		if (argc <= 2) 
		{
			cout << "error: at least filename should be specified. ";
			flag =false;
		}
	return flag;	
}

string convertPath(string givenPath)
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



string convertPathtoOriginal(string givenPath)
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

/* function return fileName from path
string FileName(string givenPath)
{  string fileName; 

	for(unsigned int i = givenPath.length(); i >0; i--)
	{
		if(givenPath[i] == '/')
		{	
			for (unsigned int j = i+1; j < givenPath.length(); j++)
			{	
			fileName+=givenPath[j];
			}
			break;
			//cout << fileName;
		}
	}
	return fileName;
	
//return givenPath;	
	
}*/

