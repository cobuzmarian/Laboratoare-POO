#include<iostream>
#include<string.h>

using namespace std;

class Object {
	public:
		void print() {
			cout<<this<<endl;
		};
		virtual int equals (Object& obj) {
			return this== &obj;
		} ;
};

int operator == ( Object& ob1, Object& ob2) {
	return ob1.equals(ob2);
}

class String:public Object {
		char *a;
	public:
		String(char *s="") {
			a=new char[strlen(s)+1];
			strcpy(a,s);
		};
		int equals(Object& obj) {
			String & sobj= *(String*) &obj;
			return strcmp (a, sobj.a)==0 ? 1:0;
		}
		void print() {
			cout<<a<<endl;
		};
		String operator + (String &s) {
			char *b;
	    	b=a;
	    	b=strcat(b,s.a);
	    	return(b);
		};
};

int main() {
	String a="Lab9",b="POO",c="";
	cout<<"Primul sir: ";
	a.print();
	cout<<"\nAl doilea sir: ";
	b.print();
	cout<<"\n";
	if(a.equals(b))cout<<"Sunt egale."<<endl;
	else cout<<"Nu sunt egale."<<endl;
	c=a+b;
	cout<<"\nRezultatul este: ";
	c.print();
	return 0;
}
