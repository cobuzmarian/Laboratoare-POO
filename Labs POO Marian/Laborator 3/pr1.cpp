#include "complex.h"

int main() {
	Complex a(1,1), b(2, 2);
	Complex c, d, e, f;
	cout<<"Complex a + Complex b = " <<endl;
	c = a.aduna(b);
	c.afiseazaComplex();
	
	cout<<"Complex a - Complex b = "<<endl;
	d = a.scade(b);
	d.afiseazaComplex();
	
	cout<<"Complex a * Complex b = "<<endl;
	e = a.inmulteste(b);
	e.afiseazaComplex();

	cout<<"Complex b la puterea 3 = "<<endl;
	f = b.putere(3);
	f.afiseazaComplex();
	return 0;
}
