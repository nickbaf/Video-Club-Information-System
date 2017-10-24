#include "Rent.h"
#include <ctime>
#include <wchar.h>
#include <iostream>
using namespace std;
Rent::Rent(int newCustomerID,int newProductID) {
    this->customerID=newCustomerID;
    this->productID=newProductID;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    this->year = 1900 + ltm->tm_year;
    this->month = 1 + ltm->tm_mon;
    this->day = ltm->tm_mday;
    
}
Rent::Rent(){
    
}

int Rent::getCustomerID() {
    return customerID;
}

int Rent::getProductID() {
    return productID;
}

int Rent::getYear() {
    return year;
}

int Rent::getMonth() {
    return month;
}

int Rent::getDay() {
    return day;
}

std::ostream & operator<<(ostream &out, Rent& r) {
    out << r.customerID << '\n';
    out << r.day << '\n';
    out << r.month<< '\n';
    out << r.productID << '\n';
    out << r.year << '\n';
    return out;
}

std::istream & operator>>(istream &in, Rent& r) {
    in >> r.customerID;
    in >> r.day;
    in >> r.month;
    in >> r.productID;
    in >> r.year;
    return in;
}
