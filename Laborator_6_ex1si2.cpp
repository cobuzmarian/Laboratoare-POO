#include<iostream>
#include<assert.h>
using namespace std;

class IntVec
{
	int *vec;
	int d;
	int dmax;
	int inc;
	public:
		IntVec(int,int);
		IntVec(IntVec &);
		~IntVec();
		int size(){return d;}
		void add(int);
		int get(int);
		void set(int,int);
		void remove(int);
		int indexOf(int);
		void print();
};

IntVec::IntVec(int dmax = 10, int inc = 10)
{
	this->dmax = dmax;
	this->inc = inc;
	vec = new int[dmax];
	d = -1;	
}

IntVec::IntVec(IntVec &v)
{
	d = v.d;
	dmax = v.dmax;
	inc = v.inc;
	vec = new int[dmax];
	for (int i = 0; i <= d; i++)
		vec[i] = v.vec[i];
}


IntVec::~IntVec()
{
	delete[] vec;
}

void IntVec::add(int x)
{
	assert (d < dmax);
	vec[++d] = x;
}

int IntVec::get(int poz)
{
	assert(poz >= 0 && poz <= d);
	return vec[poz];	 
}

void IntVec::set(int poz, int x)
{
	assert(poz >= 0 && poz <= d);
	vec[poz] = x;
}

void IntVec::remove(int poz)
{
	assert(poz >= 0 && poz <= d);
	for (int i = poz; i < d; i++)
		vec[i] = vec[i+1];
	d--;	
}

int IntVec::indexOf(int x)
{
	for (int i = 0; i <= d; i++)
		if (vec[i] == x)
			return i;
	return -1;	
}

void IntVec::print()
{
	cout << "[";
	for (int i = 0; i < d; i++)
		cout << vec[i] << ",";
	if (d >= 0)
		cout << vec[d];
	cout << "]\n";
}


int main()
{
	IntVec a(10,10);	
	a.add(3);
	a.add(2);
	a.add(5);
	a.add(7);
	a.add(1);
	a.add(10);
	cout << "vectorul este:";
	a.print();
	cout << "a[1]=" << a.get(1);
	a.set(2,20);
	cout << "\n dupa modificarea lui a[2]:";			
	a.print();
	a.remove(a.indexOf(1));
	cout << "dupa eliminarea numarului 1:";
	a.print();
	IntVec b(a); 
	b.set(2,3);
	cout << "Dupa copierea si modificarea copiei:\n";
	cout << "Vectorul corespunzator a:";
	a.print();
	cout << "Vectorul corespunzator b:";
	b.print();
}
