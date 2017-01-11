#include<iostream>

using namespace std;

class bitset{

public:
	unsigned short *v;
	int dim;

	bitset()
	{
		dim = 16;
		v = new unsigned short[16];
		
		for(int i = 0; i < 16; i++)
			v[i] = 0;
	}
	

	bitset(int dmax)
	{
		dim = dmax/16;
		v = new unsigned short[dim];
		
		for(int i = 0; i < dim; i++)
			v[i] = 0;
	}	
	
	~bitset()
	{
		delete[] v;
	}
	
	void operator =(const bitset &atribuit)
	{
		bitset temp;

		temp.dim = atribuit.dim;
		temp.v = new unsigned short[dim];
		
		for(int i = 0; i < dim; i++)
			temp.v[i] = atribuit.v[i];
		
		dim = temp.dim;
		v = new unsigned short[dim];
		
		for(int i = 0; i < dim; i++)
			v[i] = temp.v[i];
		
	}

	bitset operator +(bitset &termen)
	{
		bitset temp;
		if(termen.dim > dim)
		{
			temp = termen;
			
			for(int i = 0; i < dim; i++)
				temp.v[i] = temp.v[i] | v[i];
		}
		else {
			temp = (*this);
			
			for(int i = 0; i < termen.dim; i++)
				temp.v[i] = temp.v[i] | termen.v[i];
		     }

		return temp;
	}
	
	friend ostream& operator << (ostream &out, const bitset &shown)
	{
		unsigned short test;
	
		out << "\n[ ";
		
		for(int i = 0; i < 16; i++)
		{
			test = 1 << i;
			
			for(int j = 0; j < shown.dim; j++)
				if(test & shown.v[j]) out << j*16 + i << " ";
		}

		out << "]\n";
		return out;
	}

	bitset operator+ (int element)
	{
		bitset temp;
		temp = (*this);
		if(element/16 > dim) cout << "\nNu se poate adauga!\n";	
		else temp.v[element/16] = temp.v[element/16] | (1 << element%16);
		return temp;
	}
	
	bitset operator- (bitset &termen)
	{
		bitset temp;
		temp = (*this);
		unsigned short test;
		int t;
		dim > termen.dim ? t = termen.dim : t = dim;
		
		for(int i = 0; i < 16; i++)
		{
			test = 1 << i;
		
			for(int j = 0; j < t; j++)
				if( temp.v[j] & test && termen.v[j] & test)
					temp.v[j] -= test;
		}
		
		return temp;
	}

	bitset operator* (bitset &intersect)
	{
		unsigned short test;
		int t;
		dim > intersect.dim ? t = intersect.dim : t = dim;	

		bitset temp(t*16);

		for(int i = 0; i < 16; i++)
		{
			test = 1 << i;
		
			for(int j = 0; j < t; j++)
				if( v[j] & test && intersect.v[j] & test)
					temp.v[j] += test;
		}
		
		return temp;
	}

	int size()
	{
		int card = 0;
		unsigned short test;

		for(int i = 0; i < 16; i++)
		{
			test = 1 << i;
		
			for(int j = 0; j < dim; j++)
				if(v[j] & test)
					card++;
		}
		
		return card;
	}	

	bool contains(int val)
	{	
		if(val/16 > dim) 
		return 0;

		unsigned short test = 1 << val%16;
		return v[val/16] & test;
	}

	bool contains(bitset &verificat)
	{
		
		if(size() != verificat.size() )
			return 0;
		
		if(verificat.dim > dim)
		{
			for(int i = verificat.dim - 1; i >= dim; i--)
				if(verificat.v[i]) return 0;
		}
		else {
			for(int i = dim - 1; i >= verificat.dim; i--)
				if(v[i]) return 0; 
		}
		
		int t, ok = 0;
		dim > verificat.dim ? t = verificat.dim : t = dim;
		
		for(int i = 0; i < t; i++)
			if(v[i] == verificat.v[i])
				ok++;

		if(ok == t)
			return 1;

		return 0;
	}
	
	bool isEmpty()
	{	
		return !(size() );
	}


	bool operator == (bitset &verificat)
	{
		if(contains(verificat) && verificat.contains( (*this) ) )
			return 1;
		else return 0;
	}	
};


void greedy(bitset *c, int d, bitset S)
{
bitset M, A;
int imax, sizemax = 0;
M = c[0];

for(int i = 1; i < d; i++)
	M = M + c[i];

if(M*S == S)
{
	do{
		sizemax = 0;
		imax = 0;
                for(int i = 0; i < d; i++)
                {
                        A = S*c[i];
                        if(A.size() > sizemax)
                        {
                                imax = i;
                                sizemax = A.size();
                        }

                }

                cout << c[imax];

                S = S - c[imax];

                }while(!(S.isEmpty() ) );
}
else cout << "\nNu exista solutie!\n";

}

int main()
{
bitset test1, test2, test3;
test1 = test1 + 1;
test1 = test1 + 2;
test1 = test1 + 126;
cout << test1;

test2 = test2 + 12;
test2 = test2 + 78;
test2 = test2 + 253;
test2 = test2 + 111;
cout << test2;

test3 = test1 + test2;
cout << test3;

test3 = test3 - test2;
cout << test3;

test1 = test1 + 26;
cout << test1;

test3 = test3*test1;

cout << test3;

cout << test3.contains(126) << "\n";
cout << test3.contains(test1) << "\n";

bitset S, *C;
C = new bitset[5];

for(int i = 1; i < 6; i++)
S = S + i;


C[0] = C[0] + 2;
C[0] = C[0] + 5;

C[1] = C[1] + 2;
C[1] = C[1] + 3;
C[1] = C[1] + 4;

C[2] = C[2] + 3;
C[2] = C[2] + 4;
C[2] = C[2] + 5;

C[3] = C[3] + 1;
C[3] = C[3] + 3;
C[3] = C[3] + 4;

greedy(C, 4, S);

}
 