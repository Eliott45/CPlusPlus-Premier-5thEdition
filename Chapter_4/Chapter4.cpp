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

/* Exercise 8
* The logical AND and OR operators follow the short-circuit evaluation strategy. Which means:
* they always evaluate their left operand before the right,
* the right operand is evaluated if and only if the left operand does not determine the result.
* The equality operator evaluates both the left operand and the right operand, then compares those values. 
* The order of evaluation of the two operands is undefined.
*/

/// <summary>
/// The condition cp && *cp means if cp is not a null pointer and the object pointed by cp is not null, 0 or can be converted to false.
/// </summary>
int exercise9() {
    const char* cp = "Hello World";
    if (cp && *cp) {
        return 1;
    }
    else {
        return 0;
    }
}

void exercise10() {
    int i;
    while (cin >> i && i != 42);
}

void exercise11() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b && b > c && c > d) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

/* Exercise 12
* i != j < k
* j < k is bool
* i != true|false is i != 1|0
*/

void exercise13() {
    int i; double d;
    d = i = 3.5;
    cout << " i = " << i << " d = " << d << endl;// d = 3, i = d
    i = d = 3.5;
    cout << " i = " << i << " d = " << d << endl; // i = 3, d = 3.5
}

/* Exercise 14
* if (42 = i) will be error
* if (i = 42) i will be = 42
*/

void exercise15() {
    double dval; int ival; int* pi;
    // dval = ival = pi = 0;
    // the type of `pi` is `int *` which cannot be converted to `int`
    dval = ival = 0;
    pi = 0;
}

/* Exercise 16
* (a) if(p = GetPtr() != 0) => ((p = getPtr()) != 0)
* (b) if (i = 1024) => if (i == 1024) ?
*/

int main()
{
    cout << "Exercise 1: " << exercise1() << endl;
    cout << "Exercise 4: " << exercise4() << endl;
    cout << "Exercise 5: " << endl; exercise5();
    // cout << "Exercise 6: " << endl; cout << exercise6() << endl;
    cout << "Exercise 7: " << endl; exercise7();
    cout << "Exercise 9: " << exercise9() << endl;
    // cout << "Exercise 10: " << endl; exercise10();
    // cout << "Exercise 11: " << endl; exercise11();
    cout << "Exercise 13: " << endl; exercise13();

}
