#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;
using std::vector;

// Exercise 1 in Chapter 3
int exercise1_9() {
    int sum = 0, i = 50;
    while (i < 100) {
        sum += i;
        i++;
    }
    return sum;
}

void exercise2() {
    // string line;
    string word;

    while (cin >> word) {
        cout << word << endl;
    }

    /*
    * while (getline(cin, line)) {
    *   cout << line << endl;
    * }
    */

}

void exercise4() {
    string word1, word2;
    cout << "Enter two words: " << endl;
    cin >> word1 >> word2;
    if (word1.size() == word2.size()) {
        cout << "Words are the same size " << endl;
    }
    else if (word1.size() > word2.size()) {
        cout << word1 << " > " << word2 << endl;
    }
    else {
        cout << word2 << " > " << word1 << endl;
    }
}

void exercise5() {
    string total, word;
    while (cin >> word) {
        total += ' ' + word;
    }
    cout << total << endl;
}

void exercise6() {
    string word;
    if (cin >> word) {
        for (auto &c : word) {
            c = 'X';
        }
    }
    cout << word << endl;
}

void exercise7() {
    string word;
    if (cin >> word) {
        for (char &c : word) {
            c = 'X';
        }
    }
    cout << word << endl;
}

void exercise8() {
    string word;
    if (cin >> word) {
        string::size_type pos = 0; 
        while (pos != word.size()) {
            word[pos++] = 'X';
        }
    }
    cout << word << endl;
}

void exercise9() {
    string s;
    cout << s[0] << endl; // The index is out of range, result is undefined.
}

void exercise10() {
    string s;
    cin >> s;
    for (const auto& c : s) {
        if (!ispunct(c)) {
            cout << c;
        }
    }
    cout << endl;
}

void exercise11() {
    const string s = "Keep out!";
    for (auto& c : s) {
        // It works
    }
}

void exercise12() {
    vector<vector<int>> ivec; // (a) Correct, vector of vector of int
    // vector<string> svec = ivec; // (b) Error type of vector doesn't match 
    vector<string> svec(10, "null"); // (c) Vector containing 10 strings "null" 
}

void exercise13() {
    vector<int> v1; // (a) - containing 0 elements
    vector<int> v2(10); // (b) - containing 10 elements, the values of all elements is 0 
    vector<int> v3(10, 42); // (c) containing 10 elements, the values of all elements is 42
    vector<int> v4{ 10 }; // (d) containing 1 element, the value of elements is 10;
    vector<int> v5{ 10,42 }; // (e) containing 2 elements, 10 and 42;
    vector<string> v6{ 10 }; // (f) containing 10 elements, empty strings
    vector<string> v7{ 10, "hi" }; // (g) containing 10 element, the value of elements is "hi";
}

void exercise14() {
    vector<int> v1;
    int i;
    while (cin >> i) {
        v1.push_back(i);
    }

    for (const auto num : v1) {
        cout << num << " ";
    }

    cout << endl;
}

void exercise15() {
    vector<string> v1;
    string i;

    while (cin >> i) {
        v1.push_back(i);
    }

    for (auto word : v1) {
        cout << word << " ";
    }

    cout << endl;
}

void printIntVector(vector<int> v) {
    for (const auto num : v) {
        cout << num << " ";
    }
    cout << endl;
}

void printStringVector(vector<string> v) {
    for (const auto word : v) {
        cout << word << " ";
    }
    cout << endl;
}


void exercise16() {
    vector<int> v1; 
    cout << "v1:" << endl; printIntVector(v1);
    vector<int> v2(10);
    cout << "v2:" << endl; printIntVector(v2);
    vector<int> v3(10, 42);
    cout << "v3:" << endl; printIntVector(v3);
    vector<int> v4{ 10 }; 
    cout << "v4:" << endl; printIntVector(v4);
    vector<int> v5{ 10,42 }; 
    cout << "v5:" << endl; printIntVector(v5);
    vector<string> v6{ 10 }; 
    cout << "v6:" << endl; printStringVector(v6);
    vector<string> v7{ 10, "hi" };
    cout << "v7:" << endl; printStringVector(v7);
}

void exercise17() {
    vector<string> v;
    string s;
    int maxWords = 32, i = 0;

    while (i < maxWords && cin >> s) {
        v.push_back(s);
        i++;
    }

    for (auto &str : v) {
        for (auto& c : str) {
            c = toupper(c);
        }
    }

    for (decltype(v.size()) i = 0; i != v.size(); ++i) {
        cout << v[i] << '\t';
        if ((i + 1) % 8 == 0) {
            cout << endl;
        }
    }
}

void exercise18() {
    vector<int> ivec;
    // ivec[0] = 42;
    ivec.push_back(42);
    cout << ivec[0] << endl;
}

void exercise19() {
    vector<int> v1(10, 42); // The best method 
    vector<int> v2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
    vector<int> v3;
    for (int i = 0; i != 10; i++) {
        v3.push_back(42);
    }
}

void exercise20() {
    vector<int> v;
    int num;
    int maxNums = 10, i = 0;

    while (i < maxNums && cin >> num) {
        v.push_back(num);
        i++;
    }

    cout << "Vector is: " << endl;

    for (i = 0; i < v.size(); i ++) {
        cout << v[i] << " ";
    }

    cout << endl;

    cout << "Sum of pairs: " << endl;

    for (i = 0; i < v.size(); i+=2) {
        cout << v[i] + v[i + 1] << " ";
    }

    cout << endl;

    for (i = 0; i < v.size(); i++) {
        cout << v[i] + v[(v.size() - 1) - i] << " ";
    }
}

void exercise21() {
    vector<int> v;
    int num;
    int maxNums = 10, i = 0;

    while (i < maxNums && cin >> num) {
        v.push_back(num);
        i++;
    }

    cout << "Vector is: " << endl;

    for (auto j = v.cbegin(); j != v.cend(); j++) {
        cout << *j << " ";
    }

    cout << endl;

    cout << "Sum of pairs: " << endl;

    for (auto j = v.cbegin(); j != v.cend(); j += 2) {
        cout << *j + *(j + 1) << " ";
    }

    cout << endl;

    for (auto j = v.cbegin(); j != v.cend(); j++) {
        cout << *j + *(v.cend() - 1 - (j - v.cbegin())) << " ";
    }  
}

void exercise25() { 
    vector<unsigned> scores(11, 0);
    unsigned grade;
    int maxGrades = 10, i = 0;

    while (maxGrades > i && cin >> grade) {
        ++*(scores.begin() + grade / 10);
        i++;
    }

    for (const auto& grade : scores) {
        cout << grade << ' ';
    } 
    cout << endl;
}

/* Exercise 26
* mid = beg  + (end - beg) / 2;
* mid = (beg + end) / 2; // Operator + does not exist  for two iterators.
*/

void exercise27() {
    unsigned buf_size = 1024;
    // (a) int ia1[buf_size]; // Error buf_size not constexpr
    int ia2[4 * 7 - 14]; // (b)
    // int ia3[txt_size]; // (c) Error txt_size not constexpr
    // char st[11] = "fundamental"; // (d) String length must be 12 
}

/* Exercise 28
*
*string sa[10];  // ten elements of empty string
*int    ia[10];  // ten elements of 0
*
*int main() {
*  string sa2[10];  // ten elements of empty string
*  int    ia2[10];  // ten elements of undefined value
*}
*
*/

/* Exercise 29
* It is necessary to set the size of the array in advance
* Impossibility to remove or add others without shifting 
* The threat of going beyond the boundaries of the array
*/

void exercise30() {
    constexpr size_t array_size = 10;
    int ia[array_size];

    /*
    for (size_t ix = 1; ix <= array_size; ++ix) {
        ia[ix] = ix;
    }
    */
    
    for (int i = 0; i < array_size; i++) {
        ia[i] = i + 1;
        cout << ia[i] << " ";
    }
    
    cout << endl;
}

void exercise31() {
    int a[10];

    for (int i = 0; i < 10; i++) {
        a[i] = i;
        cout << a[i] << " ";
    }
    
    cout << endl;
}

void exercise32() {
    int a1[10], a2[10];

    cout << "Array: " << endl;

    for (int i = 0; i < 10; i++) {
        a1[i] = i;
        cout << a1[i] << " ";
        a2[i] = a1[i];
    }

    cout << endl;

    cout << "Vector: " << endl;

    vector<int> v; 
    for (int i = 0; i < 10; i++) {
        v.push_back(a2[i]);
        cout << v[i] << " ";
    }

    cout << endl;
}

void exercise35() {
    int a[10];

    for (int i = 0; i < 10; i++) {
        a[i] = i + 1;
        cout << a[i] << " ";
    }

    cout << endl;

    for (int* bg = begin(a), *ed = end(a); bg < ed; bg++) {
        *bg = 0;
        cout << *bg << " ";
    }

    cout << endl;
}

void exercise36() {
    int a[5], b[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter " << i << " value of array A: ";
        cin >> a[i];
        cout << "Enter " << i << " value of array B: ";
        cin >> b[i];
    }

    cout << endl;

    int i = 0;
    for (; i < 5; i++) {
        if (a[i] != b[i]) break;
    }

    if (i == 5) {
        cout << "Arrays are identical" << endl;
    }
    else {
        cout << "Arrays are not identical" << endl;
    }
}

void exercise37() {
    const char ca[] = { 'h','e','l','l','o'};
    const char* cp = ca;
    while (*cp) {
        cout << *cp;
        ++cp;
    }
    cout << endl;
    /*
    Since there is no null character at the end, 
    the program will print all the characters in ca and continue 
    print whatever in memory until it find a null character.
    */
}

/* Exercise 38
* There is no point in adding the addresses of variables 
*/


void exercise39() {
    string s1, s2;
    cout << "Enter two strings: ";
    cin >> s1 >> s2;

    if (s1 == s2) {
        cout << "Strings are equal" << endl;
    }
    else {
        cout << "Strings are not equal" << endl;
    }
    
    
    char cs1[100], cs2[100];
    cout << "Enter two strings (C): ";
    cin >> cs1 >> cs2;
    if (!strcmp(cs1, cs2)) {
        cout << "C-style strings are equal" << endl;
    }
    else {
        cout << "C-style strings are not equal" << endl;
    }
}

void exercise40() {
    char s1[] = "Eliott", s2[] = "Alderson", s3[16];
    strcpy_s(s3, s1);
    strcat_s(s3, s2);
    cout << s3 << endl;
}

void exercise41() {
    int arr[] = { 1, 2, 3, 4, 5 };
    vector<int> ivec(begin(arr), end(arr));
}

void exercise42() {
    vector<int> ivec{ 1,2,3,4,5 };
    int arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = ivec[i];
    }
}

void exercise43() {
    constexpr size_t ia_row = 3;
    constexpr size_t ia_col = 3;
    int ia[ia_row][ia_col] = {
      {0, 1, 2},
      {3, 4, 5},
      {6, 7, 8}
    };

    cout << "Using a serial operator:" << endl;

    for (const int(&row)[ia_col] : ia) {
        for (const int& col : row) {
            cout << col << '\t';
        }
        cout << endl;
    }

    cout << "Using indexing:" << endl;

    for (size_t i = 0; i < ia_row; i++) {
        for (size_t j = 0; j < ia_col; j++) {
            cout << ia[i][j] << '\t';
        }
        cout << endl;
    }

    cout << "Using pointers:" << endl;

    using int_array = int[ia_col];

    for (int_array* p = ia; p < ia + ia_row; p++) {
        for (int* q = *p; q < *p + ia_col; q++) {
            cout << *q << '\t';
        }
        cout << endl;
    }
}


int main()
{
    cout << "Exercise 1: Sum = " << exercise1_9() << endl;
    // cout << "Exercise 2: " << endl; exercise2();
    cout << "Exercise 4: " << endl; exercise4();
    // cout << "Exercise 5: " << endl; exercise5();
    cout << "Exercise 6: " << endl; exercise6();
    cout << "Exercise 7: " << endl; exercise7();
    cout << "Exercise 8: " << endl; exercise8();
    cout << "Exercise 9: " << endl; exercise9();
    cout << "Exercise 10: " << endl; exercise10();
    // cout << "Exercise 14: " << endl; exercise14();
    // cout << "Exercise 15: " << endl; exercise15();
    cout << "Exercise 16: " << endl; exercise16();
    // cout << "Exercise 17: " << endl; exercise17();
    cout << "Exercise 18: " << endl; exercise18();
    // cout << "Exercise 20: " << endl; exercise20();
    // cout << "Exercise 21: " << endl; exercise21();
    // cout << "Exercise 25: " << endl; exercise25();
    cout << "Exercise 30: " << endl; exercise30();
    cout << "Exercise 31: " << endl; exercise31();
    cout << "Exercise 32: " << endl; exercise32();
    cout << "Exercise 35: " << endl; exercise35();
    // cout << "Exercise 35: " << endl; exercise36();
    // cout << "Exercise 37: " << endl; exercise37();
    // cout << "Exercise 39: " << endl; exercise39();
    cout << "Exercise 40: " << endl; exercise40();
    cout << "Exercise 43: " << endl; exercise43();

}

