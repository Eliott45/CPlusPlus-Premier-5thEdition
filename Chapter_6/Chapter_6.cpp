#include <iostream>

using namespace std;

/* Exercise 1
* A parameter is the variable in the parentheses after the function name when we defining the function and used inside a function.
* An argument is the variable in the parentheses after the function name when we calling the function, and it is used to initialize 
* the parameter of the function.
*/

/* Exercise 2
* (a)
* string f() {
*   string s;
*   return s;
* }
* (b)
* void f2(int i) { ... }
* (c) 
* int calc(int v1, int v2) { ... }
* (d)
* double squre(double x) {
*   return x * x;
* }
*/

// Exercise 3-4

/*
int fact() {
    int val;
    cin >> val;
    int ret = 1; 
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}
*/

int exercise5(int i) {
    return i >= 0 ? i : -i;
}

/* Exercise 6
* A local variable is a variable defined inside the function scope.
* A parameter is also a local variable, but the definition is in the parameter list of the function.
* A local static variable is a local variable that defined with static keyword. It has a lifetime much longer than usual local variable.
*/

int exercise7() {
    static int cnt = 0;
    return cnt++;
}

void exercise10(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void exercise11(int &i) {
    i = 0;
}

void exercise12(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

/* Exercise 13
* void f(T) will pass the argument by value, which means in the function f, a copy of T will be made.
* void f(T&) will pass the argument by reference, which means in the function f, the same variable defined in the caller is used.
*/

/* Exercise 14
* Reference parameters

    - Functions must use reference parameters to operate on objects of a type that cannot be copied.

    - Functions prefer to use reference parameters to operate on objects of large class types or large containers.

    - Functions should use reference parameters to return additional information via the reference parameters.

    - void printStr(std::ostream &os, const std::string &str, bool &stat) { if (os << str) stat = true; else stat = false; }
*/

int main()
{
    // cout << "Exercise 3-4: "; cout << fact() << endl;
    // cout << "Exercise 5: "; cout << exercise5(5) << endl;

    /*
    
    cout << exercise7() << endl;
    cout << exercise7() << endl;
    cout << exercise7() << endl;

    */

    /* Exercise 10
    
    cout << "Exercise 10: " << endl;
    int a, b;
    cin >> a >> b;
    exercise10(&a, &b);
    cout << a << " " << b << endl;

    */

    // Exercise 11
    /*
    int c;
    cin >> c;
    exercise11(c);
    cout << c << endl;
    */

    /*
    * 
    cout << "Exercise 12: " << endl;
    int a, b;
    cin >> a >> b;
    exercise12(a, b);
    cout << a << " " << b << endl;
    //  The reference version looks like easier to use, but the user must know from other source that the function will change the value of the argument.
    */

    
}


