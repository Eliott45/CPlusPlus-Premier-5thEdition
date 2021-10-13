#include <iostream>
#include <string>

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

int main()
{
    exercise1(cin);
}

