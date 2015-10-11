#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H
#include <string>


// validate nr of arguments return true if we have enough arguments
bool CheckArgcNumbers(int argc);

// convert path  Ex: C:\learn in C:/learn for validating 
// returns the convert path
std::string ConvertPath(std::string givenPath);

// reconvert path to original
// returns the original path
std::string ConvertPathToOriginal(std::string givenPath);

#endif