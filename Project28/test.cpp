#include "gmock/gmock.h"
#include "driver_interface.h"

TEST(Application, selectKiwerStockBrocker) {
	Application app;
	StockBrockerDriver* brocker = app.selectStockBrocker("kiwer");
	
	EXPECT_TRUE(brocker != nullptr);
}
TEST(Application, selectNemoStockBrocker) {
	Application app;
	StockBrockerDriver* brocker = app.selectStockBrocker("nemo");
	
	EXPECT_TRUE(brocker != nullptr);
}