#include "stvar.h"
#include <iostream>
#include <cstring>

using namespace std;

int stvar::brStvari = 0;

void stvar::setNaziv()
{
	cout << "Unesite naziv stvari za skladistenje: ";
	cin.getline(this->naziv, 50);
}

void stvar::setKolicina()
{
	cout << "Unesite kolicinu stvari: ";
	cin >> this->kolicina;
	cin.ignore();
}

char* stvar::getNaziv()
{
	return this->naziv;
}

int stvar::getKolicina()
{
	return this->kolicina;
}

void stvar::unesiStvar()
{
	cout << "|| Unos stvari ||" << endl;
	setNaziv();
	setKolicina();
}

void stvar::povecajKolicinu(int a)
{
	this->kolicina = this->kolicina + a;
}

void stvar::smanjiKolicinu(int a)
{
	this->kolicina = this->kolicina - a;
}

void stvar::trenutnoBrStvari()
{
	cout << "Na stanju je trenutno " << stvar::brStvari << " stvari." << endl;
}

stvar::stvar()
{
	strcpy_s(this->naziv, "Nova stvar");
	this->kolicina = 0;
}

stvar::~stvar()
{
}
