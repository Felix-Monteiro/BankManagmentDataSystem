#include "EmployeesHashTable.h"

EmployeesHashTable::EmployeesHashTable(int size)
{
	this->size = size;
	data = new StaffInfoStr * [size]; //array of Staff Info pointers
	for (int i = 0; i < size; i++)
		data[i] = NULL;
}

void EmployeesHashTable::Display()
{
	for (int i = 0; i < size; i++)
		if (data[i] != NULL)
			cout << "Staff Member ID: " << data[i]->key << "\tEmployee Name: " << data[i]->name <<"\tYears of Service: "<<data[i]->years<< endl;
}

int EmployeesHashTable::HashFunction(string key)
{
	int ASCIItot = 0;
	for (int i = 0; i < key.length(); i++) {
		ASCIItot += (int)key[i];
	}
	return ASCIItot % size;
}

void EmployeesHashTable::Insert(StaffInfoStr* item)
{
	string key = item->key;
	int hash = HashFunction(key);
	while (data[hash] != NULL) {
		++hash;
		hash %= size;
	}
	data[hash] = item;
}


StaffInfoStr* EmployeesHashTable::Delete(string key)
{
	int hash = HashFunction(key);
	while (data[hash] != NULL) {
		if (data[hash]->key == key) {
			StaffInfoStr* itemToDelete = data[hash];
			data[hash] = NULL;
			return itemToDelete;
		}
		hash++;
		hash = hash % size;
	}
	return NULL;
}
