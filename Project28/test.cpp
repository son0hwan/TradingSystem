#include "gmock/gmock.h"
#include "driver_interface.h"
#include <iostream>


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

TEST(Application, logInKiwerSTockBrocker) {
	Application app;
	std::string id = "adminId";
	std::string pwd = "adminPwd";
	StockBrockerDriver* brocker = app.selectStockBrocker("kiwer");
	
	bool loginSuccess = app.login(id, pwd);

	EXPECT_TRUE(loginSuccess);
}

TEST(Application, logInNemoSTockBrocker) {
	Application app;
	std::string id = "adminId";
	std::string pwd = "adminPwd";
	StockBrockerDriver* brocker = app.selectStockBrocker("nemo");
	
	bool loginSuccess = app.login(id, pwd);

	EXPECT_TRUE(loginSuccess);
}