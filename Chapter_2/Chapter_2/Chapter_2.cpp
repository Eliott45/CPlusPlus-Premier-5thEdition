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

void exercise18() {
    int i, *p1 = &i;
    cout << "Enter i value: ";
    cin >> i;
    cout << "p1 = " << *p1 << " i also = " << i << endl;
}

void exercise20() {
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    cout << *p1 << endl; // 42 * 42 = 1764
}

void exercise21() {
    int i = 0;
    // (a) double* dp = &i; double to int will be error
    // (b) int *ip = i; int to int * will be error
    int *p = &i; // ~ p = i;

}


void exercise25() {
    // (a) int* ip, &rp = ip; It will be right: int* ip, *&rp = ip;
    int i, *ip = 0; // (b) i - variable int type, ip - pointer
    int* ip2, ip3;  // (c) ip2 - pointer, ip3 - varible 
}

void exercise26() {
    // (a) const int buf; Invalid, constant must have a value  
    int cnt = 0;
    const int sz = cnt;
    ++cnt; 
    // (d) ++sz; Constant cannot be changed 
}

void exercise27() {
    // (a) int i = -1, &r = 0; Invalid, reference non-constant value;
    // (b) int *const p2 = &i2; i2 variable does not exist 
    const int i = -1, &r = 0; 
    // (d) const int* const p3 = &i2; i2 variable does not exist 
    // (e) const int* p1 = &i2; i2 variable does not exist 
    // (f) const int &const r2; initializer required 
    // (g) const int i2 = i, &r = i; // multiple initialization 
}

int main()
{
    cout << "Exercise 3: " << endl;  exercise3();
    cout << "Exercise 9: " << endl;  exercise9();
    cout << "Exercise 13: " << endl;  exercise13();
    cout << "Exercise 17: " << endl;  exercise17();
    cout << "Exercise 18: " << endl;  exercise18();
    cout << "Exercise 20: " << endl;  exercise20();
    

}
