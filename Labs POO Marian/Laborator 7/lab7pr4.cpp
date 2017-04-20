#include<iostream>

using namespace std;

class CSquare;
class CRectangle {
	int width, height;
	public:
		CRectangle(int, int);
		void set_values(int, int);
		int area(void) {
			return (width*height);
		}
		friend class CSquare;
};

CRectangle::CRectangle(int a, int b) {
	width = a;
	height = b;
}

class CSquare {
	private:
		int side;
	public:
		void set_side(int a) {
			side = a;
		}
		int area(void);
		void convert (CRectangle a);
};

int CSquare::area() {
	return (side*side);
}

void CSquare::convert(CRectangle a) {
	side = a.width + a.height;
}

int main () { 
	CSquare sqr; 
	CSquare pat;
	CRectangle rt(4,4); 
	sqr.convert(rt);
	cout << sqr.area() << endl;
	return 0;
}
