#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/// <summary>
/// Exercise 1-2
/// </summary>
istream& exercise1(istream& is) {
    is.clear();
    string str;
    while (is >> str && str != "stop") {
        cout << str << " ";
    }
    cout << endl;
    is.clear();
    return is;
}

/* Exercise 3
The condition of a stream is equivalent to !fail(), which means set either failbit or badbit will terminate the loop. For example, errors list below will terminate the loop:
    *   System-level failure. (Set the badbit) Such as an unrecoverable r/w error.
    *   Recoverable error. (Set the failbit) Such as reading a character when numeric data expected.
    *   Reaching end-of-file. (Set both the eofbit and failbit)
*/

/// <summary>
/// Exercises 4-5
/// </summary>
vector<string> exercise4(const string& filename) {
    ifstream in(filename);
    vector<string> vs;
    if (in) {
        for (string s; getline(in, s);) {
            vs.push_back(s);
        }
    }
    else {
        cerr << "Fail to open file: " << filename << endl;
    }
    return vs;
}

istream& exercise9(istream& is) {
    is.clear();
    string str;
    while (is >> str)
        cout << str << " ";
    cout << endl;
    is.clear();
    return is;
}

void exercise10() {
    vector<string> vs;
    string filename;

    cin >> filename;
    ifstream in(filename);
    if (!in) {
        cerr << "Fail to open file: " << filename << endl;
    }
    for (string line; getline(in, line); vs.push_back(line)) {}
    for (const auto& e : vs) {
        istringstream iss(e);
        for (string word; iss >> word; cout << word << endl) {}
    }
}

int main()
{
    // exercise1(cin);

    // Exercises 4-5

    string filename;
    cin >> filename;
    auto vs = exercise4(filename);
    for (decltype(vs.size()) i = 0; i != vs.size(); ++i) {
        cout << i + 1 << "\t: " << vs[i] << endl;
    }

    // exercise9(cin);
    exercise10();
}

