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

// Exercise 1, 3
string exercise1() {
    Sales_data total;
    double price;
    if (cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                cout << total.bookNo << " "
                    << total.units_sold << " "
                    << total.revenue << endl;
                total = trans;  
            }
        }
        cout << total.bookNo << " "
            << total.units_sold << " "
            << total.revenue << endl;
    }
    else {
        cerr << "No data!" << endl;
        return "Error";
    }
}

// Exercise 4-5
struct Person {
    string getName() const { return name; }
    string getAddress() const { return address; }

    string name;
    string address;
};


int main()
{
    // exercise1();
}


