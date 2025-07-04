#pragma once
#pragma once
#include <string>
#include <vector>
#include "driver_interface.h"

class AutoTradingSystem {
public:
	void selectStockBrocker(StockBrockerDriver* driver);
	void login(std::string ID, std::string password);
	void buy(std::string stockCode, int price, int count);
	int buyNiceTiming(std::string stockCode, int price);

private:
	StockBrockerDriver* driver;
	bool checkBuyPrerequisite(int price, int count);

	static const int MAX_BUY_COUNT;
};

class BrockerFinder {
public:
	virtual StockBrockerDriver* getStockBrocker(std::string brokername);
};