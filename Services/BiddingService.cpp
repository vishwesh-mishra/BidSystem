#include<iostream>
#include "BiddingService.h"

void BiddingService::createBid(BidDetail* bidDetail) {
	initialBidTable[bidDetail->bidProdId] = bidDetail;
	this->bidId++;
}

void BiddingService::placeBid(int bidProdId, string buyerId, double bidValue) {
	if (initialBidTable.find(bidProdId) == initialBidTable.end()) cout << "Bid is not available or has been closed" << endl;
	else {
		if (initialBidTable[bidProdId]->bidValue >= bidValue) {
			cout << "Bid cannot be placed with value less than or equal to initial bid. Try again!!" << endl;
			return;
		}
		placedBidTable[bidProdId].insert({ buyerId,bidValue });
	}
}

void BiddingService::deleteTotalBid(int bidProdId) {
	initialBidTable.erase(bidProdId);
	placedBidTable.erase(bidProdId);
}

void BiddingService::deletePlacedBid(int bidProdId, string buyerId) {
	placedBidTable[bidProdId].erase(buyerId);
}

void BiddingService::closeBidAndFindWinner(int bidProdId) {
	if (initialBidTable.find(bidProdId) == initialBidTable.end()) cout << "Bid Doesn't exist" << endl;
	else if (placedBidTable.find(bidProdId) == placedBidTable.end()) cout << "No bids found. Hence no winner!" << endl;
	else {
		// Closing bid and finding winner
		string winner = "No winner";
		map<string, double> bidders = placedBidTable[bidProdId];
		map<string, double>::iterator it;
		double maxBid = 0;
		for (it = bidders.begin();it != bidders.end();it++) {
			if (it->second > maxBid) {
				maxBid = it->second;
				winner = it->first;
			}
		}
		deleteTotalBid(bidProdId);
		cout << "Winner is: " << winner << " with bidValue: "<< maxBid<< endl;
	}
}