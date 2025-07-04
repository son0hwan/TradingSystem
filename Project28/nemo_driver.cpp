#include "driver_interface.h"

void NemoDriverInterface::login(std::string ID, std::string password)
{
    nemo.certification(ID, password);
}

void NemoDriverInterface::buy(std::string stockCode, int count, int price)
{
    nemo.purchasingStock(stockCode, price, count);
}

void NemoDriverInterface::sell(std::string stockCode, int count, int price)
{
    nemo.sellingStock(stockCode, price, count);
}

int NemoDriverInterface::getPrice(std::string stockCode)
{
    return nemo.getMarketPrice(stockCode, NO_DELAY);
}