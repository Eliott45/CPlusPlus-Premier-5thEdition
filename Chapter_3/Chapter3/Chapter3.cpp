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
}

