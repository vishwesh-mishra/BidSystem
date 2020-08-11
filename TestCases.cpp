#include "TestCases.h"

void TestCases::tc1() {
	SellerService* sellerService = new SellerService();
	BuyerService* buyerService = new BuyerService();
	BiddingService* biddingService = new BiddingService();

	sellerService->createSeller(new Seller("seller1", "Seller 1", "seller1@bid.com"));
	sellerService->createSeller(new Seller("seller2", "Seller 2", "seller2@bid.com"));
	sellerService->createSeller(new Seller("seller3", "Seller 3", "seller3@bid.com"));

	buyerService->createBuyer(new Buyer("buyer1", "Buyer 1", "buyer1@bid.com"));
	buyerService->createBuyer(new Buyer("buyer2", "Buyer 2", "buyer2@bid.com"));
	buyerService->createBuyer(new Buyer("buyer3", "Buyer 3", "buyer3@bid.com"));
	buyerService->createBuyer(new Buyer("buyer4", "Buyer 4", "buyer4@bid.com"));
	buyerService->createBuyer(new Buyer("buyer5", "Buyer 5", "buyer5@bid.com"));
	buyerService->createBuyer(new Buyer("buyer6", "Buyer 6", "buyer6@bid.com"));
	buyerService->createBuyer(new Buyer("buyer7", "Buyer 7", "buyer7@bid.com"));
	buyerService->createBuyer(new Buyer("buyer8", "Buyer 8", "buyer8@bid.com"));
	buyerService->createBuyer(new Buyer("buyer9", "Buyer 9", "buyer9@bid.com"));
	buyerService->createBuyer(new Buyer("buyer10", "Buyer 10", "buyer10@bid.com"));

	sellerService->totalSellers();
	buyerService->totalBuyers();

	biddingService->createBid(new BidDetail(biddingService->bidId, 10.7, "seller1"));
	biddingService->placeBid(1, "buyer2", 13.3);
	biddingService->placeBid(1, "buyer6", 24.9);
	biddingService->placeBid(1, "buyer3", 28.1);

	biddingService->createBid(new BidDetail(biddingService->bidId, 100, "seller2"));
	biddingService->placeBid(2, "buyer4", 111.6);
	biddingService->placeBid(2, "buyer3", 123.7);

	biddingService->placeBid(1, "buyer9", 32.4);

	biddingService->createBid(new BidDetail(biddingService->bidId, 325.5, "seller3"));

	biddingService->placeBid(2, "buyer7", 122.8);

	biddingService->placeBid(1, "buyer8", 30.7);

	biddingService->placeBid(3, "buyer10", 327);

	biddingService->createBid(new BidDetail(biddingService->bidId, 456.7, "seller2"));

	//biddingService->deleteTotalBid(1);
	biddingService->closeBidAndFindWinner(1); // Winner should be buyer9 with 32.4

	biddingService->placeBid(3, "buyer7", 321.2); // Should throw bidValue less than initial bid not allowed
	biddingService->closeBidAndFindWinner(4); // No placed bids

	biddingService->placeBid(1, "buyer4", 41.3); // Bid doesn't exist

	biddingService->closeBidAndFindWinner(5); // Bid doesn't exist

	//biddingService->closeBidAndFindWinner(2); // winner should be buyer3 with 123.7
	biddingService->deletePlacedBid(2, "buyer3");
	biddingService->closeBidAndFindWinner(2); // winner should be buyer7 with 122.8

	//biddingService->closeBidAndFindWinner(3); // winner should be buyer10 with 327
	biddingService->deleteTotalBid(3);
	biddingService->closeBidAndFindWinner(3); // bid doesn't exist
}