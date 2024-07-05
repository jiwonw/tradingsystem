#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TradingSystem/TradingSystem.cpp"

class MockKiwer : public TradingSystem {
public:
	MOCK_METHOD(void, selectStockBroker, (string Name), (override));
	MOCK_METHOD(void, login, (string id, string password), (override));
	MOCK_METHOD(void, buy, (string stockCode, int price, int count), (override));
	MOCK_METHOD(void, sell, (string stockCode, int price, int count), (override));
	MOCK_METHOD(void, getPrice, (string stockCode), (override));
};

class MockNemo : public TradingSystem {
public:
	MOCK_METHOD(void, selectStockBroker, (string Name), (override));
	MOCK_METHOD(void, login, (string id, string password), (override));
	MOCK_METHOD(void, buy, (string stockCode, int price, int count), (override));
	MOCK_METHOD(void, sell, (string stockCode, int price, int count), (override));
	MOCK_METHOD(void, getPrice, (string stockCode), (override));
};

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
	//EXPECT_CALL(MOCK_NEMO, certification(ID, PW))
	//	.Times(1);

	// Act
	ts.selectStockBroker("Nemo");
	ts.login(ID, PW);
}