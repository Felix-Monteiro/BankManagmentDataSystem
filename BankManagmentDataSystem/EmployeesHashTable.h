#pragma once
#include <iostream>
#include <string>
#include "StaffInfoStr.h"

using namespace std;

class EmployeesHashTable
{
public:

	int size;
	StaffInfoStr** data;

	EmployeesHashTable(int size);
	void Display();
	int HashFunction(string key);
	void Insert(StaffInfoStr* item);
	StaffInfoStr* Delete(string key);
private:
};

