#pragma once
#include <iostream>

using namespace std;

class Client
{
public:
	int AccountNumber;
	int Amount;
	Client* leftChild;
	Client* rightChild;

	Client(int AccountNumber, int Amount);
	void Display();
	bool LessThan(Client* c1, Client* c2);
private:
};

