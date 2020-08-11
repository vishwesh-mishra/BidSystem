#pragma once
#include<string>

using namespace std;

class Seller {
public:
	string sellerId, name, email;
	Seller(string id, string name, string email) {
		this->sellerId = id;
		this->name = name;
		this->email = email;
	}
};
