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


bool isKiwerBrocker(StockBrockerDriver* driver) {
	return (nullptr != dynamic_cast<KiwerDriverInterface*>(driver));
}

bool isNemoBrocker(StockBrockerDriver* driver) {
	return (nullptr != dynamic_cast<NemoDriverInterface*>(driver));
}

TEST(Application, selectKiwerStockBrocker) {
	AutoTradingSystem app;
	BrockerFinder finder;

	auto broker = finder.getStockBrocker("kiwer");
	app.selectStockBrocker(broker);

	EXPECT_TRUE(isKiwerBrocker(broker));
	EXPECT_FALSE(isNemoBrocker(broker));
}

TEST(Application, selectNemoStockBrocker) {
	AutoTradingSystem app;
	BrockerFinder finder;

	auto broker = finder.getStockBrocker("nemo");
	app.selectStockBrocker(broker);

	EXPECT_TRUE(isNemoBrocker(broker));
	EXPECT_FALSE(isKiwerBrocker(broker));
}
TEST(Application, loginStockBrocker) {
	MockDriver mockBrocker;
	AutoTradingSystem app;
	EXPECT_CALL(mockBrocker, login("adminId", "adminPwd"), (override))
		.Times(1);

	app.selectStockBrocker(&mockBrocker);
	app.login("adminId", "adminPwd");
}