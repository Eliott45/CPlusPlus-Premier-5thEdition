#include <iostream>
#include <vector>

using namespace std;

class Sales_data;
istream& read(istream& is, Sales_data& item);

class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend istream& read(istream&, Sales_data&);
    friend ostream& print(ostream&, const Sales_data&);

public:
    Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}
    Sales_data(const string& no) : bookNo(no) {}
    Sales_data(const string& no, unsigned us, double price): bookNo(no), units_sold(us), revenue(price* us) {}
    Sales_data(istream& is);

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// exercise 2
Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// Exercise 6
Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;  // Use default copy constructor
    sum.combine(rhs);
    return sum;
}

istream& read(istream& is, Sales_data& item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream& print(ostream& os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

inline
double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

// Exercise 1, 3, 7, 13, 26
string exercise1() {
    Sales_data total(cin);
    if (cin) {
        Sales_data trans(cin);
        while (cin) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total) << endl;
                total = trans; 
            }
            read(cin, trans);  
        }
        print(cout, total) << endl;
    }
    else {
        cerr << "No data!" << endl;
        return "Error";
    }
}

// Exercise 11
Sales_data::Sales_data(istream& is) {
    read(is, *this);
}

// Exercise 4-5, 9
class Person {
    friend istream& read(istream&, Person&);
    friend ostream& print(ostream&, const Person&);

public:
    Person() = default;
    Person(const string & n) : name(n) {}
    Person(const string & n, const string & a) : name(n), address(a) {}
    Person(istream&);

    string getName() const { return name; }
    string getAddress() const { return address; }

private:
    string name;
    string address;
};

istream& read(istream& is, Person& rhs) {
    is >> rhs.name >> rhs.address;
    return is;
}

ostream &print(ostream &os, const Person &rhs) {
  os << rhs.getName() << " " << rhs.getAddress();
  return os;
}

Person::Person(istream& is) {
    read(is, *this);
}

/* Exercise 8
* The read function will change its Sales_data parameter and pass the information back via plain reference.
* The print function won't change its Sales_data parameter, and by using a reference to const, we can print const Sales_data object as well.
*/

/* Exercise 10
* if(read(read(cin, data1), data2))
* The condition test if both data1 and data2 are read correctly.
*/

/* Exercise 16
There is no constraint on where and how often an access specifier may appear inside a class definition. 
A class may contain zero or more access specifiers, each kind of access specifiers can appears multiple times. T
here is no constraint on the sequence of access specifiers too.

The constructors and member functions that are part of the interface should be defined after a public specifier.

The data members and member functions that are part of the implementation should be defined after a private specifier.
*/


/* Exercise 17
The only difference between struct and class is the default access level. 
The members defined before the first access specifier are public in struct, while those are private in class.
*/

/* Exercise 18
Encapsulation enforces the separation between interface and implementation in a class via access specifiers. Encapsulation provides some advantages:

* A class that is encapsulated hides its implementation to the user of the class, 
thus the user need not know how the class works, they can regard the class as a type (like a built-in type) instead.
* User code cannot inadvertently corrupt the state of an encapsulated object.
* The implementation of an encapsulated class can change over time without requiring changes in user code.
*/

/* Exercise 20
A friend of a class can access nonpublic members of that class.
+ For functions that are part of the interface while not a member of the class, they can access the nonpublic members of that class.
+ If the implementation of the class changes over time, its friend may also requiring changes.
*/

// Exercise 23-24, 27, 32
class Screen;

class Window_mgr {
public:
    using screen_index = vector<Screen>::size_type;
    void clear(screen_index);
    Window_mgr();
private:
   vector<Screen> screens;  //{Screen(24, 80)};
};


class Screen {
friend void Window_mgr::clear(screen_index);
public:
    using pos = string::size_type;
    using content_type = char;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht* wd, ' ') {}
    Screen(pos ht, pos wd, content_type c) : height(ht), width(wd), contents(ht* wd, c) {}

    const content_type& get() const { return contents[cursor]; }
    const content_type& get(pos row, pos col) const;

    Screen& set(content_type c);
    Screen& set(pos row, pos col, content_type c);

    Screen& move(pos row, pos col);

    const Screen& display(ostream& os) const;
    Screen& display(ostream& os);
private:
    void do_display(ostream& os) const;

    pos cursor = 0;
    pos width = 0;
    pos height = 0;
    string contents;
};

inline
const Screen::content_type& Screen::get(pos row, pos col) const {
    return contents[row * width + col];
}

inline
Screen& Screen::set(content_type c) {
    contents[cursor] = c;
    return *this;
}

inline
Screen& Screen::set(pos row, pos col, content_type c) {
    contents[row * width + col] = c;
    return *this;
}

inline
Screen& Screen::move(pos row, pos col) {
    cursor = row * width + col;
    return *this;
}

inline
const Screen& Screen::display(ostream& os) const {
    do_display(os);
    return *this;
}

inline
Screen& Screen::display(ostream& os) {
    do_display(os);
    return *this;
}

inline
void Screen::do_display(ostream& os) const {
    for (pos i = 0; i != contents.size(); ++i) {
        os << contents[i];
        if ((i + 1) % width == 0 && i + 1 != contents.size())
            os << "\n";
    }
}

Window_mgr::Window_mgr() : screens{ Screen(24, 80) } {}

void Window_mgr::clear(screen_index i) {
    Screen& s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

/* Exercise 25
* Yes, because all the data members of Screen are built-in types or string, which can rely on synthesized versions for copy and assignment.
*/

/* Exercise 28-29
* If then, every time we call move, 
* set or display, the function will return a new Screen object that is
* the copy of the original Screen object with the changes we made, while the original Screen object keeps unchanged.
*/

/* Exercise 30
Proc:
    * It is much more clear by using this to refer members.
    * The parameters in member function can have the same name as the data members if we use this pointer to refer data members.

Cons:
    * The code will look redundant.

*/

// Exercise 31
struct Y;

struct X {
    Y* y;
};

struct Y {
    X x;
};

int main()
{
    // exercise1();

    // Exercise 11,12, 21, 26
    
    /*
    Sales_data d1;
    Sales_data d2("0-201-78345-X");
    Sales_data d3("0-201-78345-X", 5, 2.5);
    Sales_data d4(cin);

    print(cout, d1) << endl;
    print(cout, d2) << endl;
    print(cout, d3) << endl;
    print(cout, d4) << endl;
    */
    
    // Exercise 15, 22
    /*
    Person p1;
    Person p2("Zhang San");
    Person p3("Zhang San", "Earth");
    Person p4(cin);

    print(cout, p1) << endl;
    print(cout, p2) << endl;
    print(cout, p3) << endl;
    print(cout, p4) << endl;
    */

    // Exercise 27

    /*
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n-----\n";
    myScreen.display(cout);
    cout << "\n-----\n";

    Screen myScreen2(5, 3);
    const Screen blank(5, 3);
    myScreen2.set('#').display(cout);  // calls nonconst version
    cout << "\n-----\n";
    blank.display(cout);  // calls const version
    cout << "\n-----\n";
   */

    // Exercise 32
    Window_mgr window;
    window.clear(0);
}


