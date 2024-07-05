#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TradingSystem/TradingSystem.cpp"
#include "MockAPI.cpp"

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
	ts.selectStockBroker(&MOCK_KIWER);
	ts.login(ID, PW);
}


TEST_F(TradingSystemFixture, Nemo_login)
{
	// Arrange
	EXPECT_CALL(MOCK_NEMO, certification(ID, PW))
		.Times(1);

	// Act
	ts.selectStockBroker(&MOCK_NEMO);
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
	ts.selectStockBroker(&MOCK_KIWER);
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
	ts.selectStockBroker(&MOCK_NEMO);
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
		ts.selectStockBroker(&MOCK_KIWER);
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
		ts.selectStockBroker(&MOCK_NEMO);
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
	ts.selectStockBroker(&MOCK_KIWER);
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
	ts.selectStockBroker(&MOCK_NEMO);
	ts.login(ID, PW);
	ts.sell("SAMSUNG", 100000, 50);
}

TEST_F(TradingSystemFixture, Kiwer_sell_without_login)
{
	// Arrange
	EXPECT_CALL(MOCK_KIWER, sell("SAMSUNG", 100000, 50))
		.Times(1);

	// Act
	try {
		ts.selectStockBroker(&MOCK_KIWER);
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
		ts.selectStockBroker(&MOCK_NEMO);
		ts.sell("SAMSUNG", 100000, 50);
	}
	catch (exception& e) {
		EXPECT_EQ(e.what(), string("Please login before selling stocks."));
	}
}

// GET PRICE !!!

TEST_F(TradingSystemFixture, Kiwer_getPrice)
{
	// Arrange
	EXPECT_CALL(MOCK_KIWER, currentPrice("SAMSUNG"))
		.Times(1);

	// Act
	ts.selectStockBroker(&MOCK_KIWER);
	int price = ts.getPrice("SAMSUNG");
}

TEST_F(TradingSystemFixture, Nemo_getPrice)
{
	// Arrange
	EXPECT_CALL(MOCK_NEMO, getMarketPrice("SAMSUNG", 0))
		.Times(1);

	// Act
	ts.selectStockBroker(&MOCK_NEMO);
	int price = ts.getPrice("SAMSUNG");
}

// BUY NICE TIMING !!!
TEST_F(TradingSystemFixture, Kiwer_buyNiceTiming)
{
	vector<int> price = {
		100000
		, 100003
		, 100004
		, 100005
		, 100006
		, 100007
		, 100008
		, 100009
	};
	// Arrange
	EXPECT_CALL(MOCK_KIWER, currentPrice("SAMSUNG"))
		.WillOnce(testing::Return(price[0]))
		.WillOnce(testing::Return(price[1]))
		.WillOnce(testing::Return(price[2]))
		.WillOnce(testing::Return(price[3]))
		.WillOnce(testing::Return(price[4]))
		.WillOnce(testing::Return(price[5]))
		.WillOnce(testing::Return(price[6]))
		.WillOnce(testing::Return(price[7]));
	EXPECT_CALL(MOCK_KIWER, buy("SAMSUNG", testing::_, testing::_))
		.Times(testing::AtLeast(1));


	// Act
	ts.selectStockBroker(&MOCK_KIWER);
	ts.login(ID, PW);
	ts.buyNiceTiming("SAMSUNG", 1000000);
}

TEST_F(TradingSystemFixture, Nemo_buyNiceTiming)
{
	vector<int> price = {
		100000
		, 100003
		, 100004
		, 100005
		, 100006
		, 100007
		, 100008
		, 100009
	};

	// Arrange
	EXPECT_CALL(MOCK_NEMO, getMarketPrice("SAMSUNG", 0))
		.WillOnce(testing::Return(price[0]))
		.WillOnce(testing::Return(price[1]))
		.WillOnce(testing::Return(price[2]))
		.WillOnce(testing::Return(price[3]))
		.WillOnce(testing::Return(price[4]))
		.WillOnce(testing::Return(price[5]))
		.WillOnce(testing::Return(price[6]))
		.WillOnce(testing::Return(price[7]));

	EXPECT_CALL(MOCK_NEMO, purchasingStock("SAMSUNG", testing::_, testing::_))
		.Times(testing::AtLeast(1));


	// Act
	ts.selectStockBroker(&MOCK_NEMO);
	ts.login(ID, PW);
	ts.buyNiceTiming("SAMSUNG", 1000000);
}