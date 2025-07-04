#include "autoTradingSystem.h"

using std::string;

void AutoTradingSystem::selectStockBrocker(StockBrockerDriver* _driver) {
	driver = _driver;
}

void AutoTradingSystem::login(std::string ID, std::string password) {
	driver->login(ID, password);
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
	checkBuyPrerequisite(stockCode, price, count); 
	driver->buy(stockCode, price, count);
}

void AutoTradingSystem::checkBuyPrerequisite(std::string stockCode, int price, int count) {
	if (price <= 0) throw std::exception("Invaid price for buy request; must be higher than 0");
	if (count <= 0) throw std::exception("Invaid count for buy request; must be higher than 0");
	if (stockCode == "") throw std::exception("Invaid stock code for buy request; must have name");
}
