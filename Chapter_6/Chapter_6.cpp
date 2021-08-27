#include <iostream>
#include <vector>

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

/* Exercise 25
int main(int argc, char* argv[]) {
    cout << "All " << argc << " argument" << (argc > 1 ? "s are:" : " is:") << endl;
    for (int i = 0; i < argc; ++i) {
        cout << i << "\t" << argv[i] << endl;
    }
    if (argc < 3)  return -1;
    string args(argv[1]);
    args += argv[2];
    cout << args << endl;

    return 0;
}

*/

/* Exercise 26
int main(int argc, char* argv[]) {
    cout << "All " << argc << " argument" << (argc > 1 ? "s are:" : " is:") << endl;
    for (int i = 0; i < argc; ++i) cout << i << "\t" << argv[i] << endl;
    return 0;
}
*/

int Exercise27(initializer_list<int> il) {
    int sum = 0;
    for (auto& e : il) {
        sum += e;
    }
    return sum;
}

/* Exercise 28
* The type of elem is const string &.
*/

/* Exercise 29
* Use a reference as the loop control variable. So that we don't need to copy the value from the initializer_list.
*/

// Exercise 30
bool str_subrange(const string& str1, const string& str2) {
    if (str1.size() == str2.size())
        return str1 == str2;
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i])
            //return;  // Error: need a return value
            return false;
    }
    // Error: need a return statement
    return true;
}

/* Exercise 31
* When the object is not a local object, then that's fine to return a reference to it.
* When we don't want the reference returned from a function to be an lvalue, we should use a reference to const as the return type instead.
*/

// Exercise 32
int& get(int* arry, int index) {
    return arry[index];
}
// The function is legal. It return a reference to the element at `index` in array `arry`. The reference return is lvalue, thus can be used to assign to the array.

void Exercise33(const vector<int>::iterator bg,
    const vector<int>::iterator ed) {
    if (bg == ed) return;
    cout << *bg << " ";
    Exercise33(bg + 1, ed);
}

/* Exercise 34
* If we pass a negative number to the function, then it will recursively call itself infinitely.
*/

/* Exercise 35
* Due to the priority, the function will be called infinitely. 
*/

// Exercises 36-37

string(&link1())[10];

string str[10] = {"Sun", "Mars", "Test", "Card", "Car", "Cat", "Dog", "Nice", "Hot"};

string(&link1())[10]{
  return str;
}

using arr_str_type = string[10];
arr_str_type &link2();

arr_str_type& link2() {
    return str;
}

auto link3()->string(&)[10];
auto link3()->string(&)[10]{
  return str;
}

decltype(str)& link4() {
    return str;
}

// Exercise 38
int odd[] = { 1, 3, 5, 7, 9 };
int even[] = { 0, 2, 4, 6, 8 };
auto arrPtr(int i) -> int(&)[5]{
  return i % 2 ? odd : even;
}

/* Exercise 39
* (a)
* int calc(int, int)
* int calc(const int, const int) // Same with first line, top-level `const` are ignored
* (b)
* int get();
* double get();  // Error, differ only on return types
* (c)
* int *reset(int *);
* double *reset(double *);  // Ok, define an overloaded function
*/

/* Exercise 40
* (a) int ff(int a, int b = 0, int c = 0);  // Ok
* (b) char *init(int ht = 24, int wd, char bckgrnd); // Error
*/

/* Exercise 41
* char *init(int ht, int wd = 80, char bckgrnd = ' ');
* (a) init(); is illegal, must have at least one argument.
* (b) init(24, 10); is legal.
* (c) init(14, '*'); is legal, but unlikely to match the programer's intent. Because the character * will be promoted to int and match wd.
*/

// Exercise 42
string make_plural(size_t ctr, const string& word, const string& ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

/* Exercise 43
* (a) inline bool eq(const BigInt&, const BigInt&) {...}
* (b) void putValues(int *arr, int size);
* The declarations of both functions should be put in a header. 
* The definition of function eq should be put in the same header with declaration. 
* The definition of function putValues may be put in a source file.
*/

// Exercise 44
inline bool isShorter(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

/* Exercise 46
* No, a constexpr function may only contains statements that generate no actions at run time, 
* but the member method size() must be called at run time, thus the function can not be a constexpr function.
*/

void Exercise47(const vector<int>::iterator bg, const vector<int>::iterator ed) {
    #ifndef NDEBUG
    cout << "In function: " << __func__ << ", " << "Vector size: " << ed - bg << endl;
    #endif
    if (bg == ed) return;
    cout << *bg << endl;
    Exercise47(bg + 1, ed);
}

/* Exercise 48
* string s;
* while(cin >> s && s != sought() {} 
* assert(cin);
* The loop are used to keep reading string from the input until sought found. 
* It is a bad idea to use assert check whether cin is in an error state. 
* Because when the program compiled with NDEBUG preprocessor variable, the statement would not be excuted.
*/

/* Exercise 49
* A candidate function is a function with the same name as the called 
* function and for which a declaration is visible at the point of the call.
* 
* A viable function is a candidate function with the same number of parameters 
* as there are arguments in the call, and the type of each argument must match or be convertible 
* to the type of its corresponding parameter.
*/

/* Exercise 50-51
void f();                         |
void f(int);                      |
void f(int, int);                 |
void f(double, double = 3.14);    |
----------------------------------|
(a) f(2.56, 42)  // Error
(b) f(42) // void f(int);    
(c) f(42, 0) // void f(int, int);  
(d) f(2.56, 3.14) // void f(double, double = 3.14);   
*/

/* Exercise 52
* void manip(int, int);
* double dobj;
* (a) manip('a', 'z'); rank 3
* (b) manip(55.4, dobj); rank 4
*/

/* Exercise 53
(a)
int calc(int&, int&);
int calc(const int&, const int&);
// OK, overloaded function takes reference to `const`

(b)
int calc(char*, char*);
int calc(const char*, const char*);
// OK, overloaded function takes pointer to `const`

(c)
int calc(char*, char*);
int calc(char* const, char* const);
// Error, redeclare the same function, top-level `const` is ignored
*/

// Exercise 54 
int foo1(int, int);
int bar1(int, int);

// Exercises 55-56
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

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

    cout << "Exercise 27: " << endl;
    cout << Exercise27({ 1,2,4,5 }) << endl;;

    /*
    string s1, s2;
    cin >> s1 >> s2;
    cout << str_subrange(s1, s2) << endl;
    */

    cout << "Exercise 33: " << endl;
    vector<int> vi = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Exercise33(vi.begin(), vi.end());
    cout << endl;

    cout << "Exercises 36-37: " << endl;
    cout << "Link 1: " << link1() << endl;
    cout << "Link 2: " << link2() << endl;
    cout << "Link 3: " << link3() << endl;
    cout << "Link 4: " << link4() << endl;
    cout << endl;

    /* Exercise 38
    int i3;
    cin >> i3;
    int(&arr)[5] = arrPtr(i3);
    int* arr2 = arrPtr(i3);
    cout << arr[0] << " " << arr2[0] << endl;
    return 0;
    */

    cout << "Exercise 42: " << endl;
    cout << "success: " << make_plural(2, "success", "es") << endl;
    cout << "success (single): " << make_plural(1, "success", "es") << endl;
    cout << "failure: " << make_plural(2, "failure") << endl;
    cout << endl;

    cout << "Exercise 47: " << endl;
    vector<int> vi2 = { 0,1,2,3,4 };
    Exercise47(vi2.begin(), vi2.end());
    cout << endl;

    cout << "Exercise 54: " << endl;
    vector<int (*)(int, int)> vf;
    vf.push_back(foo1);
    vf.push_back(bar1);
    vf[0](1, 2);
    vf[1](3, 4);
    for (const auto& e : vf) {
        e(9, 9);
    }
    cout << endl;

    cout << "Exercise 55-56: " << endl;
    vector<int (*)(int, int)> vf1;

    vf1.push_back(add);
    vf1.push_back(subtract);
    vf1.push_back(multiply);
    vf1.push_back(divide);

    int a, b;
    cin >> a >> b;
    for (const auto& e : vf) {
        cout << e(a, b) << endl;
    }

    cout << endl;
}

int foo1(int a, int b) {
    cout << "Called foo(" << a << ", " << b << ")" << endl;
    return 0;
}

int bar1(int a, int b) {
    cout << "Called bar(" << a << ", " << b << ")" << endl;
    return 0;
}


int add(int a, int b) {
    cout << "Called add(" << a << ", " << b << ")" << endl;
    return a + b;
}

int subtract(int a, int b) {
    cout << "Called subtract(" << a << ", " << b << ")" << endl;
    return a - b;
}

int multiply(int a, int b) {
    cout << "Called multiply(" << a << ", " << b << ")" << endl;
    return a * b;
}

int divide(int a, int b) {
    cout << "Called divide(" << a << ", " << b << ")" << endl;
    try {
        if (b == 0)
            throw runtime_error("Divide by 0.");
        return a / b;
    }
    catch (std::runtime_error err) {
        cerr << err.what() << endl;
        return 0;
    }
}