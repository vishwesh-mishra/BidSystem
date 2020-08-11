#pragma once
#include<string>
#include<map> 
#include "../Models/BidDetail.h"

using namespace std;

class BiddingService {
public:
	int bidId;
	map<int, BidDetail*> initialBidTable;
	map <int, map<string,double>> placedBidTable;
	BiddingService() {
		this->bidId = 1;
	}

	void createBid(BidDetail *bidDetail);
	void placeBid(int bidProdId, string buyerId, double bidValue);
	void deleteTotalBid(int bidProdId);
	void deletePlacedBid(int bidProdId, string buyerId);
	void closeBidAndFindWinner(int bidProdId);
};
