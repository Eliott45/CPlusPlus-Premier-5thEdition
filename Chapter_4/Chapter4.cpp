#include <iostream>
#include <limits>
#include <vector>

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

/* Exercise 17
* The prefix increment operator increases the operand and return the operand itself as an lvalue.
* The postfix increment operator increases the operand and return a copy of the operand's original value as an rvalue.
*/

/* Exercise 18
* The loop will print all elements except the first one in the vector, 
* and also try to dereference to one past the last element, which is an error. 
* Also, if there is no negative value in the vector, the loop will continue to dereference whatever in memeory 
* until a negative value is found, which is a disaster.
*/

/* Exercise 19
* a) prt != 0 && *prt++ better ptr != 0 && (*ptr)++
* b) ival++ && ival 
* c) vec[ival++] <= vec[ival] better ++ival, vec[ival] <= vec[ival + 1]
*/

/* Exercise 20
* vector<string>::iterator; 
* (a) *iter++; is legal, the expression moves iter to point to the next element and returns the value of the original element.
* (b) (*iter)++;  is not legal. The expression means increasing value of the element, but the value is a string and string does not have ++ operator.
* (c) *iter.empty(); is not legal. Because iter is an iterator and has no member named empty.
* (d) iter->empty(); is legal. The expression means check if the string pointed by iter is empty 
* (e) ++*iter;  is not legal. The expression means increasing value of the element, but the value is a string and string does not have ++ operator.
* (f) iter++->empty();  is legal. The expression means move iter to point to the next element and check if the original string is empty.
*/

void exercise21() {
    vector<int> v;
    int i;
    while (cin >> i) {
        v.push_back(i);
    }
    for (auto& elem : v) {
        elem = elem % 2 ? elem + elem : elem;
    }
    for (const auto& elem : v) {
        cout << elem << ' ';
    }
    cout << endl;
}

void exercise22() {
    int grade;
    cin >> grade;
    cout << (grade > 90 ? "High pass" : grade > 75 ? "Pass" : grade >= 60 ? "Low pass" : "Don't pass") << endl;

    if (grade > 90) {
        cout << "High pass" << endl;
    }
    else if (grade > 75) {
        cout << "Pass" << endl;
    }
    else if (grade >= 60) {
        cout << "Low pass" << endl;
    }
    else {
        cout << "Fail" << endl;
    }
        
}

/// <summary>
/// The precedence of the conditional operator is lower than arithmetic operator.
/// </summary>
void exercise23() {
    string s = "word";
    // string p1 = s + s[s.size() - 1] == 's' ? "" : "s";
    string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
    cout << pl << endl;
}

/* Exercise 24
* grade > 90 ? "high pass" : grade < 60 ? "fail" : "pass";
* (grade > 90 ? "high pass" : grade < 60) ? "fail" : "pass";
*/

/* Exercise 25
* ~'q' << 6 is the same as (~'q') << 6.
* 'q' = 01110001
* ~'q'  = 11111111 11111111 11111111 10001110
* ~'q' << 6  = 11111111 11111111 11100011 10000000
* The result is -7296.
*/

/* Exercise 26
* The standard guarantees the minimum size of int is 16 bits, 
* and the minimum size of long is 32 bits. Since the teacher has 30 students in a class, which needs at least 30 bits, 
* int would be not enough to hold all the results.
*/

void exercise27() {
    unsigned long ul1 = 3, ul2 = 7;
    cout << (ul1 & ul2) << endl; // (a) 3 
    cout << (ul1 | ul2) << endl; // (b) 7 
    cout << (ul1 && ul2) << endl; // (c) 1 (true)
    cout << (ul1 || ul2) << endl; // (d) 1 (true)
}

void exercise28() {
    cout << "char        " << sizeof(char) << endl;
    cout << "wchar_t     " << sizeof(wchar_t) << endl;
    cout << "char16_t    " << sizeof(char16_t) << endl;
    cout << "char32_t    " << sizeof(char32_t) << endl;
    cout << "short       " << sizeof(short) << endl;
    cout << "int         " << sizeof(int) << endl;
    cout << "long        " << sizeof(long) << endl;
    cout << "long long   " << sizeof(long long) << endl;
    cout << "float       " << sizeof(float) << endl;
    cout << "double      " << sizeof(double) << endl;
    cout << "long double " << sizeof(long double) << endl;
}

void exercise29() {
    int x[10]; int* p = x;
    cout << sizeof(x) / sizeof(*x) << endl; // 10
    cout << sizeof(p) / sizeof(*p) << endl; // 1
}

/* Exercise 30
* (a) sizeof(x) + y 
* (b) sizeof(p->mem[i]) 
* (c) sizeof(a) < b 
* (d) sizeof(f())
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
    // cout << "Exercise 21: " << endl; exercise21();
    // cout << "Exercise 22: " << endl; exercise22();
    cout << "Exercise 23: " << endl; exercise23();
    cout << "Exercise 27: " << endl; exercise27();
    cout << "Exercise 28: " << endl; exercise28();
    cout << "Exercise 29: " << endl; exercise29();

}
