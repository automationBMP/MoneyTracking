//Co-authors - Andreea Stan, Tudor Chibulcutean, v0.2

#ifndef READCONFIG_H
#define READCONFIG_H

#include <string>

class ReadConfig
{
public:
	//std::string ReturnFileasString();
	std::string GetDefaultWallet(std::string &contentConfigFile, std::string &checkVariable);
};



#endif