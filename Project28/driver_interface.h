#pragma once
#include <string>

class TradingDriverAPI {
public:
	virtual void login(std::string ID, std::string password) = 0;

	virtual void buy(std::string stockCode, int count, int price) = 0;

	virtual void sell(std::string stockCode, int count, int price) = 0;

	virtual int getPrice(std::string stockCode) = 0;
};

