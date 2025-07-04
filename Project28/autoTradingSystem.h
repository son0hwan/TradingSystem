#pragma once
#include <string>
#include "driver_interface.h"

class AutoTradingSystem {
public:
	void selectStockBrocker(TradingDriverAPI* driver);

	
private:
	TradingDriverAPI* driver;
};

class BrockerFinder {
public:
	virtual TradingDriverAPI* getStockBrocker(std::string brokername);
};