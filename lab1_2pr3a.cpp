#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include <cstdlib>

using namespace std;

int compare_str( const void *a, const void *b){
   string* s1 = (string*)a;
   string* s2 = (string*)b;
   return s1->compare(*s2);
}
int main() {
	string mystrings[100];
	ifstream fisier;
	fisier.open("fisier.txt");
	string word;
	int size = 0;
	while(fisier >> word) {
		mystrings[size] += word;
		size++;
	}
	fisier.close();
	cout <<"Nesortat:" <<endl;
	for(int i = 0; i < size; i++)
		cout << mystrings[i] << " ";
		

	qsort(mystrings, size, sizeof(string), compare_str);
	
	cout <<endl <<"Sortat:"<<endl;
	for(int i = 0; i < size; i++)
		cout << mystrings[i] << " ";
	
	cout << endl;

	return 0;
}
