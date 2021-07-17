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


int main()
{
    cout << "Exercise 3: " << endl;  exercise3();
    cout << "Exercise 9: " << endl;  exercise9();

}
