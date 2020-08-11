#pragma once
#include<string>

using namespace std;

class BidDetail {
public:
	int bidProdId;
	double bidValue;
	string sellerId;
	BidDetail(int bidProdId, double bidValue, string sellerId) {
		this->bidProdId = bidProdId;
		this->bidValue = bidValue;
		this->sellerId = sellerId;
	}
};
