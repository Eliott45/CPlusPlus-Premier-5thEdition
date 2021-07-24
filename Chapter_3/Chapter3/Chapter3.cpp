#include <iostream>
#include <string>

using namespace std;

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

int main()
{
    cout << "Exercise 1: Sum = " << exercise1_9() << endl;
    // cout << "Exercise 2: " << endl; exercise2();
    cout << "Exercise 4: " << endl; exercise4();
    // cout << "Exercise 5: " << endl; exercise5();
}

