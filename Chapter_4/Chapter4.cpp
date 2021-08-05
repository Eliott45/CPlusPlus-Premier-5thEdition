#include <iostream>

using namespace std;

int exercise1() {
    return 5 + 10 * 20 / 2; // 105
}

/* Exercise 2
* vec.begin() = ((vec.begin)())
* vec.begin() + 1 = ( * ((vec.begin)())) + 1
*/
   

int main()
{
    cout << "Exercise 1: " << exercise1() << endl;
}
