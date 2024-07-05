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

// LOGIN !!!
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

// BUY !!!
TEST_F(TradingSystemFixture, Kiwer_buy)
{
	// Arrange
	EXPECT_CALL(MOCK_KIWER, login(ID, PW))
		.Times(1);
	EXPECT_CALL(MOCK_KIWER, buy("SAMSUNG", 100000, 50))
		.Times(1);

	// Act
	ts.selectStockBroker("Kiwer");
	ts.login(ID, PW);
	ts.buy("SAMSUNG", 100000, 50);
}

TEST_F(TradingSystemFixture, Nemo_buy)
{
	// Arrange
	EXPECT_CALL(MOCK_NEMO, certification(ID, PW))
		.Times(1);
	EXPECT_CALL(MOCK_NEMO, purchasingStock("SAMSUNG", 100000, 50))
		.Times(1);

	// Act
	ts.selectStockBroker("Nemo");
	ts.login(ID, PW);
	ts.buy("SAMSUNG", 100000, 50);
}

TEST_F(TradingSystemFixture, Kiwer_buy_without_login)
{
	// Arrange
	EXPECT_CALL(MOCK_KIWER, buy("SAMSUNG", 100000, 50))
		.Times(1);

	// Act
	try {
		ts.selectStockBroker("Kiwer");
		ts.buy("SAMSUNG", 100000, 50);
	}
	catch (exception& e) {
		EXPECT_EQ(e.what(), string("Cannot buy stock before login"));
	}
}

TEST_F(TradingSystemFixture, Nemo_buy_without_login)
{
	// Arrange
	EXPECT_CALL(MOCK_NEMO, purchasingStock("SAMSUNG", 100000, 50))
		.Times(1);

	// Act
	try {
		ts.selectStockBroker("Nemo");
		ts.buy("SAMSUNG", 100000, 50);
	}
	catch (exception& e) {
		EXPECT_EQ(e.what(), string("Cannot buy stock before login"));
	}
}


// SELL !!!
TEST_F(TradingSystemFixture, Kiwer_sell)
{
	// Arrange
	EXPECT_CALL(MOCK_KIWER, login(ID, PW))
		.Times(1);
	EXPECT_CALL(MOCK_KIWER, sell("SAMSUNG", 100000, 50))
		.Times(1);

	// Act
	ts.selectStockBroker("Kiwer");
	ts.login(ID, PW);
	ts.sell("SAMSUNG", 100000, 50);
}

TEST_F(TradingSystemFixture, Nemo_sell)
{
	// Arrange
	EXPECT_CALL(MOCK_NEMO, certification(ID, PW))
		.Times(1);
	EXPECT_CALL(MOCK_NEMO, sellingStock("SAMSUNG", 100000, 50))
		.Times(1);

	// Act
	ts.selectStockBroker("Nemo");
	ts.login(ID, PW);
	ts.buy("SAMSUNG", 100000, 50);
}

TEST_F(TradingSystemFixture, Kiwer_sell_without_login)
{
	// Arrange
	EXPECT_CALL(MOCK_KIWER, buy("SAMSUNG", 100000, 50))
		.Times(1);

	// Act
	try {
		ts.selectStockBroker("Kiwer");
		ts.sell("SAMSUNG", 100000, 50);
	}
	catch (exception& e) {
		EXPECT_EQ(e.what(), string("Please login before selling stocks."));
	}
}

TEST_F(TradingSystemFixture, Nemo_sell_without_login)
{
	// Arrange
	EXPECT_CALL(MOCK_NEMO, sellingStock("SAMSUNG", 100000, 50))
		.Times(1);

	// Act
	try {
		ts.selectStockBroker("Nemo");
		ts.sell("SAMSUNG", 100000, 50);
	}
	catch (exception& e) {
		EXPECT_EQ(e.what(), string("Please login before selling stocks."));
	}
}