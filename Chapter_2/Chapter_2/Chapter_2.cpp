#include <iostream>

using namespace std;

void exercise3() {
    unsigned u = 10, u2 = 42;
    cout << u2 - u << endl; // 32
    cout << u - u2 << endl; // 4294967264 
    int i = 10, i2 = 42;
    cout << i2 - i << endl; // 32
    cout << i - i2 << endl; // -32
    cout << i - u << endl; // 0
    cout << u - i << endl; // 0
}

void exercise9() { 
    // cin >> int input_value;  
    int input_value;
    cin >> input_value;

    // int i = { 3.14 }; - conversion from 'double' to 'int' requires a narrowing conversion
    double i = { 3.14 };

    double wage, salary;
    salary = wage = 9999.99; 

    // int i2 = 3.14; - conversion from 'double' to 'int' requires a narrowing conversion
    double i2 = 3.14;

}

void exercise11() {
    // extern int ix = 1024; - An initializer is not allowed on a local declaration of an extern variable	
    int iy; // defenition 
    extern int iz; // declaration
}

void exercise12() {
    // (a) int double = 3.14;
    int _;
    // (c) int catch-22;
    // (d) int 1_or_2 = 1;
    double Double = 3.14;
}

void exercise13() {
    int i = 100, sum = 0;
    for (int i = 0; i != 10; i++) {
        sum += i;
    }
    cout << i << " " << sum << endl; // 100 45
}

void exercise15() {
    // (a) int ival = 1.01;
    int ival = 1;
    // (b) int &rval1 = 1.01;
    int &rval2 = ival;
    // (d) int &rval3;
}

void exercise16() {
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;

    r2 = 3.14159; // d = r2; d = 3.14159
    r2 = r1; // d = i(0); d = 0
    i = r2; // i = d; i = 0;
    r1 = d; // i = d; i = 0;
    // i = 0, d = 0;
}

void exercise17() {
    int i, &ri = i;
    i = 5; ri = 10; // i = 10, ri = 10;
    cout << i << " " << ri << endl;
}

int main()
{
    cout << "Exercise 3: " << endl;  exercise3();
    cout << "Exercise 9: " << endl;  exercise9();
    cout << "Exercise 13: " << endl;  exercise13();
    cout << "Exercise 17: " << endl;  exercise17();
 
}
