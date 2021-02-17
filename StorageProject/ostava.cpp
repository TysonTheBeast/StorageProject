#include "ostava.h"
#include "stvar.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void ostava::setMaxBrStvari()
{
	do
	{
		system("cls");
		cout << "Unesite max. broj stvari koje mogu stati u ostavu: ";
		cin >> this->maxBrStvari;
		cin.ignore();
	} while (maxBrStvari < 1);
}

int ostava::getMaxBrStvari()
{
	return this->maxBrStvari;
}

void ostava::spremiStvari()
{
	/*for (int i = 0; i < stvari.size(); i++)
	{
		s.brStvari++;
	}*/
	stvar::trenutnoBrStvari();
	if (getMaxBrStvari() == stvar::brStvari) // <=
	{
		cout << "Ostava je puna! Ne moze vise stvari stati!" << endl;
	}
	else
	{
		stvar s;
		int br = 0;
		s.unesiStvar();
		if (stvar::brStvari == 0)
		{
			if (s.getKolicina() > getMaxBrStvari())
			{
				cout << "Ostava ne moze skladistiti toliki broj stvari!" << endl;
				stvar::brStvari = s.getKolicina() - (s.getKolicina() - getMaxBrStvari());
				cout << "Visak: " << s.getKolicina() - getMaxBrStvari() << endl;
				s.smanjiKolicinu(s.getKolicina() - getMaxBrStvari());
				stvari.push_back(s);
			}
			else
			{
				cout << "Naziv predmeta: " << s.getNaziv() << endl;
				cout << "Kolicina: " << s.getKolicina() << endl;
				stvari.push_back(s);
				stvar::brStvari = s.getKolicina();
			}
		}
		else if (stvar::brStvari > 0)
		{
			for (unsigned int i = 0; i < stvari.size(); i++)
			{
				if (_strcmpi(this->stvari[i].getNaziv(), s.getNaziv()) == 0)
				{
					br++;
					cout << s.getNaziv() << " vec postoji u ostavi." << endl;
					if (stvar::brStvari + s.getKolicina() > getMaxBrStvari())
					{
						stvari[i].povecajKolicinu(s.getKolicina() - (stvar::brStvari + s.getKolicina() - getMaxBrStvari()));
						cout << "Kolicina je prevelika da bi stala u ostavu. Visak: " << stvar::brStvari + s.getKolicina() - getMaxBrStvari() << endl;
						stvar::brStvari = getMaxBrStvari();
						break;
					}
					else
					{
						stvari[i].povecajKolicinu(s.getKolicina());
						stvar::brStvari += s.getKolicina();
						cout << "Kolicina: " << stvari[i].getKolicina() << endl;
						break;
					}
				}
				/*else
				{
					if (stvar::brStvari + s.getKolicina() > getMaxBrStvari())
					{
						cout << "Kolicina je prevelika da bi stala u ostavu. Visak: " << stvar::brStvari + s.getKolicina() - getMaxBrStvari() << endl;
						s.smanjiKolicinu(stvar::brStvari + s.getKolicina() - getMaxBrStvari());
						stvari.push_back(s);
						stvar::brStvari = getMaxBrStvari();
						break;
					}
					else
					{
						stvari.push_back(s);
						stvar::brStvari += s.getKolicina();
						cout << "Kolicina: " << s.getKolicina() << endl;
						break;
					}
				}*/
			}
			if (br == 0)
			{
				if (stvar::brStvari + s.getKolicina() > getMaxBrStvari())
				{
					cout << "Kolicina je prevelika da bi stala u ostavu. Visak: " << stvar::brStvari + s.getKolicina() - getMaxBrStvari() << endl;
					s.smanjiKolicinu(stvar::brStvari + s.getKolicina() - getMaxBrStvari());
					stvari.push_back(s);
					stvar::brStvari = getMaxBrStvari();
				}
				else
				{
					stvari.push_back(s);
					stvar::brStvari += s.getKolicina();
					cout << "Kolicina: " << s.getKolicina() << endl;
				}
			}
		}
	}
}

void ostava::uzmiStvari()
{
	if (stvar::brStvari == 0)
	{
		cout << "Ostava je prazna! Ne mozete uzeti nista iz nje!" << endl;
	}
	else
	{
		char uzmiX[50];
		int kolX;
		int br = 0;
		cout << "Unesite stvar koju zelite da uzmete iz ostave: ";
		cin.getline(uzmiX, 50);
		cout << "Unesite kolicinu " << uzmiX << " koju zelite da uzmete iz ostave: ";
		cin >> kolX;
		// sve iznad mogao zamijeniti sa stvar s; s.unesiStvar();
		cin.ignore();
		if (kolX > stvar::brStvari)
		{
			cout << "[GRESKA] Unesena kolicina premasuje ukupnu kolicinu ostave!" << endl;
		}
		else
		{
			for (int i = 0; i < stvari.size(); i++)
			{
				if (_strcmpi(uzmiX, stvari[i].getNaziv()) == 0)
				{
					br++;
					if (kolX == stvari[i].getKolicina())
					{
						cout << "Unesena kolicina je jednaka onoj koja se nalazi u ostavi!" << endl;
						cout << "Trenutna kolicina koju uzimate: " << stvari[i].getKolicina() << endl;
						stvar::brStvari = stvar::brStvari - stvari[i].getKolicina();
						stvari.erase(stvari.begin() + i);
						break;
					}
					else if (kolX > stvari[i].getKolicina())
					{
						cout << "[GRESKA] Unesena kolicina se ne nalazi u ostavi!" << endl;
						cout << "Trenutna kolicina koju uzimate: " << stvari[i].getKolicina() << endl;
						stvar::brStvari = stvar::brStvari - stvari[i].getKolicina();
						stvari.erase(stvari.begin() + i);
						break;
					}
					else
					{
						stvari[i].smanjiKolicinu(kolX);
						stvar::brStvari = stvar::brStvari - kolX;
						cout << "Uzeli ste " << kolX << " " << uzmiX << ". " << endl;
						cout << "Ostalo je: " << stvari[i].getKolicina() << endl;
						break;
					}
				}
				/*else
				{
					cout << uzmiX << " ne postoji u ostavi!" << endl;
				*/
			}
			if (br == 0)
			{
				cout << uzmiX << " ne postoji u ostavi!" << endl;
			}
		}
	}
}

void ostava::ispisOstave()
{
	if (stvari.size() == 0)
	{
		system("cls");
		cout << "Ostava je prazna!" << endl;
	}
	else
	{
		system("cls");
		for (unsigned int i = 0; i < stvari.size(); i++)
		{
			cout << "Naziv predmeta: " << stvari[i].getNaziv() << endl;
			cout << "Kolicina predmeta: " << stvari[i].getKolicina() << endl;
			cout << "---------------------------------" << endl;
		}
	}
}

void ostava::pretragaStvari()
{
	char pretX[50];
	cout << "Unesite stvar za pretrazivanje: ";
	cin.getline(pretX, 50);
	bool check = false;
	int temp = 0;
	for (unsigned int i = 0; i < stvari.size(); i++)
	{
		if (_strcmpi(pretX, this->stvari[i].getNaziv()) == 0)
		{
			temp = i;
			check = true;
			break;
		}
		else
		{
			check = false;
		}
	}
	if (check == true)
	{
		cout << stvari[temp].getNaziv() << " postoji u ostavi. " << endl;
		cout << "Kolicina: " << stvari[temp].getKolicina() << endl;
	}
	else
	{
		cout << pretX << " ne postoji u ostavi. " << endl;
	}
}

ostava::ostava()
{
	this->setMaxBrStvari();
	cout << "Ostava kreirana!" << endl;
	system("pause");
	system("cls");
}

ostava::~ostava()
{
}
