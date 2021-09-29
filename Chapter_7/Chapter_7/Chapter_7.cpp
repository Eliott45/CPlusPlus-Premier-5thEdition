#include <iostream>

using namespace std;

struct Sales_data;
istream& read(istream& is, Sales_data& item);

struct Sales_data {
    // Sales_data() = default;
    Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}
    Sales_data(const string& no) : bookNo(no) {}
    Sales_data(const string& no, unsigned us, double price): bookNo(no), units_sold(us), revenue(price* us) {}
    Sales_data(istream& is);

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

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
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

// Exercise 1, 3, 7, 13
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
struct Person {
    Person() = default;
    Person(const string & n) : name(n) {}
    Person(const string & n, const std::string & a) : name(n), address(a) {}
    Person(istream&);

    string getName() const { return name; }
    string getAddress() const { return address; }

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



int main()
{
    // exercise1();

    // Exercise 11,12
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
    
    // Exercise 15
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
}


