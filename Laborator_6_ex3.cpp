#include<iostream>
#include<assert.h>
#include<conio.h>
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
	this->dmax = dmax; this->inc = inc;
	vec = new int[dmax]; d = -1;}

IntVec::IntVec(IntVec &a)
{
	d = a.d; dmax = a.dmax;
	inc = a.inc; vec = new int[dmax];
	for (int i = 0; i <= d; i++)
		vec[i] = a.vec[i];
}


IntVec::~IntVec()
{delete[] vec;}

void IntVec::add(int x)
{assert (d < dmax); vec[++d] = x;}

int IntVec::get(int poz)
{assert(poz >= 0 && poz <= d); return vec[poz];}

void IntVec::set(int poz, int x)
{assert(poz >= 0 && poz <= d); vec[poz] = x;}

void IntVec::remove(int poz)
{
	assert(poz >= 0 && poz <= d);
	for (int i = poz; i < d; i++)
		vec[i] = vec[i+1]; d--;
}

int IntVec::indexOf(int x)
{
	for (int i = 0; i <= d; i++)
		if (vec[i] == x)
			return i; return -1;
}

void IntVec::print(){
	cout << "[";
	for (int i = 0; i < d; i++)
		cout << vec[i];
        cout << ",";
	if (d >= 0)
		cout << vec[d]; cout << "]\n";
}


class Stiva{
	IntVec v;
	public:
		Stiva(){}
		void push(int x){
			cout << "Apelarea push(" << x << ")\n"; v.add(x);
		}
		void pop();
		int isEmpty(){
            return v.size() < 0;
            }
};

void Stiva::pop(){
	if (!isEmpty()){
		cout << " Pop extrage elementul: " << v.get(v.size()) << "\n"; v.remove(v.size());}
	else
		cout << "Pop nu extrage niciun element !\n";
}

int main(){
	Stiva a;
	a.push(11);
	a.push(7);
	a.push(2);
    a.pop();a.pop();a.pop();a.pop();
	getch();
}
