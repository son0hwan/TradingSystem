#pragma once
#pragma once
#include <string>
#include "driver_interface.h"

class AutoTradingSystem {
public:
	void selectStockBrocker(StockBrockerDriver* driver);
    void buy(std::string stockCode, int price, int count);

private:
	StockBrockerDriver* driver;
	bool checkStockTradePrerequisite(std::string stockCode, int price, int count);
};

class BrockerFinder {
public:
	virtual StockBrockerDriver* getStockBrocker(std::string brokername);
};