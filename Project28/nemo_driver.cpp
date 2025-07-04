#include "driver_interface.h"

void NemoDriverInterface::login(std::string ID, std::string password)
{
}

void NemoDriverInterface::buy(std::string stockCode, int count, int price)
{
}

void NemoDriverInterface::sell(std::string stockCode, int count, int price)
{
}

int NemoDriverInterface::getPrice(std::string stockCode)
{
    return 0;
}


class NemoDriverInterface : public TradingDriverAPI {
public:
	void login(std::string ID, std::string password) override;

	void buy(std::string stockCode, int count, int price) override;

	void sell(std::string stockCode, int count, int price) override;

	int getPrice(std::string stockCode) override;

};

class KiwerDriverInterface : public TradingDriverAPI {
public:
	void login(std::string ID, std::string password) override;

	void buy(std::string stockCode, int count, int price) override;

	void sell(std::string stockCode, int count, int price) override;

	int getPrice(std::string stockCode) override;

};