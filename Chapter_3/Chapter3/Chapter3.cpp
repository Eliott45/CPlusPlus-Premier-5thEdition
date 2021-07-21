#include <iostream>

using namespace std;

// Exercise 1 in Chapter 3
int exercise1_9() {
    int sum = 0, i = 50;
    while (i < 100) {
        sum += i;
        i++;
    }
    return sum;
}

int main()
{
    cout << "Exercise 1: Sum = " << exercise1_9() << endl;
}

