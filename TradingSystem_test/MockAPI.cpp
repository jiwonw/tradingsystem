#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TradingSystem/TradingSystem.cpp"
#include <string>

using namespace std;

class MockKiwer : public KiwerAPI
{
public:
	MOCK_METHOD(void, login, (string ID, string password), ());
	MOCK_METHOD(void, buy, (string stockCode, int count, int price), ());
	MOCK_METHOD(void, sell, (string stockCode, int count, int price), ());
	MOCK_METHOD(int, currentPrice, (string stockCode), ());
};

class MockNemo : public NemoAPI
{
public:
	MOCK_METHOD(void, certification, (string ID, string pass), ());
	MOCK_METHOD(void, purchasingStock, (string stockCode, int price, int count), ());
	MOCK_METHOD(void, sellingStock, (string stockCode, int price, int count), ());
	MOCK_METHOD(int, getMarketPrice, (string stockCode, int minute), ());
};