#pragma once
#pragma once
#include <string>
#include "driver_interface.h"

class AutoTradingSystem {
public:
	void selectStockBrocker(StockBrockerDriver* driver);
	void login(std::string ID, std::string password);
    void buy(std::string stockCode, int price, int count);

	void sell(std::string stockCode, int price, int count);

private:
	StockBrockerDriver* driver;
	bool checkBuyPrerequisite(int price, int count);
};

class BrockerFinder {
public:
	virtual StockBrockerDriver* getStockBrocker(std::string brokername);
};