#pragma once
#include "driver_interface.h"

void KiwerDriverInterface::login(std::string ID, std::string password)
{
    kiwer.login(ID, password);
}

void KiwerDriverInterface::buy(std::string stockCode, int count, int price)
{
	kiwer.buy(stockCode, count, price);
}

void KiwerDriverInterface::sell(std::string stockCode, int count, int price)
{
	kiwer.sell(stockCode, count, price);
}

int KiwerDriverInterface::getPrice(std::string stockCode)
{
	return kiwer.currentPrice(stockCode);
}