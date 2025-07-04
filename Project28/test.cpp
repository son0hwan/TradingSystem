#include "gmock/gmock.h"
#include "driver_interface.h"
#include "autoTradingSystem.h"

class StockBrockerBock : public TradingDriverAPI {
public:

};

TEST(Application, selectKiwerStockBrocker) {
	AutoTradingSystem app;
	BrockerFinder finder;

	auto broker = finder.getStockBrocker("kiwer");

	app.selectStockBrocker(broker);
}
TEST(Application, selectNemoStockBrocker) {
	AutoTradingSystem app;
	BrockerFinder finder;

	auto newmoBroker = finder.getStockBrocker("nemo");
	app.selectStockBrocker(newmoBroker);
}
