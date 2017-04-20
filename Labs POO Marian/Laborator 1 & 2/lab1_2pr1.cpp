#include<iostream>

using namespace std;

int main() {
	int intreg;
	char caracter;
	string sir;
	
	cout <<"Introdu un nr intreg: ";
	cin >> intreg;
	cout <<"Introdu un caracter: ";
	cin >> caracter;
	cout <<"Introdu un sir de caractere: ";
	cin >> sir;
	
	cout << endl <<"Numarul introdus este: " << intreg << endl;
	cout <<"Caracterul introdus este: " << caracter << endl;
	cout <<"Sirul de caractere introdus este: " << sir << endl;
	
	cout << endl << "[Afisare pointeri]" << endl;
	int *pInt;           //pointer la intreg
	char *pChar;         //pointer la char
	string *pSir;        //pointer la sir
	pInt = &intreg;      //pInt pointeaza la adresa lui intreg
	pChar = &caracter;   //pChar pointeaza la adresa caracterului introdus
	pSir = &sir;         //pSir pointeaza la adresa sirului introdus mai sus
	
	cout <<"Afisare pointer la intregul dat: " << *pInt << endl;
	cout <<"Afisare pointer la caracterul dat: " << *pChar << endl;
	cout <<"Afisare pointer la sirul dat: " << *pSir << endl;

	return 0;
}
