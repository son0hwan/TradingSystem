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

TEST(Application, getCurrentPrice) {
	MockDriver mockBrocker;
	AutoTradingSystem app;

	EXPECT_CALL(mockBrocker, getPrice("test"), (override))
		.Times(1)
		.WillOnce(Return(10));

	app.selectStockBrocker(&mockBrocker);

	EXPECT_EQ(10, app.getPrice("test"));
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

	EXPECT_CALL(mockBrocker, sell("test", 10, 1), (override))
		.Times(1);

	app.selectStockBrocker(&mockBrocker);
	app.sell("test", 10, 1);
}

TEST(Application, priceIsGettingHigher) {
	NiceMock<MockDriver> mockBrocker;
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

TEST(Application, priceIsNotGettingHigher) {
	NiceMock<MockDriver> mockBrocker;
	AutoTradingSystem app;

	EXPECT_CALL(mockBrocker, getPrice("test"), (override))
		.Times(3)
		.WillOnce(Return(10))
		.WillOnce(Return(20))
		.WillOnce(Return(10));

	app.selectStockBrocker(&mockBrocker);

	int buyItemCount = app.buyNiceTiming("test", 100);

	EXPECT_EQ(0, buyItemCount);
}

TEST(Application, sellNiceTimingSuccess) {
	MockDriver mockBrocker;
	AutoTradingSystem app;

	EXPECT_CALL(mockBrocker, getPrice("test"), (override))
		.Times(3)
		.WillOnce(Return(30))
		.WillOnce(Return(20))
		.WillOnce(Return(10));
	EXPECT_CALL(mockBrocker, sell("test", 10, 5), (override))
		.Times(1);

	app.selectStockBrocker(&mockBrocker);

	int sellingMoney = app.sellNiceTiming("test", 5);

	EXPECT_EQ(50, sellingMoney);
}

TEST(Application, sellNiceTimingFailed) {
	MockDriver mockBrocker;
	AutoTradingSystem app;

	EXPECT_CALL(mockBrocker, getPrice("test"), (override))
		.Times(3)
		.WillOnce(Return(30))
		.WillOnce(Return(20))
		.WillOnce(Return(30));

	EXPECT_CALL(mockBrocker, sell("test", _, _), (override))
		.Times(0);

	app.selectStockBrocker(&mockBrocker);

	int sellingMoney = app.sellNiceTiming("test", 5);

	EXPECT_EQ(0, sellingMoney);
}

TEST(Application, loginWrongIDStockBrocker) {
	NiceMock<MockDriver> mockBrocker;
	AutoTradingSystem app;

	app.selectStockBrocker(&mockBrocker);

	EXPECT_THROW(app.login("", "adminPwd"),
		std::exception);
}

TEST(Application, loginWrongPasswordStockBrocker) {
	NiceMock<MockDriver> mockBrocker;
	AutoTradingSystem app;

	app.selectStockBrocker(&mockBrocker);

	EXPECT_THROW(app.login("adminId", ""),
		std::exception);
}

TEST(Application, buyInvalidCode) {
	MockDriver mockBrocker;
	AutoTradingSystem app;

	app.selectStockBrocker(&mockBrocker);

	EXPECT_THROW(app.buy("", 10, 1), std::exception);
}

TEST(Application, buyInvalidPrice) {
	MockDriver mockBrocker;
	AutoTradingSystem app;

	app.selectStockBrocker(&mockBrocker);

	EXPECT_THROW(app.buy("item", -1, 1), std::exception);
}

TEST(Application, buyInvalidCount) {
	MockDriver mockBrocker;
	AutoTradingSystem app;

	app.selectStockBrocker(&mockBrocker);

	EXPECT_THROW(app.buy("item", 10, -1), std::exception);
}