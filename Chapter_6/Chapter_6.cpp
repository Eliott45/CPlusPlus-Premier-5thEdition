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

int main()
{
    // cout << "Exercise 3-4: "; cout << fact() << endl;
    // cout << "Exercise 5: "; cout << exercise5(5) << endl;

    /*
    
    cout << exercise7() << endl;
    cout << exercise7() << endl;
    cout << exercise7() << endl;

    */
}


