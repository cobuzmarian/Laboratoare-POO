#include <iostream>
#include <stdio.h>
#include<conio.h>
using namespace std;

class CVector { 
public:
    int x, y;
    CVector (){};
    CVector (int, int);
    CVector operator - (CVector);
    CVector& operator = (CVector);
};

CVector::CVector (int a, int b)
{
x = a;
y = b;
}

CVector CVector::operator - (CVector param)
{
CVector temp;
temp.x = x - param.x;
temp.y = y - param.y;
return (temp);
}

CVector& CVector::operator=(const CVector param)
{
    x = param.x;
    y = param.y;
    return *this;
}

int main ()
{
CVector a (3, 1);
CVector b (1, 2);
CVector c;
CVector d;
c = a - b;
cout << c.x << "," << c.y << endl;
d = c;
cout << d.x << "," << d.y << endl;
getch();
return 0;
}
