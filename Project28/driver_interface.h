#pragma once
#include <string>

#pragma once
#include <string>

class StockBrockerDriver {
public:
	virtual void login(std::string ID, std::string password) = 0;

	virtual void buy(std::string stockCode, int price, int count) = 0;

	virtual void sell(std::string stockCode, int price, int count) = 0;

	virtual int getPrice(std::string stockCode) = 0;
};



class NemoDriverInterface : public StockBrockerDriver {
public:
	void login(std::string ID, std::string password) override;

	void buy(std::string stockCode, int count, int price) override;

	void sell(std::string stockCode, int count, int price) override;

	int getPrice(std::string stockCode) override;

};

class KiwerDriverInterface : public StockBrockerDriver {
public:
	void login(std::string ID, std::string password) override;

	void buy(std::string stockCode, int count, int price) override;

	void sell(std::string stockCode, int count, int price) override;

	int getPrice(std::string stockCode) override;

};