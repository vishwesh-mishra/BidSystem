#pragma once
#include<string>
#include<map>
#include "../Models/Buyer.h"

using namespace std;

class BuyerService {
public:
	map<string, Buyer*> buyerTable;
	void createBuyer(Buyer *buyer);
	void totalBuyers();
};