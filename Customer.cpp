#include "Customer.h"
#include <string>
#include <iostream>
using namespace std;

Customer::Customer(int newID, string newName, string newSurname, string newDate, bool newSex, string newAdress, int newPhone) {
    ID = newID;
    name = newName;
    surname = newSurname;
    date = newDate;
    sex = newSex;
    adress = newAdress;
    phone = newPhone;
}

Customer::Customer() {

}

void Customer::print() {
    cout << "Name:" << name << surname << endl;
    cout << "ID:" << ID << endl;
    cout << "Birthday:" << date << endl;
    cout << "Sex:" << sex << endl;
    cout << "adress:" << adress << endl;
    cout << "Phone:" << phone << endl;

}

int Customer::getID() {
    return ID;
}

void Customer::setID(int newID) {
    ID = newID;
}

string Customer::getName() {
    return name;
}

void Customer::setName(string newName) {
    name = newName;
}

string Customer::getSurname() {
    return surname;
}

void Customer::setSurname(string newSurname) {
    surname = newSurname;
}

string Customer::getDate() {
    return date;
}

void Customer::setDate(string newDate) {
    date = newDate;
}

bool Customer::getSex() {
    return sex;
}

void Customer::setSex(bool newSex) {
    sex = newSex;
}

string Customer::getAdress() {
    return adress;
}

void Customer::setAdress(string newAdress) {
    adress = newAdress;
}

int Customer::getPhone() {
    return phone;
}

void Customer::setPhone(int newPhone) {
    phone = newPhone;
}

std::ostream & operator<<(ostream &out, Customer& s) {
    out << s.ID << '\n';
    out << s.adress << '\n';
    out << s.date << '\n';
    out << s.name << '\n';
    out << s.phone << '\n';
    out << s.sex << '\n';
    out << s.surname << '\n';
    return out;
}

std::istream & operator>>(istream &in, Customer& s) {
    in >> s.ID;
    in >> s.adress;
    in >> s.date;
    in >> s.name;
    in >> s.phone;
    in >> s.sex;
    in >> s.surname;
    return in;
}
