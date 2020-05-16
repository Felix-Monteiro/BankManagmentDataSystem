#pragma once
#include "Client.h"
#include <iostream>

using namespace std;

class ClientTree
{
public:
	Client* root;
	ClientTree();
	Client *Find(Client* key);
	void DisplayInOrder(Client* localRoot);
	void InsertAccount(int AccountNumber, int Amount);
	Client* FindMin(Client* root);
	struct Client* DeleteAccount(struct Client* root, int AccountNumber);
	struct Client* Getsuccessor(Client* root, int AccountNumber);
	bool Search(Client* root, int AccountNumber);
	int FindHeight(struct Client* root);
private:

};

