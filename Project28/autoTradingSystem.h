#pragma once
#pragma once
#include <string>
#include "driver_interface.h"

class AutoTradingSystem {
public:
	void selectStockBrocker(StockBrockerDriver* driver);
	int getPrice(std::string stockCode);

private:
	StockBrockerDriver* driver;
};

class BrockerFinder {
public:
	virtual StockBrockerDriver* getStockBrocker(std::string brokername);
};