#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int compare_str( const void *a, const void *b){
   string* obj = (string*)a;
   string* obj1 = (string*)b;
   return obj->compare(*obj1);
}
int main(){
    int size;
    cout <<"Introdu numarul de cuvinte: ";
    cin >> size;
    string mystring[size];
    cout <<"Introdu " << size << " cuvinte: ";
    for(int i = 0; i < size; i++)
    	cin >> mystring[i];
    	
    qsort(mystring, size, sizeof(string), compare_str);
    cout<<"Cuvinte sortate:" <<endl;
    for( int i=0; i<size; i++)
        cout << mystring[i] <<" ";
        
    cout << endl;
    return 0;
}
