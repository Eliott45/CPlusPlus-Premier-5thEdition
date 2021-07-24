#include <iostream>
#include <string>
#include <vector>

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


}

