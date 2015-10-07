#GitHub learning experience

##Configure coding guideline


--------------------------------------------------------------------------------

###1. Identation 
	
	- using one Tab 
	
	- max length for each line 80 (nr of columns)
	
	- space between operators 
		Ex: int num = 0;
		
	- no space inside implementation near () 
		Ex: (a > b)
		
	- apeal functions , no space between "namefunction" and () 
		Ex: function();
		
	- before , no space 
		Ex: TicTacToe(firstPlayer), winx(0), winy(0)
		
	- after , single space
		Ex: TicTacToe(firstPlayer), winx(0), winy(0)
	
	- a space should be added before any for, if, while statements and the ()
		Ex: if (a > b)
		
	- access specifier has no identation same as class
		Ex:	class XOScored : public TicTacToe
			{ 
			private:
						
	- new line after each block of function 
		Ex:	TicTacToe(firstPlayer), winx(0), winy(0)
			{
			}
		
			void print()
			{
			cout << "GAME_WON_BY_X = " << winx << "\t" << "GAME_WON_BY_O" 
				<< winy << endl;
			}
	
	
###2. Identation for {}

	- each brackets on new line 
		Ex:	void print()
			{
			cout << "GAME_WON_BY_X = " << winx << "\t" << "GAME_WON_BY_O" 
				 << winy << endl;
			}
		
	- identation same as function
		Ex:	void print()
			{
			cout << "GAME_WON_BY_X = " << winx << "\t" << "GAME_WON_BY_O" 
				 << winy << endl;
			}
	
	
###3. Naming conventions 

	- local variables : lovercase first letter, UPPERCASE for the first letter 
      of another word in name 
        Ex:  variableName 
                              
    - const variables : all name UPPERCASE and _C at the end of name
        Ex: const int MAX_C
                              
    - class, method and function name : first letter UPPERCASE ,UPPERCASE for 
      the first letter of every other word
        Ex:class LargeTree, void PrintTheResult(), bool IsConditionTrue()
                              
    - the function name will be a verb followed by a noun
        Ex: PrintTheResult()
                              
    - enum name : first letter UPPERCASE, UPPERCASE for first letter of
      other words in the name and _E at the end of name
        Ex: EnumType_E
                              
    - enum members : all letters UPPERCASE 
        Ex : NAME_MEMBER
                                           
    - class variable member : the first letter should be lowercase, the other 
      words should begin with uppercase and _m at the end of the name
        Ex: classVariable_m
                 
    - class accessors and mutators : Get or Set followed by the desired variable
        Ex: int varName;
            int GetVarName();
               
    - member method call in the class : name of class and ::
        Ex: ClassName::ClassMethod()

	- initialization of each variable in declaration , and closer to the scope 
	  of usage
		Ex: for (int i = 0; i < 100; i++)
	  
	- initialization of variable members class in default Constructor
		Ex: TicTacToe(firstPlayer), winx(0), winy(0)
	
	- declaration of pointer or reference simbols, near type of variable with no 
	  space
		Ex: TicTacToeImpl* implTic_p;
	  
	- name of pointers : lovercase first letter, UPPERCASE for first letter of
	  another word in name and _p at the end of name
		Ex: TicTacToeImpl* implTic_p;

	  
###4. Commenting

	- the beginning of each file should contain the author and the version of 
	  implementation 
		Ex: //Andreea Stan, v1.2
		
	- before each statement if needed
		Ex: //declare something
			char variable = 'a';
  
			// call a function
			FunctiontoCall();
			
	- comments in headers for functions
		Ex: //Get who should make the next move
			int GetNextPlayer();
			
			//Check if game is over
			bool IsGameOver();
			
	- with // or /* */ for block comments
		Ex: //Check something
			bool Something();
			
			/*
			Returns the board as string
			Endl at the end of each row, space after each field.
			Ex:
			"1 2 3 \n
			 4 5 6 \n
			 7 8 9 \n"
			*/
			std::string GetBoard();
			
	- comments should be included relative to their position in code
		Ex: //Check something
			bool Something();
			
			while(true)
			{
			// do something
			something();
			}
	

###5. Declaration

	- C++ header files should have the extension .h and source files the 
	  extension .cpp
		Ex: MyClass.h, MyClass.cpp
		
	- a class should be declared in a header file and defined in a source file
      where the name of the files match the name of the class
		Ex: MyClass.h, MyClass.cpp
		
	- the name of each block of functions should represent its functionality
		Ex: CurrencyExchange.cpp contains:  ConvertYentoEuro();
											ConvertEurotoRon();
											ConvertPoundtoDollar();
											ConvertDollartoEuro();
											
	- ifndef + name of file _H at the end
		Ex: #ifndef MYCLASS_H
			#define MYCLASS_H
			
	- source files in "src" folder
	
	- include files in "inc" folder
	
###6. All rights rezerved , Team Viscacha


![example image](https://i.imgur.com/3NhecgQ.jpg "An exemplary image") 

	
	