#pragma once
#include "stvar.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class ostava
{
private:
	vector<stvar> stvari;
	int maxBrStvari;
public:
	void setMaxBrStvari();
	int getMaxBrStvari();
	void spremiStvari();
	void uzmiStvari();
	void ispisOstave();
	void pretragaStvari();
	ostava();
	~ostava();
};
