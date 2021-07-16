#include <iostream>
#include "Sales_item.h"

using namespace std;

int exercise1() {
    return 0;
}

int exercise2() {
    return -1;
}

string exercise3() {
    return "Hello, World";
}

int exercise4() {
    int a, b; 
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    return a * b;
}



void exercise6() {
    int v1, v2;
    cout << "Enter v1: ";
    cin >> v1;
    cout << "Enter v2: ";
    cin >> v2;
    cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;
}

void exercise8() {
    cout << "/*";
    cout << "*/";
    // cout << /* "*/" */; - It won't work due to incorrect nesting of comments 
    cout << /* "*/" /* "/*" */ << endl;
}

int exercise9() {
    int sum = 0, i = 50;
    while (i < 100) {
        sum += i;
        i++;
    }
    return sum;
}

void exercise10() {
    int i = 10;
    while (i >= 0) {
        cout << i << endl;
        i--;
    }
    cout << endl;
}

void exercise11() {
    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    while (a != b) {
        if (a > b) {
            cout << a-- << endl;
        }
        else {
            cout << a++ << endl;
        }
    }
    cout << a << endl;
}

int exercise12() {
    int sum = 0;
    for (int i = -100; i <= 100; ++i) {
        sum += i;
    }
    return sum; // 0
}

int exercise13() {
    int sum = 0;
    for (int i = 50; i < 100; i++) {
        sum += i;
    }
    return sum;
}

void exercise16() {
    int sum = 0, value = 0;
    while (cin >> value) {
        sum += value;
    }
    cout << "Sum is " << sum << endl;
}

void exercise19() {
    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    while (a != b) {
        if (a > b) {
            cout << b++ << endl;
        }
        else {
            cout << a++ << endl;
        }
    }
    cout << a << endl;
}

void exercise20() {
    Sales_item item1, item2;
    cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn()) // ex 21
    {
        cout << item1 + item2 << endl;
    }
}

int main()
{
    cout << "Exercise 1: " << exercise1() << endl;
    cout << "Exercise 2: " << exercise2() << endl;
    cout << "Exercise 3: " << exercise3() << endl;
    cout << "Exercise 4: " << exercise4() << endl;
    cout << "Exercise 6: " << endl; exercise6();
    cout << "Exercise 8: "; exercise8();
    cout << "Exercise 9: " << exercise9() << endl;
    cout << "Exercise 10: " << endl; exercise10();
    cout << "Exercise 11: " << endl; exercise11();
    cout << "Exercise 12: " << exercise12() << endl;
    cout << "Exercise 13: " << exercise13() << endl;
    // cout << "Exercise 16: "; exercise16();
    cout << "Exercise 19: " << endl; exercise19();
    cout << "Exercise 20: " << endl; exercise20();
}
