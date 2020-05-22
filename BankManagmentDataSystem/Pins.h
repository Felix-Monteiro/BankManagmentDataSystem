#pragma once

#include <iostream>

using namespace std;

class Pins
{
public:
	int key;
	string name;
	Pins(int key, string name) :key(key), name(name) {}
	~Pins() {}

	bool operator>(const Pins& rhd) {
		return this->key > rhd.key;

	}

private:
};

