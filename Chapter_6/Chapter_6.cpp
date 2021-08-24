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
Reference parameters

    - Functions must use reference parameters to operate on objects of a type that cannot be copied.

    - Functions prefer to use reference parameters to operate on objects of large class types or large containers.

    - Functions should use reference parameters to return additional information via the reference parameters.

    - void printStr(std::ostream &os, const std::string &str, bool &stat) { if (os << str) stat = true; else stat = false; }

Nonreference parameters

    - Functions should use nonreference parameters when the value of the parameters may changed but should not affect the objects passed to the function.

        int sum(int n) { int sum = 0; while (n > 0) sum += n--; return sum; }
*/

/* Exercise 15
string::size_type find_char(const string &s, char c, string::size_type &occurs)

- s and occurs are both referecnes to avoid copy.
- s is const because it isn't changed inside function and a string literal can be used here. occurs is plain reference beacuse it is used to pass information (changed inside function).
- c is nonreference because copy a char is very cheap. It's fine to make it a const reference but not plain reference, because we don't want to accidentally change c inside function, and we may want to pass a char literal to the function.
- If occurs is made a reference to const, then we cannot get how many times the character c occurred in string s.
*/

/* Exercise 16
* bool is_empty(string &s) { return s.empty(); } // The parameter of the function should be const string &s. So that we can pass string literals or const strings to the function.
*/

// Exercise 17

bool CapitalLetter(const string& s) {
    for (auto& c : s) {
        if (c >= 'A' && c <= 'Z') return true;
    } 
    return false;
}

void toLowerStr(string& s) {  
    for (auto& c : s) {
        if (c >= 'A' && c <= 'Z') c -= 'A' - 'a';
    }
}

// The parameters have different type, because in `hasCapital`, we don't need to change the string, but in `toLowerStr`, we need to change the string.

/* Exercise 18
* (a) bool compare(const matrix &, const matrix &);
* (b) vector<int> change_val(int, vector<int>::iterator &); 
*/

/* Exercise 19
* double calc(double);
* int count(const string &, char);
* int sum(vector<int>::iterator, vector<int>::iterator, int);
* vector<int> vec(10);
* (a) calc(23.4, 55.1); !Error two parameters 
* (b) count("abcda", 'a');
* (c) calc(66);
* (d) sum(vec.begin(), vec.end(), 3.8);
*/

/* Exercise 20
* If the reference parameters will not be changed inside function, then they should be reference to const.
*/

int Exercise21(int a, int* pb) {
    return a > *pb ? a : *pb;
}

void Exercise22(int*& a, int*& b) {
    int* tmp = a;
    a = b;
    b = tmp;
}

// Exercise 23
void print(int i) {
    cout << "void print(int i): ";
    cout << i << endl;
}

void print(const int* bg, const int* ed) {
    cout << "void print(const int *bg, const int *ed): ";
    while (bg != ed) {
        cout << *bg++ << " ";
    }
    
}

void print(const int arr[], size_t sz) {
    cout << "void print(const int arr[], size_t sz): ";
    for (size_t i = 0; i != sz; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print(const int(&arr)[2]) {
    cout << "void print(const int (&arr)[2]): ";
    for (auto& e : arr) {
        cout << e << " ";
    }
    cout << endl;
}
       
// Exercise 24
void print(const int(&ia)[10]) {
    for (size_t i = 0; i != 10; i++) {
        cout << ia[i] << endl;
    }
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

    /* Exercise 12
    cout << "Exercise 12: " << endl;
    int a, b;
    cin >> a >> b;
    exercise12(a, b);
    cout << a << " " << b << endl;
    //  The reference version looks like easier to use, but the user must know from other source that the function will change the value of the argument.
    */

    /* Exercise 17
    cout << "Exercise 17" << endl;
    string s;
    cin >> s;
    cout << CapitalLetter(s) << endl;
    toLowerStr(s);
    cout << s << endl;
    */

    /*
    cout << "Exercise 21" << endl;
    int a, b;
    cin >> a >> b;
    cout << Exercise21(a, &b);
    */

    // Exercise 22
    cout << "Exercise 22: " << endl;
    int i = 1, j = 2;
    int* pi = &i, * pj = &j;
    cout << "pi = " << pi << " *pi = " << *pi << endl;
    cout << "pj = " << pj << " *pj = " << *pj << endl;
    Exercise22(pi, pj);
    cout << "pi = " << pi << " *pi = " << *pi << endl;
    cout << "pj = " << pj << " *pj = " << *pj << endl;
    cout << endl;

    // Exercise 23
    cout << "Exercise 23: " << endl;
    int i2 = 0, j2[2] = { 0, 1 };
    print(i2);
    print(begin(j2), end(j2));
    print(j2, end(j2) - begin(j2));
    print(j2);
    cout << endl;

    

}


