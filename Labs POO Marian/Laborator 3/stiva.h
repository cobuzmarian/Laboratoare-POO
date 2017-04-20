#include<iostream>
#define MAX 100

using namespace std;

class Stiva {

    private:
        int        data[MAX];
        int        size;

    public:
        Stiva() {       // Constructor
            size = 0;
        }
        Stiva(int a) {
            size = a;
        }
       void Push(int a) {

            if (size < MAX)
                data[size++] = a;
            else
                cout << "Stiva e plina " << endl;
        }
        int Pop() {

            if (size == 0) {
                cout <<"Stiva e goala, nu avem ce scoate!"<<endl;
                return 0;
            }
            else {
                return data[size--];
            }
        }
        void isEmpty() {
            if (size == 0) {
                cout << "Stiva e goala" << endl;
            }
            else {   
                cout << "Stiva nu e goala" << endl;
            }
        }
};