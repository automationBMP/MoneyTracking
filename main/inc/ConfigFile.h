//Author: Andrei Martinescu, v0.2
#ifndef CHANGECONFIG_H
#define CHANGECONFIG_H

#include <string>

class ConfigFile
{

private:
	//Config_E EnumPos_m;
	ConfigFile();
	std::string content_m;
	std::string change_m;
	std::string default_change_m;
	std::string default_wallet_m;
	std::string default_currency_m;
	std::string default_income_category_m;
	std::string default_spending_category_m;
	std::string currencies_m;
	std::string rate_EUR_RON_m;
	std::string rate_RON_EUR_m;
	std::string rate_USD_RON_m;
	std::string rate_EUR_USD_m;

public:
	ConfigFile (std::string &content, std::string &default_change, std::string &change);
	std::string ChangeConfigFile();
	void ReWriteConfigFile();
	

};
std::string ReturnDefaultNoUnderLine(std::string &change);

#endif