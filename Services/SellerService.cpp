#include<iostream>
#include "SellerService.h"

void SellerService::createSeller(Seller* seller) {
	sellerTable[seller->sellerId] = seller;
}

void SellerService::totalSellers() {
	cout << "Total number of sellers = " << sellerTable.size() << endl;
}