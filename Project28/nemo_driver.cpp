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
    return nemo.getMarketPrice(stockCode, NO_DELAY);
}