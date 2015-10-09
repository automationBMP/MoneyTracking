#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H
#include <string>


// validate nr of arguments
bool checkArgc(int argc);

// convert path  Ex: C:\learn in C:/learn for validating
std::string convertPath(std::string givenPath);

// reconvert path to original
std::string convertPathToOriginal(std::string givenPath);

#endif