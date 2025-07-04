#include "autoTradingSystem.h"

using std::string;

void AutoTradingSystem::selectStockBrocker(StockBrockerDriver* _driver) {
	driver = _driver;
}

int AutoTradingSystem::getPrice(std::string stockCode) {
	return driver->getPrice(stockCode);
}

StockBrockerDriver* BrockerFinder::getStockBrocker(string brokername) {
	if (brokername == "kiwer") {
		return new KiwerDriverInterface(); //TBD, API
	}

	if (brokername == "nemo") {
		return new NemoDriverInterface(); //TBD, API
	}
}