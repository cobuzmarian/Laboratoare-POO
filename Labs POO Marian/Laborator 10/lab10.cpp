#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

class Object {
	public:
		virtual void print() {
			cout << this << " ";
		}
		virtual int equals(Object &obj) {
			return this==&obj;
		}
		
};

inline int operator == (Object& ob1, Object &ob2) {
	return ob1.equals(ob2);
}

class String : public Object
{
	public: char * str;
	String(char * s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	~String()
	{
	}
	void print()
	{
		cout << str << " ";
	}
	int equals(Object& obj)
	{
		String & strobj = *(String*)&obj;
		if(strcmp(str, strobj.str) == 0)
            return 1;
        else
            return 0;
	}
	String operator+ (String s)
	{
		char *temp;
		temp = new char[strlen(str)+ strlen(s.str)];
		strcpy(temp,str);
		strcat(str, s.str);
		String rez(temp);
		return rez;
	}
};

class Vector {
	Object* *vec;
	int n, nmax;
	public:
		Vector(int size) {
		vec = new Object* [nmax=size];
		n = 0;
		}
		~Vector() {
			delete [] vec;
		}
		void add(Object &p) {
			vec[n++] = &p;
		}
		Object* operator[] (int i) {
			assert (i < n);
			return vec[i];
		}
		int size() {
			return n;
		}
		void print();
		int contains(Object & ob) {
			for(int i = 0; i < n; i++) {
				if(vec[i]->equals(ob)) {
					return 1;
				}
			}
			return 0;
		}
		

};
void Vector::print() {
	for(int i = 0; i < n; i++) {
				vec[i]->print(); cout << " ";
			}
			cout << endl;
}
int main() {
	Vector a(10);
	Vector b(10);
	char *sir=new char[50];
    char *sir2=new char[50];
    char *sir3=new char[50];
    sir="Laborator";
    sir2="POO";
    sir3="2016";
	String lab(sir);
	String poo(sir2);
	String an(sir3);
	b.add(lab);
	
	if(b.contains(lab)) {
		cout <<"vectorul b contine sirul lab" <<endl;
	}
	else {
		cout <<"vectorul nu contine sirul lab" <<endl;
	}
	a.add(lab);
	a.add(poo);
	a.add(an);
	if(b.contains(poo)) {
		cout <<"vectorul b contine sirul poo" << endl;
	}
	else {
		cout <<"vectorul b nu contine sirul poo" << endl;
	}
	for(int i = 0; i < a.size(); i++) {
		String *vechar = (String*)a[i];
		vechar->print();
	}
	cout << endl;
	a.print();
	cout << endl;
	return 0;
}
