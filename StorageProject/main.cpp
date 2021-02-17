#include <iostream>
#include "ostava.h"

using namespace std;

int main()
{
	int x;
	ostava o;
	do
	{
		system("cls");
		cout << "|| OSTAVA ||" << endl;
		cout << "1. Spremi stvar" << endl;
		cout << "2. Uzmi stvar" << endl;
		cout << "3. Ispis ostave" << endl;
		cout << "4. Pretraga stvari u ostavi" << endl;
		cout << "5. Kraj" << endl;
		cout << "Izbor: ";
		cin >> x;
		cin.ignore();
		if (cin.fail())
		{
			cin.ignore();
			cin.clear();
		}
		else
		{
			if (x == 1)
			{
				o.spremiStvari();
				system("pause");
			}
			else if (x == 2)
			{
				o.uzmiStvari();
				system("pause");
			}
			else if (x == 3)
			{
				o.ispisOstave();
				system("pause");
			}
			else if (x == 4)
			{
				o.pretragaStvari();
				system("pause");
			}
		}
	} while (x != 5);
	return 0;
}