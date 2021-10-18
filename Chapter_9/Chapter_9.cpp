﻿#include <iostream>
#include <sstream>
#include <list>
#include <deque>
#include <vector>

using namespace std;

/* Exercise 1

(a) List. Since the sequence of the words need to be alphabetical, the container needs to support insert in the middle effeciently.

(b) Deque. The container needs to support insert/delete in the front and back effeciently.

(c) Vector. There is no need to use other containers. And to sort the numbers in container, random access is usually needed.

*/

/* Exercise 3
The constraints for two iterators, begin and end, forming an iterator range are
1. They refer to elements of, or one past the end of, the same container.
2. end must not precede begin.
*/

bool exercise4(vector<int>::const_iterator begin, vector<int>::const_iterator end, int k) {
    for (auto it = begin; it != end; ++it) {
        if (k == *it) return true;
    }
    return false;
}

vector<int>::const_iterator exercise5(vector<int>::const_iterator begin, vector<int>::const_iterator end, int k) {
    for (auto it = begin; it != end; ++it) {
        if (k == *it) return it;
    }
    return end;
}

/* Exercise 6
    The iterator of list does not support iterator arithmetic, including relational operators like >, <. Thus the condition for the while loop should be iter1 != iter2.
*/

int main()
{
    // Exercise 2
    list<deque<int>> exercise2;

    // Exercise 4
    string str;
    getline(cin, str);
    istringstream iss(str);
    vector<int> vi;
    int k;
    while (iss >> k) {
        vi.push_back(k);
    }
    cin >> k;
    cout << exercise4(vi.cbegin(), vi.cend(), k) << endl;
    // Exercise 5
    auto it = exercise5(vi.cbegin(), vi.cend(), k);
    if (it == vi.end()) {
        cout << "No found " << k << " in range" << endl;
    }
    else {
        cout << "Found " << *it << " at position " << it - vi.cbegin() << endl;
    }
}

