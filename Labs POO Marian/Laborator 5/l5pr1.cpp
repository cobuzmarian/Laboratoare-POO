#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class BitSet {
        public:
        	char v[10];
			void Set(int x) {
				printf("Am adaugat %d!\n", x);
				v[x/8] |= (1 << (7-x%8));
			}
			void Clear(int x) {
				printf("Am sters %d!\n", x);
				v[x/8] &= ~(1 << (7-x%8));
			}
			void Contains(int x) {
				if(v[x/8] &= (1 << (7-x%8))) {
					printf("DA Contine pe %d!\n", x);
				}
				else {
					printf("Nu Contine pe %d!\n", x);
				}
			}
			void toString() { 
				printf("---------------\n");  	
    			for (size_t i = 0; i < 8; i++) {
        			for (short j = 7; j >= 0; j--) {
            			printf("%d ", (v[i] >> j) & 1);
        			}
        			printf("\n");
   				}
   				printf("---------------");
   				printf("\n");
    		}	
};

class IntSet: public BitSet {
	private:
		vector<int>v;
		int n;
	public:
		IntSet() {
			n = 0;
		}
		IntSet(int dim){
			n = dim;
		}
		int contine(int x) {
			for(int i = 0; i < v.size(); i++) {
				if(v[i] == x) {
					cout << "Vectorul contine numarul " << x << endl;
					return 1;
				}
			}
			cout <<"Vectorul nu contine numarul " << x << endl;
			return 0;
		}
		void add(int x) {
			for(int i = 0; i < v.size(); i++) {
				if(v[i] == x) {
					cout << "Elementul este continut deja!" <<endl;
					return;
				}
			}
			if(v.size() < n) {
				v.push_back(x);
			}
				else {	
					cout<<"Vector plin!"<<endl;
			}
		}
		void remove(int x) {
			int aux;
			int gasit = 0;
			for(int i = 0; i < v.size(); i++) {
				if(v[i] == x) {
					aux = i;
					gasit = 1;
				}
			}
			if(gasit) {
				 v.erase (v.begin()+aux);
			}
			else{
				cout<<"Elementul nu se afla in vector!" <<endl;
			}
		}
		void printInt() {
			for(int i = 0; i < v.size(); i++) {
				cout << v[i] << " " ;
			}
			cout << endl;
		}
		
};

int main()
{
        BitSet a;
        a.Set(6);
        a.Set(4);
        a.Set(9);
        a.toString();
        a.Clear(6); 
        a.Contains(4);
        a.Clear(4);
        a.Contains(4);
        a.Set(19);
        a.toString();
        cout<<"IntSet" <<endl;
		IntSet b;
		b.Set(9);
		b.Set(1);
		b.Contains(9);
		b.toString();
		b.Clear(9);
		b.Contains(9);
		b.toString();
		
		return 0;   
}
