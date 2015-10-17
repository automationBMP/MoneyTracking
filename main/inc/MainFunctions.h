#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H
#include <string>


// validate nr of arguments return true if we have enough arguments
bool CheckArgcNumbers(int argc,std::string argument);

// convert path  Ex: C:\learn in C:/learn for validating 
// returns the convert path
std::string ConvertPath(std::string givenPath);

// reconvert path to original
// returns the original path
std::string ConvertPathToOriginal(std::string givenPath);

//function read config file
// returns all content of file
std::string ReturnFileasString();
#endif