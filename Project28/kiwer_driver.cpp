#pragma once
#include "driver_interface.h"

void KiwerDriverInterface::login(std::string ID, std::string password)
{
}

void KiwerDriverInterface::buy(std::string stockCode, int count, int price)
{
}

void KiwerDriverInterface::sell(std::string stockCode, int count, int price)
{
}

int KiwerDriverInterface::getPrice(std::string stockCode)
{
	return kiwer.currentPrice(stockCode);
}