#include <iostream>

using namespace std;


struct Sales_data {
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

// Exercise 1, 3, 7
string exercise1() {
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total) <<endl;
                total = trans;  
            }
        }
        print(cout, total) << endl;
    }
    else {
        cerr << "No data!" << endl;
        return "Error";
    }
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

// Exercise 4-5, 9
struct Person {
    string getName() const { return name; }
    string getAddress() const { return address; }

    string name;
    string address;
};

istream& read(istream& is, Person& rhs) {
    is >> rhs.name >> rhs.address;
    return is;
}

ostream& print(ostream& os, const Person& rhs) {
    os << rhs.getName() << " " << rhs.getAddress();
    return os;
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
}


