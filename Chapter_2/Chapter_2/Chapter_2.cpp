#include <iostream>
#include <string>
#include "Sales_data.h" // exercise 42

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

void exercise30_31() {
    int i;

    const int v2 = 0;  // top-level const 
    int v1 = v2; 
    int *p1 = &v1, & r1 = v1;
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;
    // p2 - low-level const, p3 - low-level and top-level const, r2 - low-level const

    r1 = v2; 
    // p1 = v2; // low-level const doesn't match 
    p2 = p1;  
    //p1 = p3;  // low-level const doesn't match
    p2 = p3;  
}

void exercise32() {
    //int null = 0, *p = null;  
    int *p = nullptr;
}

void exercise33_34() {
    int i = 0, &r = i;
    auto a = r; // int
    
    const int ci = i, & cr = ci;
    auto b = ci; // int 
    auto c = cr; // int
    auto d = &i; // int*
    auto e = &ci; // const int*

    const auto f = ci; // const int

    auto &g = ci; // const int&

    cout << "a before: " << a << endl;
    a = 42;
    cout << "a after: " << a << endl;

    cout << "b before: " << b << endl;
    b = 42;
    cout << "b after: " << b << endl;

    cout << "c before: " << c << endl;
    c = 42;
    cout << "c after: " << c << endl;

    cout << "d = " << d << endl;
    cout << "e = " << e << endl;
    cout << "f = " << f << endl;
    cout << "g = " << g << endl;
    /* Error
    * d = 42;
    * e = 42;
    * f = 42;
    * g = 42;
    */ 
}


void exercise35() {
    const int i = 42; // const int
    auto j = i; // int 
    const auto &k = i; // const int
    auto *p = &i; // const int *
    const auto j2 = i, &k2 = i; // const int, const int &
}

void exercise36() {
    int a = 3, b = 4;
    decltype(a) c = a; // int c = 3
    decltype((b)) d = a; //int & to a, d = 3
    ++c; // 4
    ++d; // 4, a = 4
}

void exercise37() {
    int a = 3, b = 4;
    decltype(a) c = a; // int c = 3
    decltype(a = b) d = a; // int & to a
}

void exercise38() {
    int i1 = 5;
    auto a1 = i1; // int
    decltype(i1) b; // int

    const int i2 = 10;
    auto a2 = i2;          // int
    decltype(i2) d3 = 42;  // const int
}

/* Exercise 39
* struct Foo {
*
* } 
* without ";" will be error
*/


// Exercise 40-41


void exercise1_20() {
    Sales_data item; 
    double price;
    cin >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    cout << item.bookNo << " " << item.units_sold << " " << item.revenue << endl;
    
}

void exercise1_21() {
    Sales_data item1, item2;
    double price;

    cin >> item1.bookNo >> item1.units_sold >> price;
    item1.revenue = item1.units_sold * price;

    cin >> item2.bookNo >> item2.units_sold >> price;
    item2.revenue = item2.units_sold * price;

    if (item1.bookNo == item2.bookNo) {
        unsigned totalSold = item1.units_sold + item2.units_sold;
        cout << (item1.revenue + item2.revenue) / (totalSold) << endl;
    }
    else {
        cout << "ISBN is different" << endl;
    }
}

void exercise1_22() {
    Sales_data total, item;
    double price;

    cin >> total.bookNo >> total.units_sold >> price;
    total.revenue = total.units_sold * price;

    do {
        cin >> item.bookNo >> item.units_sold >> price;
        item.revenue = item.units_sold * price;
        if (total.bookNo == item.bookNo) {
            total.units_sold += item.units_sold;
            total.revenue += item.revenue;
        }
        
    } while (total.bookNo == item.bookNo);

    cout << total.units_sold << " " << total.revenue << endl;
}


int main()
{
    cout << "Exercise 3: " << endl;  exercise3();
    cout << "Exercise 9: " << endl;  exercise9();
    cout << "Exercise 13: " << endl;  exercise13();
    cout << "Exercise 17: " << endl;  exercise17();
    cout << "Exercise 18: " << endl;  exercise18();
    cout << "Exercise 20: " << endl;  exercise20();
    cout << "Exercise 33-34: " << endl; exercise33_34();
    cout << "Exercise 40-41: " << endl; 
    exercise1_20();
    exercise1_21();
    exercise1_22();

}
