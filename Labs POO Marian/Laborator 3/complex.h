#include <iostream>
#include <cmath>

using namespace std;

class Complex {
	private:
		int real;
		int imag;
		
	public:
		Complex() {
			real=0;
	    		imag=0;
		}
		Complex(int a,int b) {
			real=a;
	    		imag=b;
		}
		Complex aduna(Complex& c) {
			Complex comp;
			comp.real = this->real + c.real;  
			comp.imag = this->imag + c.imag;
			return comp; 
		}
		Complex scade(Complex& c) {
			Complex comp;
			comp.real = this->real - c.real;
			comp.imag = this->imag - c.imag;
			return comp; 
		}
		Complex inmulteste(Complex& c) {
			Complex comp;
			comp.real = this->real * c.real;
			comp.imag = this->imag * c.imag; 
			return comp;
			
		}
		Complex putere(int p) {
			Complex comp;
			comp.real = pow(this->real, p);
			comp.imag = pow(this->imag, p);
			return comp;
			
		}
		void afiseazaComplex(void) {
			cout <<"Real: "<< this->real << endl << "Imag: " << this->imag << endl;
		}
		
};

