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
	if (false == checkBuyPrerequisite(price, count)) {
		return;
	}
	driver->buy(stockCode, price, count);
}

bool AutoTradingSystem::checkBuyPrerequisite(int price, int count) {
	if (price <= 0 || count <= 0) return false;
}

int AutoTradingSystem::buyNiceTiming(std::string stockCode, int price) {
	int priceValue = driver->getPrice(stockCode);
	for (int times = 2; times <= 3; times++) {
		Sleep(200);

		if (priceValue >= driver->getPrice(stockCode)) return 0;
		driver->buy(stockCode, price, 3);
	}
	return 3;
}

StockBrockerDriver* BrockerFinder::getStockBrocker(string brokername) {
	if (brokername == "kiwer") {
		return new KiwerDriverInterface(); //TBD, API
	}

	if (brokername == "nemo") {
		return new NemoDriverInterface(); //TBD, API
	}