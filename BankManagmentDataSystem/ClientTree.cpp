#include "ClientTree.h"
#include <windows.h>

ClientTree::ClientTree()
{
	root = 0;
}

Client* ClientTree::Find(Client* key)
{
	Client* current = root;
	while (current != key) {
		if (key < current)
			current = current->leftChild;
		else
			current = current->rightChild;
		if (current == 0)
			return 0;
	}
	return current;
}

//Function Overloading- In order to display Account details
Client* ClientTree::Find(int key)
{
	Client* current = root;
	while (current->AccountNumber != key) {
		if (key < current->AccountNumber)
			current = current->leftChild;
		else
			current = current->rightChild;
		if (current == 0)
			return 0;
	}
	return current;
}

void ClientTree::DisplayInOrder(Client* localRoot)
{
	if (localRoot != 0) {
		DisplayInOrder(localRoot->leftChild);
		localRoot->Display();
		DisplayInOrder(localRoot->rightChild);
	}
}

void ClientTree::InsertAccount(int AccountNumber, int Amount)
{
	Client* newNode = new Client(AccountNumber, Amount);
	if (root == 0)
		root = newNode;
	else {
		Client* current = root;
		Client* parent;
		while (true) {
			parent = current;
			if (newNode->LessThan(newNode, current)) {
				current = current->leftChild;
				if (current == 0) {
					parent->leftChild = newNode;
					return;
				}
			}
			else {
				current = current->rightChild;
				if (current == 0) {
					parent->rightChild = newNode;
					return;
				}
			}
		}
	}
}

Client* ClientTree::FindMin(Client* root)
{
	while (root->leftChild != NULL) root = root->leftChild;
	return root;
}

Client* ClientTree::DeleteAccount(Client* root, int AccountNumber)
{
	cout << "->Deleating Account: " << AccountNumber << endl;
	if (root == NULL) return root;
	else if (AccountNumber < root->AccountNumber) root->leftChild = DeleteAccount(root->leftChild, AccountNumber);
	else if (AccountNumber > root->AccountNumber) root->rightChild = DeleteAccount(root->rightChild, AccountNumber);
	// Account Found-Ready to be deleted	

	else {

		// 1st Case:  No child
		if (root->leftChild == NULL && root->rightChild == NULL) {
			delete root;
			root = NULL;
		}

		// 2nd Case: One child 
		else if (root->leftChild == NULL) {
			struct Client* temp = root;
			root = root->rightChild;
			delete temp;
		}
		else if (root->rightChild == NULL) {
			struct Client* temp = root;
			root = root->leftChild;
			delete temp;
		}

		// 3rd Case: 2 children
		else {
			struct Client* temp = FindMin(root->rightChild);
			root->AccountNumber = temp->AccountNumber;
			root->rightChild = DeleteAccount(root->rightChild, temp->AccountNumber);
		}
	}
	return root;
}

Client* ClientTree::Getsuccessor(Client* root, int AccountNumber)
{
	// Search the Node - O(n)

	struct Client* current = Find(root);
	if (current == NULL) return NULL;
	cout << "Getting the Successor of Account Number: " << AccountNumber << endl;
	cout << "...\n" << endl;
	Sleep(3000);
	if (current->rightChild != NULL) {  //Case 1: Node has right subtree
		return FindMin(current->rightChild); // O(n)
	}
	else {   //Case 2: No right subtree  - O(n)
		struct Client* successor = NULL;
		struct Client* ancestor = root;
		while (ancestor != current) {
			if (current->AccountNumber < ancestor->AccountNumber) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->leftChild;
			}
			else
				ancestor = ancestor->rightChild;
		}
		return successor;
	}
}

bool ClientTree::Search(Client* root, int AccountNumber)
{
	if (root == NULL) {
		return false;
	}
	else if (root->AccountNumber == AccountNumber) {
		return true;

	}
	else if (AccountNumber <= root->AccountNumber) {
		return Search(root->leftChild, AccountNumber);
	}
	else {
		return Search(root->rightChild, AccountNumber);
	}

}

int ClientTree::FindHeight(Client* root)
{
	if (root == NULL) {
		return-1;
	}
	return max(FindHeight(root->leftChild), FindHeight(root->rightChild)) + 1;
}

bool ClientTree::IsBst(Client* root, int minValue , int maxValue)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->AccountNumber > minValue && root->AccountNumber < maxValue && IsBst(root->leftChild, minValue ,root->AccountNumber) && IsBst(root->rightChild,root->AccountNumber ,maxValue))
	{
		return true;
	}
	else {
		cout << "Binary Search Tree Broken!";
		return false; }
}





