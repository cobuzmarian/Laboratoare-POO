#include <iostream>
#include <string.h>
using namespace std;

class Object {
	public:
		void print() {
			cout << this << endl;
		}
		virtual int equals(Object &obj) {
			return this==&obj;
		}
		
};

int operator == (Object& ob1, Object &ob2) {
	return ob1.equals(ob2);
}

class String: public Object {
	char *s;
	public:
		String(char *str) {
			s = new char[strlen(str) + 1];
			strcpy(s,str);
		}
		int equals(Object &obj) {
			String &strobj = *(String*) &obj;
			return strcmp(s, strobj.s) == 0 ? 1:0;
		}
		String operator +(Object &obj2) {
			String &strobj2 = *(String*) &obj2;
			return strcat(s,strobj2.s);
		}
		void printS() {
			cout << s << endl;
		}
		
};
int main() {
	Object ob1;
	Object *ob2;
	ob2 = new Object;
	ob2->print();
	ob1.print();
	if(ob2->equals(ob1)) {
		cout <<"egale \n";
	}
	else {
		cout <<"nu-s egale \n";
	}
	String s1 ("unu"); String s2("unu"); 
	if ( s1==s2) 
		cout << "siruri egale \n"; 
	else 
		cout << "siruri diferite \n";
		
	String s3("unu");
	
	cout << endl << "siruri concatenate:" << endl;
	s1 + s2;
	s1.printS();
	
	if(s3.equals(s1) == 0)
		cout << "egale" <<endl;
	if(s3.equals(s1) < 0)
		cout <<"s2 mai mare"<<endl;
	if(s3.equals(s1) > 0)
		cout <<"s1 mai mare"<<endl;
	return 0;
}
