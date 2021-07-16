#include <iostream>

using namespace std;

int exercise1() {
    return 0;
}

int exercise2() {
    return -1;
}

string exercise3() {
    return "Hello, World";
}

int exercise4() {
    int a, b; 
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    return a * b;
}



void exercise6() {
    int v1, v2;
    cout << "Enter v1: ";
    cin >> v1;
    cout << "Enter v2: ";
    cin >> v2;
    cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;
}

void exercise8() {
    cout << "/*";
    cout << "*/";
    // cout << /* "*/" */; - It won't work due to incorrect nesting of comments 
    cout << /* "*/" /* "/*" */;
}

int main()
{
    cout << "Exercise 1: " << exercise1() << endl;
    cout << "Exercise 2: " << exercise2() << endl;
    cout << "Exercise 3: " << exercise3() << endl;
    cout << "Exercise 4: " << exercise4() << endl;
    cout << "Exercise 6: " << endl; exercise6();
    cout << "Exercise 8: " << endl; exercise8();
}
