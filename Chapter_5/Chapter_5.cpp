#include <iostream>
#include <vector>
#include <string>

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
* (b) bool status;
* while (status = find(word)) {...}
* if (!status) {...}
*/

string exercise5() {
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	string letterGrade;
	int grade;
	cin >> grade;
	if (grade >= 60) {
		letterGrade = scores[(grade - 50) / 10];
	}
	else {
		letterGrade = scores[0];
	}
	return letterGrade;
}

string exercise6() {
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	int grade;
	cin >> grade;
	return grade < 60 ? scores[0] : scores[(grade - 50) / 10];
}

/* Exercise 7
* (a) 
*	if (ival1 != ival2)
*		ival1 = ival2;
*	else ival1 = ival2 = 0;
* (b)
* if (ival < minval) {
*	minval = ival;
*	occurs = 1; 
* }
* (c)
* int ival;
* if (ival = get value()) 
*	cout << "ival = " << ival " << ival << endl;s
* if(!ival) 
*	cout << "ival = 0\n";
* (d)
* if (ival == 0) 
*	ival = get_value();
*/

/* Exercise 8
* A "dangling else" means the ambiguity that an else may belong to several if. 
* In C++, this is resolved by specifying that each else is matched with the closest preceding unmatched if.
*/

int main()
{
	cout << "Exercise 2: " << exercise2() << endl;
	cout << "Exercise 3: " << exercise3() << endl;
	// cout << "Exercise 5: " << exercise5() << endl;
	// cout << "Exercise 6: " << exercise6() << endl;

}
