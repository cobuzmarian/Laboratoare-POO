#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>

using namespace std;
class BitSet{
	public:
	char v[10];
	BitSet()
	{
	 for(int i = 0; i < 10; i++)
	   {
		v[i] = 0;
	   }
	}
	void Set(int x)
	{
	char c;
	c = 0x1;
	c = c << 7 - x%8;
	v[x/8] = v[x/8] | c;
	}
	void Clear(int x)
	{
	char c;
	c = 0xFF;
	c = c - pow(2, 7 - x%8);
	v[x/8] = v[x/8] & c;
	}
	bool incl(int x)
	{
	char c;
	c = 0x1;
	c = c << 7 - x%8;
	if(v[x/8] & c)
	return 1;
	else return 0;
	}	
	void toString()
	{
	char c;
	cout << "\n\n";
	for(int j = 0; j < 10; j++)
	{	
		for(int i = 0; i <= 7; i++)
		{
			c = pow(2,i);
			if(v[j] & c)
			cout << j*8 + 7 - i << "\n";			
		}	
	}
	}
};


int main()
{
BitSet x;
int cit = 1;
while(cit)
{
cin >> cit;
cout << "\n";
x.Set(cit);
}
cout << "de sters?";
cin >> cit;
x.Clear(cit);
cout << "include?";
cin >> cit;
if(x.incl(cit) )
cout << "y";
else cout << "n";
x.toString();
return 0;
}
