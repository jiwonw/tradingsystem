#include <string>
using namespace std;

class TradingSystem
{
public:
	virtual void selectStockBroker(string Name) {

	}
	virtual void login(string id, string password ) {

	}
	virtual void buy(string stockCode, int price, int count) {

	}
	virtual void sell(string stockCode, int price, int count) {

	}
	virtual void getPrice(string stockCode) {

	}

private:

};