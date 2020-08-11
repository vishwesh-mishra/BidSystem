#include<iostream>
#include "BuyerService.h"

void BuyerService::createBuyer(Buyer *buyer) {
	buyerTable[buyer->buyerId] = buyer;
}

void BuyerService::totalBuyers() {
	cout << "Total number of buyers = " << buyerTable.size() << endl;
}
