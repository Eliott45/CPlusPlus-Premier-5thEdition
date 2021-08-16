#include <iostream>
#include "Chapter6.h"

using namespace std;

int main() {
    cout << "SUK";
    int n;
    while (cin >> n)
        cout << n << "! = " << fact(n) << endl;

    return 0;
}