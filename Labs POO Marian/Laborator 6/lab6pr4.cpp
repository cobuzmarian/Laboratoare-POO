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

class Stiva {
	IntVec *s;
	public:
		Stiva() { 
			s = new IntVec();
		}
		void push(int x) {
			s->add(x);
		}
		void pop() {
			if(s->size() == 0) {
					cout<<"Stiva e goala, nu avem ce scoate!" <<endl;
					return;
				}
			s->remove(s->size());
		}
		void isEmpty() {
			if(s->size() == 0) {
				cout <<"Stiva goala!" <<endl;
			}
			else {
				cout<<"Stiva nu e goala!"<<endl;
			}
		}
};

int main() {
	Stiva s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.isEmpty();
	s.pop();
	s.pop();
	s.pop();
	s.isEmpty();
	s.pop();
	return 0;
}
