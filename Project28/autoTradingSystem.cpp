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