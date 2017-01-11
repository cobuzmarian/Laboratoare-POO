#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

class Object {
public:
   virtual void print()
   {
       cout << this << ' ';
   }
   virtual int equals (Object& obj)
   {
    return this==&obj;
   }
} ;

 inline int operator == (Object& ob1, Object& ob2)
 {
    return ob1.equals(ob2);
 }


class Vector
{
  Object* * vec;   
  int n, nmax;    
public:

  Vector (int size)
  {
    vec=new Object* [nmax=size];
    n=0;
  }

  ~Vector()
  {
      delete[]vec;
  }
  void print ();

  void add (Object& obj)
  {
      vec[n++]= &obj;
  }

  int size() {
       return n;
       }

  Object & operator[] (int i)
  {
    return *vec[i];
  }

  int contains(Object &obj)
  {
      int q=0;
      for(int i=0;i<n;i++)
      if(vec[i]==&obj)
        q=1;
      return q;
  }
};

void Vector::print ()
{
    for (int i=0; i<n; i++)
    {
      vec[i]->print(); cout <<"  ";
    }
  cout << "\n";
}

class String1 : public Object
{
	public: char * str;
	String1(char * s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	~String1()
	{
	}
	void print()
	{
		cout << str << ' ';
	}
	int equals(Object& obj)
	{
		String1 & strobj = *(String1*)&obj;
		if(strcmp(str, strobj.str) == 0)
            return 1;
        else
            return 0;
	}
	String1 operator+ (String1 s)
	{
		char *temp;
		temp = new char[strlen(str)+ strlen(s.str)];
		strcpy(temp,str);
		strcat(str, s.str);
		String1 rez(temp);
		return rez;
	}
};

int main()
{
    char *sir=new char[50];
    char *sir2=new char[50];
    char *sir3=new char[50];
    sir="Acesta e ";
    sir2=" sirul ";
    sir3="necesar";
	String1 st1(sir2),str2(sir),str3(sir3);
    cout<<"Primul sir: ";
    st1.print();
    cout<<"Al doilea sir: ";
    st1.print();
    str2+st1;
    cout<<"Al treilea sir: ";
    str2.print();
    Vector a(10);
    a.add (st1);
    a.add(str2);
cout << endl<<"Afisare vector:";
 a.print();
 cout<<"Primul sir de comparat este: ";
 str3.print();
 if(a.contains(str3))
    cout<<"Vectorul contine sirul dat";
 else
    cout<<"Vectorul NU contine sirul dat";
cout<<"Al doilea de comparat este: ";
st1.print();
 if(a.contains(st1))
    cout<<"Vectorul contine sirul dat";
 else
    cout<<"Vectorul NU contine sirul dat";

 return 0;
}
