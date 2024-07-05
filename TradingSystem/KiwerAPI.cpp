#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
class KiwerAPI {
public:
	virtual void login(string ID, string password) {
		cout << ID << " login success\n";
	}

	virtual void buy(string stockCode, int count, int price) {
		cout << stockCode << " : Buy stock ( " << price << " * " << count << ")\n";
	}

	virtual void sell(string stockCode, int count, int price) {
		cout << stockCode << " : Sell stock ( " << price << " * " << count << ")\n";
	}

	virtual int currentPrice(string stockCode) {
		srand(time(NULL));
		int ret = rand() % 10 * 100 + 5000;
		return ret;
	}
};