#pragma once
#include<string>

using namespace std;

class Buyer {
public:
	string buyerId, name, email;
	Buyer(string id, string name, string email) {
		this->buyerId = id;
		this->name = name;
		this->email = email;
	}
};
