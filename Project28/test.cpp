#include "gmock/gmock.h"
#include "driver_interface.h"

TEST(Application, selectKiwerStockBrocker) {
	Application app;
	StockBrocker* brocker = app.selectStockBorkcer("kiwer");
	
	EXPECT_TRUE(brocker != nullptr);
}
TEST(Application, selectNemoStockBrocker) {
	Application app;
	StockBrocker* brocker = app.selectStockBorkcer("nemo");
	
	EXPECT_TRUE(brocker != nullptr);
}
