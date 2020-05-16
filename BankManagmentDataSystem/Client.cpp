#include "Client.h"

Client::Client(int AccountNumber, int Amount)
{
	this->AccountNumber = AccountNumber;
	this->Amount = Amount;

	leftChild = 0;
	rightChild = 0;
}

void Client::Display()
{
	cout << "-Account Number: " << this->AccountNumber << " -Amount: " << this->Amount <<" $"<< endl;
}


bool Client::LessThan(Client* c1, Client* c2)
{
	if (c1->AccountNumber< c2->AccountNumber)
		return true;
	else
		return false;
}


