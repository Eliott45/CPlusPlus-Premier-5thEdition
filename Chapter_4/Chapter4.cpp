#include <iostream>
#include <limits>

using namespace std;

int exercise1() {
    return 5 + 10 * 20 / 2; // 105
}

/* Exercise 2
* vec.begin() = ((vec.begin)())
* vec.begin() + 1 = ( * ((vec.begin)())) + 1
*/

/* Exercise 3
* I think that is an acceptable trade-off.
*/


int exercise4() {
    return 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2; // 16 + 75 + 0 = 91
    // ((12/3) * 4) + (5 * 15) + ((24 % 4) / 2) 
}

void exercise5() {
    cout << -30 * 3 + 21 / 5 << endl; // (a) = -90 + 4.2 = -86
    cout << -30 + 3 * 21 / 5<< endl;  // (b) = -30 + 12.6 = -18
    cout << 30 / 3 * 21 % 5 << endl;  // (c) = 0
    cout << -30 / 3 * 21 % 4 << endl; // (d) = -2
}

string exercise6() {
    int i;
    cout << "Enter the number: ";
    cin >> i;
    return (i % 2 == 0) ? "Even" : "Odd";
}

void exercise7() {
    // Overflow is when the value of a variable is out of range. 
    int a = numeric_limits<int>::max();
    int b = numeric_limits<int>::min();
    cout << a + 1 << endl;
    cout << b - 1 << endl;
}


int main()
{
    cout << "Exercise 1: " << exercise1() << endl;
    cout << "Exercise 4: " << exercise4() << endl;
    cout << "Exercise 5: " << endl; exercise5();
    // cout << "Exercise 6: " << endl; cout << exercise6() << endl;
    cout << "Exercise 7: " << endl; exercise7();
}
