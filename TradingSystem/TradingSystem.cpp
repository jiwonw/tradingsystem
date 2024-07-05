#pragma once
#include <string>
#include "KiwerAPI.cpp"
#include "NemoAPI.cpp"

using namespace std;

#define interface struct

interface StockBrokerDriver {
	virtual void login(string id, string password) = 0;
	virtual void buy(string stockCode, int price, int count) = 0;
	virtual void sell(string stockCode, int price, int count) = 0;
	virtual int getPrice(string stockCode) = 0;
};

class KiwerDriver : public StockBrokerDriver {
public:
	KiwerDriver(KiwerAPI* api)
		: api{ api }
	{

	}
	void login(string id, string password) {
		api->login(id,  password);
	}
	void buy(string stockCode, int price, int count) {
		api->buy(stockCode, price, count);
	}
	void sell(string stockCode, int price, int count) {
		api->sell(stockCode, price, count);
	}
	int getPrice(string stockCode) {
		return api->currentPrice(stockCode);
	}
private:
	KiwerAPI* api;
};

class NemoDriver : public StockBrokerDriver {
public:
	NemoDriver(NemoAPI* api)
		: api{ api }
	{

	}
	void login(string id, string password) {
		api->certification(id, password);
	}
	void buy(string stockCode, int price, int count) {
		api->purchasingStock(stockCode, price, count);
	}
	void sell(string stockCode, int price, int count) {
		api->sellingStock(stockCode, price, count);
	}
	int getPrice(string stockCode) {
		return api->getMarketPrice(stockCode, 0);
	}
private:
	NemoAPI* api;
};



class TradingSystem
{
public:
	void selectStockBroker(KiwerAPI *api) {
		driver = new KiwerDriver(api);
	}

	void selectStockBroker(NemoAPI *api) {
		driver = new NemoDriver(api);
	}

	void login(string id, string password ) {
		driver->login(id, password);
	}
	void buy(string stockCode, int price, int count) {
		driver->buy(stockCode, price, count);
	}
	void sell(string stockCode, int price, int count) {
		driver->sell(stockCode, price, count);
	}
	int getPrice(string stockCode) {
		return driver->getPrice(stockCode);
	}

private:
	StockBrokerDriver* driver;
};