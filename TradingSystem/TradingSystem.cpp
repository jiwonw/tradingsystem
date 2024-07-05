#include <string>
#include "KiwerAPI.cpp"
#include "NemoAPI.cpp"
using namespace std;

#define interface struct

interface StockBrokerDriver {
	virtual void login(string id, string password) = 0;
	virtual void buy(string stockCode, int price, int count) = 0;
	virtual void sell(string stockCode, int price, int count) = 0;
	virtual int getPrice(string stockCode, int minute) = 0;
};

class KiwerDriver : public StockBrokerDriver {
	void login(string id, string password);
	void buy(string stockCode, int price, int count);
	void sell(string stockCode, int price, int count);
	int getPrice(string stockCode, int minute);
};

class NemoDriver : public StockBrokerDriver {
	void login(string id, string password);
	void buy(string stockCode, int price, int count);
	void sell(string stockCode, int price, int count);
	int getPrice(string stockCode, int minute);
};

class TradingSystem
{
public:
	void selectStockBroker(string Name) {
		if ("Kiwer") driver = new KiwerDriver();
		if ("Nemo") driver = new NemoDriver();
		driver = nullptr;
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
	int getPrice(string stockCode, int minute) {
		return driver->getPrice(stockCode, minute);
	}

private:
	StockBrokerDriver* driver;
};