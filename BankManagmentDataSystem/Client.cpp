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
	cout << "AccountNumber: " << this->AccountNumber << " -Amount: " << this->Amount <<"$"<< endl;
}

int Client::Factorial(int n)
{
	if (n == 1)
		return 1;
	return Factorial(n - 1) * n;
}

bool Client::LessThan(Client* c1, Client* c2)
{
	int AccountFactorialA = Factorial(c1->AccountNumber) * c1->Amount;
	int AccountFactorialB = Factorial(c2->AccountNumber) * c2->Amount;

	if (AccountFactorialA < AccountFactorialB)
		return true;
	else
		return false;
}
