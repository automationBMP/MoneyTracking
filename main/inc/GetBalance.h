#ifndef GETBALANCE_H
#define GETBALANCE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
// class getbalance returns the balance
class GetBalance
{
	private:
		double balance;
		bool categoryExists;
	public:
		std::string PrintBalance(std::string &content, std::string category);
		bool CategoryExists();
};



#endif