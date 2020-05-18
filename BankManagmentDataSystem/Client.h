#pragma once
#include <iostream>

using namespace std;

class Client
{
public:
	Client* leftChild;
	Client* rightChild;
	int AccountNumber;
	int Amount;

	Client(int AccountNumber, int Amount);
	void Display();
	bool LessThan(Client* c1, Client* c2);
private:
};

