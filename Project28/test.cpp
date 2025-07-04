#include "gmock/gmock.h"
#include "driver_interface.h"
#include "autoTradingSystem.h"

class MockDriver : public StockBrockerDriver {
public:
	MOCK_METHOD(void, login, (std::string, std::string), (override));
	MOCK_METHOD(void, buy, (std::string, int, int), (override));
	MOCK_METHOD(void, sell, (std::string, int, int), (override));
	MOCK_METHOD(int, getPrice, (std::string), (override));
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

TEST(Application, loginStockBrocker) {
	MockDriver mockBrocker;
	AutoTradingSystem app;
	EXPECT_CALL(mockBrocker, login("adminId", "adminPwd"), (override))
		.Times(1);

	app.selectStockBrocker(&mockBrocker);
	app.login("adminId", "adminPwd");
}

TEST(Application, buyStockItem) {
	MockDriver mockBrocker;
	AutoTradingSystem app;

	EXPECT_CALL(mockBrocker, buy("test", 10, 1), (override))
		.Times(1);

	app.selectStockBrocker(&mockBrocker);
	app.buy("test", 10, 1);
}