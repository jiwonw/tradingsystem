#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TradingSystem/TradingSystem.cpp"

class TradingSystemFixture : public testing::Test {
public:
	TradingSystem ts;
	const string ID = "NICKNAME";
	const string PW = "ABCD1234";
	MockKiwer MOCK_KIWER;
	MockNemo MOCK_NEMO;
};

TEST_F(TradingSystemFixture, Kiwer_login)
{
	// Arrange
	EXPECT_CALL(MOCK_KIWER, login(ID, PW))
		.Times(1);

	// Act
	ts.selectStockBroker("Kiwer");
	ts.login(ID, PW);
}


TEST_F(TradingSystemFixture, Nemo_login)
{
	// Arrange
	EXPECT_CALL(MOCK_NEMO, certification(ID, PW))
		.Times(1);

	// Act
	ts.selectStockBroker("Nemo");
	ts.login(ID, PW);
}