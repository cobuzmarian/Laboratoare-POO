#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	ifstream fisier;
	ofstream fisier2;
	fisier.open("fisier.txt");
	fisier2.open("fisier_ex2.txt");
	string word;
	while(fisier >> word) {
		fisier2 << word << endl;
	}
	fisier2.close();
	fisier.close();
	
	return 0;	
}
