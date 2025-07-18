#include "autoTradingSystem.h"
#include <windows.h>
#include <exception>

class InvalidLoginException : public std::exception {};

using std::string;

void AutoTradingSystem::selectStockBrocker(StockBrockerDriver* _driver) {
	driver = _driver;
}

void AutoTradingSystem::login(std::string ID, std::string password) {
	if (ID == "" || password == "") throw InvalidLoginException();
	driver->login(ID, password);
}

void AutoTradingSystem::sell(std::string stockCode, int price, int count) {
	driver->sell(stockCode, price, count);
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

int AutoTradingSystem::sellNiceTiming(std::string stockCode, int stockCount)
{
	int price = getNiceCellPrice(stockCode);
	if (false == isValidStockPrice(price)) {
		return 0;
	}

	driver->sell(stockCode, price, stockCount);
	return price * stockCount;
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

int AutoTradingSystem::getNiceCellPrice(const std::string& stockCode) {
	int currPrice = driver->getPrice(stockCode);

	if (false == isValidStockPrice(currPrice)) return INVALID_STOCK_PRICE;
	for (int i = 0; i < MAX_SELL_COUNT - 1; i++) {
		Sleep(200);

		int newPrice = driver->getPrice(stockCode);

		if (false == isValidStockPrice(newPrice)) return INVALID_STOCK_PRICE;
		if (currPrice <= newPrice)  return INVALID_STOCK_PRICE;
		currPrice = newPrice;
	}
	return currPrice;
}

bool AutoTradingSystem::isValidStockPrice(int price) {
	return (price > 0);
}
