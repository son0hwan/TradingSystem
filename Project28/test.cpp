#include "gmock/gmock.h"
#include "driver_interface.h"
#include "autoTradingSystem.h"

using namespace testing;

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

TEST(Application, sellStockItem) {
	MockDriver mockBrocker;
	AutoTradingSystem app;

	EXPECT_CALL(mockBrocker, buy("test", 10, 1), (override))
		.Times(1);

	app.selectStockBrocker(&mockBrocker);
	app.sell("test", 10, 1);
}

TEST(Application, getCurrentPrice) {
	MockDriver mockBrocker;
	AutoTradingSystem app;

	EXPECT_CALL(mockBrocker, getPrice("test"), (override))
		.Times(1)
		.WillOnce(Return(10));

	app.selectStockBrocker(&mockBrocker);

	EXPECT_EQ(10, app.getPrice("test"));
}

TEST(Application, priceIsGettingHigher) {
	MockDriver mockBrocker;
	AutoTradingSystem app;

	EXPECT_CALL(mockBrocker, getPrice("test"), (override))
		.Times(3)
		.WillOnce(Return(10))
		.WillOnce(Return(20))
		.WillOnce(Return(30));

	app.selectStockBrocker(&mockBrocker);

	int buyItemCount = app.buyNiceTiming("test", 100);
	
	EXPECT_EQ(3, buyItemCount);
}