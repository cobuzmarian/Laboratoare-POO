#include<iostream>
#include<vector>
using namespace std;

class IntSet {
	private:
		int n;
		int *v;
		int nr = 0;
	public:
		IntSet() {
		}
		IntSet(int dim){
			
			n = dim;
			v = new int[dim];

		}
		IntSet contains(int x) {
			for(int i = 0; i < nr; i++) {
				if(v[i] == x) {
					cout <<"Vectorul contine pe " << x << " !" <<endl;
					return 1;
				}
			}
			cout <<"Vectorul nu contine pe " << x << " !" <<endl;
			return 0;
		}
		IntSet add(int x) {
			for(int i = 0; i < nr; i++) {
				if(v[i] == x) {
					cout << "Elementul " << x << " este continut deja!" <<endl;
					return 0;
				}
			}
			if(nr >= n) {
				cout << "Vector plin!" <<endl;
				return 0;
			}
			v[nr] = x;
			nr++;
		}
		IntSet remove(int x) {
			int aux;
			for(int i = 0; i < nr; i++) {
				if(v[i] == x) {
					aux = i;
				}
			}
			if(v[aux] != x) {
				cout << "Vectorul nu contine pe " << x << "!" <<endl;
				return 0;
			}
			else {
				for(int i = aux - 1; i < nr - 1; i++) {
					v[i] = v[i+1];
				}
			nr--;
			cout <<"Am scos elementul " << x << " din vector!" <<endl;
			}
		}
		IntSet toString() {
			cout <<"Vectorul contine: ";
			for(int i = 0; i < nr; i++) {
				cout << v[i] << " " ;
			}
			cout << endl;
		}
		
};

int main() {

	IntSet a(4);
	a.add(2);
	a.toString();
	a.add(4);
	a.add(5);
	a.add(2);
	//cout<<"ha";
	a.remove(6);
	a.toString();
	a.remove(2);
	a.add(4);
	a.toString();
	a.add(19);
	a.add(10);
	a.toString();
	a.contains(19);
	a.contains(33);
	a.add(33);
	return 0;
}
