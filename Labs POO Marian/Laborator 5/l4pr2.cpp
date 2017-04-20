#include<iostream>
#include<vector>

using namespace std;

class IntSet {
	private:
		vector<int>v;
		int n;
	public:
		IntSet(int dim){
			n = dim;
		}
		int contains(int x) {
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
		void toString() {
			for(int i = 0; i < v.size(); i++) {
				cout << v[i] << " " ;
			}
			cout << endl;
		}
		
};


int main() {

	IntSet a(3);
	a.add(2);
	//a.toString();
	a.add(4);
	a.add(5);
	a.add(2);
	a.remove(6);
	a.toString();
	a.remove(2);
	a.remove(2);
	a.add(4);
	a.toString();
	return 0;
}
