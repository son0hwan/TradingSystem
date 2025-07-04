#include "gmock/gmock.h"
#include "driver_interface.h"

class MockDriver : public TradingDriverAPI {
public:
	MOCK_METHOD(void, login, (std::string, std::string), (override));
	MOCK_METHOD(void, buy, (std::string, int, int), (override));
	MOCK_METHOD(void, sell, (std::string, int, int), (override));
	MOCK_METHOD(int, getPrice, (std::string), (override));
};

TEST(TS, TC1) {
	EXPECT_EQ(1, 1);
}