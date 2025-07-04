#pragma once
#pragma once
#include <string>
#include <vector>
#include "driver_interface.h"

class AutoTradingSystem {
public:
	void selectStockBrocker(StockBrockerDriver* driver);
	void login(std::string ID, std::string password);
	void buy(std::string stockCode, int price, int count);
	void sell(std::string stockCode, int price, int count);
	int getPrice(std::string stockCode);
	int buyNiceTiming(std::string stockCode, int price);
	int sellNiceTiming(std::string stockCode, int stockCount);

private:
	bool IsPriceIncrease3Times(std::string& stockCode, int price);
	void checkBuyPrerequisite(std::string stockCode, int price, int count);

	int getNiceCellPrice(const std::string& stockCode);

	bool isValidStockPrice(int price);

	StockBrockerDriver* driver;
	static const int MAX_BUY_COUNT = 3;
	static const int MAX_SELL_COUNT = 3;
	static const int INVALID_STOCK_PRICE = -1;
};

class BrockerFinder {
public:
	virtual StockBrockerDriver* getStockBrocker(std::string brokername);
};