#include "autoTradingSystem.h"

using std::string;

void AutoTradingSystem::selectStockBrocker(TradingDriverAPI* _driver) {
	driver = _driver;
}


TradingDriverAPI* BrockerFinder::getStockBrocker(string brokername) {
	if (brokername == "kiwer") {
		return new KiwerDriverInterface(); //TBD, API
	}

	if (brokername == "nemo") {
		return new NemoDriverInterface(); //TBD, API
	}
}