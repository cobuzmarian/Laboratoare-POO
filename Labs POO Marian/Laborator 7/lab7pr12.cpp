#include<iostream>

using namespace std;


class CVector {
	public:
	int x, y;
	CVector();
	CVector(int, int);
	CVector operator + (CVector);
	CVector operator - (CVector);
	CVector operator = (CVector);
	CVector operator * (CVector);
};

CVector::CVector() {
	x = 0;
	y = 0;
}

CVector::CVector(int a, int b) {
	x = a;
	y = b;
}

CVector CVector::operator + (CVector param) {
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return (temp);
}

CVector CVector::operator - (CVector param) {
	CVector temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	return (temp);
}

CVector CVector::operator = (CVector param) {
	x = param.x;
	y = param.y;
	return *this;
} 

CVector CVector::operator *(CVector param) {
	CVector temp;
	temp.x = x * param.x;
	temp.y = y * param.y;
	return temp;
}

int main() {
	CVector a(3, 1);
	CVector b(1, 2);
	CVector c;
	CVector d;
	CVector e;
	CVector f;
	c = a + b;
	d = a - b;
	e = d;
	f = c * e;
	cout << c.x << "," << c.y << endl;
	cout << d.x << "," << d.y << endl;
	cout << e.x << "," << e.y << endl;
	cout << f.x << "," << f.y << endl;
	return 0;
}

