﻿#include <iostream>
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

void exercise9() {
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while (cin >> ch && ch != 's') {
		if (ch == 'a')
			++aCnt;
		else if (ch == 'e')
			++eCnt;
		else if (ch == 'i')
			++iCnt;
		else if (ch == 'o')
			++oCnt;
		else if (ch == 'u')
			++uCnt;
	}
	cout << "Number of vowel a: " << aCnt << '\n'
	<< "Number of vowel e: " << eCnt << '\n'
	<< "Number of vowel i: " << iCnt << '\n'
	<< "Number of vowel o: " << oCnt << '\n'
	<< "Number of vowel u: " << uCnt << endl;
}

void exercise10() {
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while (cin >> ch && ch != 's') {
		switch (ch) {
		case 'A': case 'a':
			++aCnt;
			break;
		case 'E': case 'e':
			++eCnt;
			break;
		case 'I': case 'i':
			++iCnt;
			break;
		case 'O': case 'o':
			++oCnt;
			break;
		case 'U': case 'u':
			++uCnt;
			break;
		}
	}
	cout << "Number of vowel a: " << aCnt << '\n'
	<< "Number of vowel e: " << eCnt << '\n'
	<< "Number of vowel i: " << iCnt << '\n'
	<< "Number of vowel o: " << oCnt << '\n'
	<< "Number of vowel u: " << uCnt << endl;
}

void exercise11() {
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	unsigned spaceCnt = 0, tabCnt = 0, newlineCnt = 0, otherCnt = 0;
	char ch;
	while (cin >> ch && ch != 's') {
		switch (ch) {
		case 'A': case 'a':
			++aCnt;
			break;
		case 'E': case 'e':
			++eCnt;
			break;
		case 'I': case 'i':
			++iCnt;
			break;
		case 'O': case 'o':
			++oCnt;
			break;
		case 'U': case 'u':
			++uCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newlineCnt;
			break;
		default:
			++otherCnt;
		}
	}
	cout << "Number of vowel a:\t" << aCnt << '\n'
	<< "Number of vowel e:\t" << eCnt << '\n'
	<< "Number of vowel i:\t" << iCnt << '\n'
	<< "Number of vowel o:\t" << oCnt << '\n'
	<< "Number of vowel u:\t" << uCnt << '\n'
	<< "Number of space:\t" << spaceCnt << '\n'
	<< "Number of tab:\t" << tabCnt << '\n'
	<< "Number of newline:\t" << newlineCnt << '\n'
	<< "Number of others:\t" << otherCnt << endl;
}

void exercise12() {
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	unsigned spaceCnt = 0, tabCnt = 0, newlineCnt = 0, otherCnt = 0;
	unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
	bool fPresent = false;
	char ch;
	while (cin.get(ch)) { 
		switch (ch) {
		case 'A': case 'a':
			++aCnt;
			break;
		case 'E': case 'e':
			++eCnt;
			break;
		case 'I':
			++iCnt;
			break;
		case 'i':
			++iCnt;
			if (fPresent) {
				++fiCnt;
				fPresent = false;
			}
			break;
		case 'O': case 'o':
			++oCnt;
			break;
		case 'U': case 'u':
			++uCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newlineCnt;
			break;
		case 'f':
			if (fPresent)
				++ffCnt;
			else
				fPresent = true;
			break;
		case 'l':
			if (fPresent) {
				++flCnt;
				fPresent = false;
			}
			break;
		default:
			++otherCnt;
		}
	}
	cout << "Number of vowel a:\t" << aCnt << '\n'
		<< "Number of vowel e:\t" << eCnt << '\n'
		<< "Number of vowel i:\t" << iCnt << '\n'
		<< "Number of vowel o:\t" << oCnt << '\n'
		<< "Number of vowel u:\t" << uCnt << '\n'
		<< "Number of space:\t" << spaceCnt << '\n'
		<< "Number of tab:\t" << tabCnt << '\n'
		<< "Number of newline:\t" << newlineCnt << '\n'
		<< "Number of sequence ff:\t" << ffCnt << '\n'
		<< "Number of sequence fl:\t" << flCnt << '\n'
		<< "Number of sequence fi:\t" << fiCnt << '\n'
		<< "Number of others:\t" << otherCnt << endl;

}

/* Exercise 13
* (a)
* unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
* char ch = next_text();
* switch (ch) {
*  case ’a’: aCnt++; break;  
*  case ’e’: eCnt++; break;  
*  default: iouCnt++;
* }
* 
* (b)
* unsigned index = some_value();
* int ix;
* switch (index) {
*  case 1:
*    //int ix = get_value();  
*    ix = get_value();
*    ivec[ ix ] = index;
*    break;
*  default:
*    ix = ivec.size()-1;
*    ivec[ ix ] = index;
* }
* 
* (c)
* unsigned evenCnt = 0, oddCnt = 0;
* int digit = get_num() % 10;
* switch (digit) {
*  // case 1, 3, 5, 7, 9:  
*  case 1: case 3: case 5: case 7: case 9:
*    oddcnt++;
*    break;
*  // case 2, 4, 6, 8, 10:
*  case 2: case 4: case 6: case 8: case 10:
*    evencnt++;
*    break;
* }
* 
* (d)
* /unsigned ival=512, jval=1024, kval=4096;
* // case label must be integral const expression
* constexpr unsigned ival=512, jval=1024, kval=4096;
* unsigned bufsize;
* unsigned swt = get_bufCnt();
* switch(swt) {
*  case ival:
*    bufsize = ival * sizeof(int);
*    break;
*  case jval:
*    bufsize = jval * sizeof(int);
*    break;
*  case kval:
*    bufsize = kval * sizeof(int);
*    break;
* }
* 
*/

int main()
{
	cout << "Exercise 2: " << exercise2() << endl;
	cout << "Exercise 3: " << exercise3() << endl;
	// cout << "Exercise 5: " << exercise5() << endl;
	// cout << "Exercise 6: " << exercise6() << endl;
	// cout << "Exercise 9: " << endl;  exercise9();
	// cout << "Exercise 10: " << endl;  exercise10();
	// cout << "Exercise 11: " << endl;  exercise11();
	// cout << "Exercise 12: " << endl;  exercise12();

}
