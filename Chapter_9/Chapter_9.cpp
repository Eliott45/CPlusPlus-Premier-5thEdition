#include <iostream>
#include <sstream>
#include <list>
#include <deque>
#include <vector>
#include <string>
#include <forward_list>

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

// Exercise 7 vector<int>::size_type.

/* Exercise 8
* list<string>::const_iterator or list<string>::iterator to read elements.
*/

/* Exercise 9
 Those that start with a c return the const version of the related iterator. 
 For example, begin() will return an iterator while cbegin() will return a const_iterator.
*/

/* Exercise 10
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(); - the type of `it1` is `vector<int>::iterator`
auto it2 = v2.begin(); - the type of `it2` is `vector<int>::const_iterator`
auto it3 = v1.cbegin(), it4 = v2.cbegin(); - the type of `it3` and `it4` is `vector<int>::const_iterator`
*/

/* Exercise 11
  vector<int> v1;                        // Empty
  vector<int> v2(v1);                    // Empty
  vector<int> v3 = v1;                   // Empty
  vector<int> v4{1, 2, 3};               // 3 elements: 1, 2, 3
  vector<int> v5 = {1, 2, 3};            // 3 elements: 1, 2, 3
  vector<int> v6(v5.begin(), v5.end());  // 3 elements: 1, 2, 3
  vector<int> v7(5);                     // 5 elements: 0, 0, 0, 0, 0
  vector<int> v8(5, 1);                  // 5 elements: 1, 1, 1, 1, 1
*/

/* Exercise 12
The constructor that takes a container to copy requires the container type and the element type of the two containers are both match exactly.

The constructor that takes two iterators requires the element type of the source container must be compatible with the element type of the destiny container.
*/

/* Exercise 17
The constraints are:
    * the lefthand and righthand operands must have the same container type and element type.
    * the element of the container must support the < operator.
*/

/* Exercise 21
The member function insert(p, t) has the same effect on both list and vector containers, 
but the cost is different. Inserting an element into list is cheap, while inserting an element into vector 
will cause all the elements after the newly inserted element be moved. Thus every time the while loop body is excuted, 
all elements in the vector are moved backward, and new element is inserted in the front of the vector.
*/

/* Exercise 22
vector<int>::iterator iter = iv.begin(),
                      mid = iv.begin() + iv.size()/2;
while (iter != mid) {
  if (*iter == some_val) {
    iv.insert(iter, 2 * some_val);  // Error, we should update the iter
    iter = iv.insert(iter, 2 * some_val);
    ++iter;  // Increament to point to the original value
  }
  ++iter;  // Increment to point to the next value
}
*/

// Exercise 23 - The values of them are all copies of c[0].

/* Exercise 25
    If elem1 and elem2 are equal, then no element will be removed from the container.

    If elem2 or both elem1 and elem2 are the off-the-end iterator, then all elements from elem1 to the last element in the container will be removed.
*/

void Exercise28(forward_list<string>& fls,
    const string& s1,
    const string& s2) {
    auto pre = fls.before_begin();
    auto cur = fls.begin();
    while (cur != fls.end()) {
        if (*cur == s1) {
            fls.insert_after(cur, s2);
            return;
        }
        else {
            pre = cur++;
        }
    }
    fls.insert_after(pre, s2);
}

int main()
{
    // Exercise 2
    list<deque<int>> exercise2;

    /*
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
    */
    
    // Exercise 13
    list<int> li{ 1, 2, 3 };
    vector<int> vi{ 4, 5, 6 };

    vector<double> vd1(li.begin(), li.end());
    vector<double> vd2(vi.begin(), vi.end());

    cout << vd1[0] << " " << vd2[0] << endl;

    // Exercise 15
    vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
    vector<int> v2 = { 1, 3, 9 };

    cout << (v1 < v2 ? "v1 < v2" : "v2 < v1") << endl;

    // Exercise 18
    /*
    deque<string> words;
    string word;
    while (cin >> word && word != "stop") {
        words.push_back(word);
    }

    for (deque<string>::const_iterator it = words.cbegin(); it != words.cend(); ++it) {
        cout << *it << endl;
    }
    */

    // Exercise 19
    /*
    list<string> words;
    string word;
    while (cin >> word && word != "stop") {
        words.push_back(word);
    }
        
    for (list<string>::const_iterator it = words.cbegin(); it != words.cend(); ++it) {
        cout << *it << endl;
    }
    */

    // Exercise 20
    /*
    list<int> input;
    deque<int> even, odd;

    for (int i; cin >> i; ) {
        input.push_back(i);
    }
        
    for (auto it = input.cbegin(); it != input.cend(); ++it) {
        if (*it % 2)
            odd.push_back(*it);
        else
            even.push_back(*it);
    }
        
    cout << "Odd: ";
    for (const auto& i : odd) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Even: ";
    for (const auto& i : even) {
        cout << i << " ";
    }
    cout << endl;
    */

    /* Exercise 24 
    vector<int> vi;

    // All of them will cause program terminate in VS2015.
    //int i1 = vi.at(0);
    //int i2 = vi[0];
    //int i3 = vi.front();
    //int i4 = *vi.begin();

    //cout << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
    */

    // Exercise 26
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> iv(begin(ia), end(ia));
    list<int> il(begin(ia), end(ia));

    cout << "Before erase:" << endl;
    cout << "vector iv: ";
    for (const auto& i : iv) {
       cout << i << " ";
    }
    cout << endl;

    cout << "list   il: ";
    for (const auto& i : il) {
        cout << i << " ";
    }
    cout << endl;

    for (auto it = iv.begin(); it != iv.end(); ) {
        if (*it % 2) {
            ++it;
        } else {
            it = iv.erase(it);
        }    
    }
    for (auto it = il.begin(); it != il.end(); ) {
        if (*it % 2) {
            it = il.erase(it);
        } 
        else {
            ++it;
        }
    }
    
    cout << "After erase:" << endl;
    cout << "vector iv: ";
    for (const auto& i : iv) {
        cout << i << " ";
    }
    cout << endl;

    cout << "list   il: ";
    for (const auto& i : il) {
        cout << i << " ";
    }
    cout << endl;

    // Exercise 27
    forward_list<int> fli{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto pre = fli.before_begin();
    auto cur = fli.begin();
    while (cur != fli.end()) {
        if (*cur % 2) {
            cur = fli.erase_after(pre);
        }
        else {
            pre = cur;
            ++cur;
        }
    }

    for (const auto& i : fli) {
        cout << i << " ";
    }
    cout << endl;

    // Exercise 28
    forward_list<string> fls{ "s1", "s2", "s3" };

    for (const auto& s : fls) {
        cout << s << " ";
    }
    cout << endl;

    Exercise28(fls, "s2", "s4");

    for (const auto& s : fls) {
        cout << s << " ";
    }
    cout << endl;

    Exercise28(fls, "s5", "s6");

    for (const auto& s : fls) {
        cout << s << " ";
    }
    cout << endl;


    return 0;
}


