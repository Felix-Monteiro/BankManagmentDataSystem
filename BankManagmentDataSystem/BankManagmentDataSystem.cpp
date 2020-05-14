// BankManagmentDataSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"Client.h"
#include"ClientTree.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
/* Logic:

		  1000
		   / \
		3000 10000
	    /   \     \
      500   47000  1000000

 */
	cout << "\n====Bank Database Managment System====" << endl;

	//Creation & Display of the initial Tree Database
	ClientTree* BankTree = new ClientTree();
	BankTree->InsertAccount(1, 1000);
	BankTree->InsertAccount(2, 3000);
	BankTree->InsertAccount(3, 10000);
	BankTree->InsertAccount(4, 500);
	BankTree->InsertAccount(5, 47000);
	BankTree->InsertAccount(6, 1000000);

	cout << "\n==== Client Database ====" << endl;
	BankTree->DisplayInOrder(BankTree->root);
	Sleep(4000);

	//Getting the Successor
	Sleep(4000);
	cout << "\n=Request:" << endl;
	struct Client* successor = BankTree->Getsuccessor(1, 1000);
	if (successor == NULL) cout << "No successor Found\n";
	else
		cout << "The successor is the Account Number: " << successor->AccountNumber << "\n";
		cout << "With the Amount of: " << successor->Amount << "$"<< "\n";
	Sleep(4000);


	//Deleting Account
	cout << "\n=Request:" << endl;
	cout << "-Delete Account:" << endl;


	BankTree->root = BankTree->DeleteAccount(BankTree->root, 1);
	Sleep(4000); 
	cout << "\n==== Client Database ====" << endl;
	BankTree->DisplayInOrder(BankTree->root);

	return 0;

    
}


