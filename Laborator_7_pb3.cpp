#include <iostream>
using namespace std;

class CDummy
{
private:
    static int n;
public:
    CDummy ()
    {
        n++; 
    };

    ~CDummy ()
    {
        n--;
    };

    static int readN()
    {
        return n;
    }

    static void writeN(int a)
    {
        n = a;
    }
};

int CDummy::n = 0;

int main () {
    CDummy a;
    CDummy b[5];
    CDummy * c = new CDummy;
    cout << CDummy::readN() << endl;
    delete c;
    cout << CDummy::readN() << endl;
    return 0;
}
