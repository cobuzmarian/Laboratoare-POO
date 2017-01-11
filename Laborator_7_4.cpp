#include <iostream.h>
class CSquare;

class CRectangle
{
    int width, height;
public:
    CRectangle CRectangle(int a, int b)
    {
        a = width;
        b = height;
        return *this;
    }
    int area (void)
    {
        return (width * height); 
    }
    friend class CSquare;
};
class CSquare
{
private:
    int side;
public:
    void set_side (int a)
    {
        side=a;
    }
    int area(void)
    {
        return (side*side);
    }
    void convert (CRectangle cr)
    {
        side = cr.width + cr.length;
    }
    friend class CRectangle;
};
void CRectangle::convert (CSquare a)
{
    width = a.side;
    height = a.side;
}

int main ()
{
    CSquare sqr;
    CRectangle rt;
    sqr.set_side(4);
    rt.convert(sqr);
    int a;
    cout << rt.area();
    return 0;
}
