#include "autoTradingSystem.h"
#include <windows.h>

using std::string;

void AutoTradingSystem::selectStockBrocker(StockBrockerDriver* _driver) {
	driver = _driver;
}

void AutoTradingSystem::login(std::string ID, std::string password) {
	driver->login(ID, password);
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

int AutoTradingSystem::buyNiceTiming(std::string stockCode, int price) {
	if (false == IsPriceIncrease3Times(stockCode, price)) return 0;
	return MAX_BUY_COUNT;
}

bool AutoTradingSystem::IsPriceIncrease3Times(std::string& stockCode, int price)
{
	int priceValue = driver->getPrice(stockCode);
	for (int times = 2; times <= 3; times++) {
		Sleep(200);

		int newPrice = driver->getPrice(stockCode);
		if (priceValue >= newPrice) return false;
		priceValue = newPrice;
	}
}

StockBrockerDriver* BrockerFinder::getStockBrocker(string brokername) {
	if (brokername == "kiwer") {
		return new KiwerDriverInterface(); //TBD, API
	}

	if (brokername == "nemo") {
		return new NemoDriverInterface(); //TBD, API
	}
}