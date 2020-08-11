#pragma once
#include<string>
#include<map>
#include "../Models/Seller.h"

using namespace std;

class SellerService {
public:
	map<string, Seller*> sellerTable;
	void createSeller(Seller* seller);
	void totalSellers();
};