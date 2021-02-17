#pragma once
class stvar
{
private:
	char naziv[50];
	int kolicina;
public:
	static int brStvari; // = 0;
	void setNaziv();
	void setKolicina();
	char* getNaziv();
	int getKolicina();
	void unesiStvar();
	void povecajKolicinu(int a);
	void smanjiKolicinu(int a);
	static void trenutnoBrStvari();
	stvar();
	~stvar();
};