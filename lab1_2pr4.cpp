#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fisier ("fisier.txt");   
    int nrLinie = 0;
    string line;
    while (getline(fisier, line)) {
    	nrLinie++;
        cout << nrLinie << " " << line <<endl;
    }
    fisier.close();
    return 0;

}

