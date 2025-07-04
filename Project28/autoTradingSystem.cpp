#include "autoTradingSystem.h"

using std::string;

void AutoTradingSystem::selectStockBrocker(StockBrockerDriver* _driver) {
	driver = _driver;
}


StockBrockerDriver* BrockerFinder::getStockBrocker(string brokername) {
	if (brokername == "kiwer") {
		return new KiwerDriverInterface(); //TBD, API
	}

	if (brokername == "nemo") {
		return new NemoDriverInterface(); //TBD, API
	}
}

void AutoTradingSystem::buy(std::string stockCode, int price, int count) {
	if (false == checkBuyPrerequisite(price, count)) {
		return;
	}
	driver->buy(stockCode, price, count);
}

bool AutoTradingSystem::checkBuyPrerequisite(int price, int count) {
	if (price <= 0 || count <= 0) return false;
}
