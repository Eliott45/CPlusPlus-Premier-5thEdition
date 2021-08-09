#include <iostream>

using namespace std;

void exercise1() {
	string s;
	while (cin >> s && s != "Stop")
		; // Empty operator  
}

int exercise2() {
	int val = 1, sum = 0;
	while (val <= 10) { // block
		sum += val;
		++val;
	} // block
	return sum;
}

int exercise3() {
	int val = 1, sum = 0;
	while (val <= 10 && (sum += val, ++val));
	return sum;
}

/* Exercise 4 
* (a) string::iterator iter = s.begin();
* while (iter != s.end()) {...}
* 
*/

int main()
{
	cout << "Exercise 2: " << exercise2() << endl;
	cout << "Exercise 3: " << exercise3() << endl;
}
