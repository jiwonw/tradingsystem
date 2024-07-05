#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>

using namespace std;
class NemoAPI {
public:
	virtual void certification(string ID, string pass) {
		cout << "[NEMO]" << ID << " login GOOD\n";
	}

	virtual void purchasingStock(string stockCode, int price, int count) {
		cout << "[NEMO]" << stockCode << " buy stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	virtual void sellingStock(string stockCode, int price, int count) {
		cout << "[NEMO]" << stockCode << " sell stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	virtual int getMarketPrice(string stockCode, int minute) {
		//minute ms�� ���� ���Ű� �Ǵ� ��� (�ּ� 1 ms)
		if (minute <= 0) minute = 1;
		Sleep(minute);
		srand(time(NULL));
		int ret = rand() % 10 * 100 + 5000;
		return ret;
	}
};