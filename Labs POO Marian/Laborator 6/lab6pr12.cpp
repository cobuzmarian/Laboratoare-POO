#include<iostream>

using namespace std;

class IntVec {
	int *vec;
	int d;
	int dmax;
	int inc;
	
	public:
		IntVec(int a=10, int b=10) {
			dmax = a;
			inc = b;
			d = 0;
			vec = new int[dmax];
		}
		IntVec(IntVec &b) {
			cout <<"Am copiat vectorul!" <<endl;
			d = b.d;
			dmax = b.dmax;
			inc = b.inc;
			vec = new int[dmax];
			for(int i = 0; i < d; i++)
				vec[i] = b.vec[i];
		}
		int size() {
			return d;
		}
		void add(int x) {
			if(d < dmax) {
				vec[d] = x;
				d++;
			}
			else {
				dmax = dmax + inc;
				vec[d] = x;
				d++;
			}
		}
		int get(int x) {
			cout <<"Elementul din pozitia " << x << " este: " << vec[x] <<endl;
			return 1;
		}
		void set(int x, int y) {
			cout <<"Am schimbat elementul din pozitia " << x << " cu " << y << endl; 
			vec[x] = y;
		}
		void remove(int x) {
			cout <<"Am scos elementul din pozitia " << x << " din vector" << endl;
			for(int i = x; i < d; i++) {
				vec[i] = vec[i+1];
			}
			--d;
		}
		int indexOf(int x) {
			for(int i = 0; i < d; i++) {
				if(vec[i] == x) {
					cout << "Indexul lui " << x << " este " << i << endl;
					return i;
				}
			}
			cout << "Elementul " << x << " nu se afla in vector!" << endl;
		}
		void print() {
			cout<<"[ ";
			for(int i = 0; i < d; i++) {
				cout << vec[i] << " ";
			}
			cout <<"]" << endl;
		}
};

int main() {
	IntVec a(10,10);
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(5);
	a.print();
	a.get(2);
	a.set(2, 4);
	a.print();
	a.remove(1);
	a.print();
	a.indexOf(5);
	a.print();
	IntVec b(a);
	cout <<"Afisare copie"<<endl;
	b.print();
	b.add(15);
	b.add(20);
	cout <<"Afisare vector B"<<endl;
	b.print();
	cout<<"Afisare vector A"<<endl;
	a.print();

	return 0;
}
