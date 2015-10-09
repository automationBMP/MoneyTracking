#include <iostream> 
#include <cstring>
#include "C:\learn\MoneyTracking\main\inc\DoCreateWallet.h" 
#include "C:\learn\MoneyTracking\main\inc\ValidateCreate.h"
#include "C:\learn\MoneyTracking\main\inc\MainFunctions.h"
using namespace std;

int main(int argc, char* argv[]) { 

	// check if we have enough arguments
	bool flag2=checkArgc(argc);
	//cout << argc <<endl;
	
	if (flag2==true) 
	{	//check if we have 3 arguments
		if (argc == 3) 
		{
			// element nr 2 on pozition 1 
			int nrArg = 2;
			// convert =argv[1] in string
			string stringArgumentNr2(argv[nrArg-1]);
			if (stringArgumentNr2 == "create") 
			{
				// element nr 3 on pozition 2 
				int nrArg = 3;
				// convert =argv[2] in string
				string 	stringArgumentNr3(argv[nrArg-1]);
				// convert path
				string convert = convertPath(stringArgumentNr3);
				//create object of class ValidateCreate
				ValidateCreate validate(convert);
				//return bool if wallet exist
				bool flag =validate.WalletExists();
				if (flag == false) 
					{
					//default amount = 00.00;
					string amount = "+00.00";
					//recreate path to initial 
					string convert2 = convertPathToOriginal(convert);
					//apeal function create new wallet with amount 00.00
					DoCreateWallet newWallet(convert2,amount);
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
					string convert = convertPath(stringArgumentNr3);
					// convert =argv[3] in string
					string 	stringArgumentNr4(argv[nrArg]);
					//create object of class ValidateCreate
					ValidateCreate validate1(convert,stringArgumentNr4);
					//cout << convert << endl;
					//return bool if wallet exist
					bool flag = validate1.WalletExists();
					if (flag == false) 
					{
						bool flag1 = validate1.IsValidNumber();
						if (flag1 == true)
						{
							//recreate path to initial 
							string convert2 = convertPathToOriginal(convert);
						    //apeal function create new wallet 
							DoCreateWallet newWallet(convert2,stringArgumentNr4);
							newWallet.CreateWalletFile();
						}
					}						
				}
			}		
	}
   
   return 0; 
}
