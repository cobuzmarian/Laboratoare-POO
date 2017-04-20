#include <iostream>

using namespace std;

class bitset {
	unsigned short *v;
	int bit;
	
	public:
		bitset() {
			bit = 16;
			v = new unsigned short[bit];
			for(int i = 0; i < bit; i++)
				v[i] = 0;
		}
		bitset(int dim) {
			bit = dim/16;
			v = new unsigned short[bit];
			for(int i = 0; i < bit; i++)
				v[i] = 0;
		}
		~bitset() {
			delete[] v;
		}
		bool contains(int x) {
			bitset aux;
			aux = (*this);
			return aux.v[x/16] & (1 << x%16);
		}
		bitset operator+ (int x) {
			bitset aux;
			aux = (*this);		
			aux.v[x/16] = aux.v[x/16] | (1 << x%16);
			return aux;
		}
		bitset operator- (int x) {
			bitset aux;
			aux = (*this);
			aux.v[x/16] = aux.v[x/16] & (~(1 << x%16));
			return aux;
		}
		friend ostream& operator<<(ostream &os, const bitset &a) {
			os <<"[ ";
			for (int f = 0; f < 16; f++){
         		if (a.v[f] != 0)
           		for (int g = 0; g < a.bit; g++)
             		if (a.v[f] & (1<<g))
               			os << 16*f+g << ' ';
       		}
       		os <<"]" <<endl;
       		return os;
		}
		void operator ==(bitset &a) {
			bitset aux;
			aux = (*this);
			if(aux.size() != a.size()) {
				cout <<"Multimile nu-s egale!" <<endl;
			}
			else {
				cout <<"Multimile sunt egale!" <<endl;
			}
		}
		bitset operator= (const bitset &a) {
			bitset aux;
			aux.bit = a.bit;
			aux.v = new unsigned short[bit];
			for(int i = 0; i < bit; i++) 
				aux.v[i] = a.v[i];
					
			bit = aux.bit;
			v = new unsigned short[bit];
			for(int i = 0; i < bit; i++) 
				v[i] = a.v[i];
						
			return aux;
		}
		int size() {
			int bitsize = 0;
			for(int i = 0; i < 16; i++) {
				for(int j = 0; j < bit; j++)
					if(v[j] & (1 << i))
						++bitsize;
			}
			return bitsize;
		}
		void isEmpty() {
			bitset aux;
			aux = (*this);
			if(aux.size()) {
				cout << "Multimea nu e vida!" <<endl;
			}
			else {
				cout <<"Multimea e vida!" <<endl;
			}
		}
		void toString() { // Afisare multime
			bitset aux;
			aux = (*this);
        	cout << "{ ";
        	for (int f = 0; f < 16; f++){
         		if (v[f] != 0)
           		for (int g = 0; g < aux.bit; g++)
             		if (v[f] & (1<<g))
               			cout << 16*f+g << ' ';
       		}
        cout << "}" << endl;
        }
			
};

int main() {
	bitset a, b, c;
	a = a + 1;
	a = a + 2;
	a = a + 3;
	a = a - 1;
	c = b + 1;
	cout << a;
	cout << c;
	c = c + 2;
	
	a == c;
	//a.toString();
	a.isEmpty();
	return 0;
	
}
