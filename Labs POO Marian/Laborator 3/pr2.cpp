#include "stiva.h"

int main() {
    Stiva s;
    Stiva d(2);
    d.Pop();
    d.isEmpty();
    s.Push(1);
    s.isEmpty();
    s.Pop();
    s.isEmpty();
    d.Pop();
    d.Pop();
    getchar();
    return 0;
}
