#include "Customer_VIP.h"
#include <iostream>
using namespace std;

Customer_VIP::Customer_VIP(int newID, string newName, string newSurname, string newDate, bool newSex, string newAdress, int newPhone, int newCreditCard, string newBank, int newCvn) : Customer(newID, newName, newSurname, newDate, newSex, newAdress, newPhone) {
    creditCard = newCreditCard;
    bank = newBank;
    cvn = newCvn;
}

void Customer_VIP::print() {
    cout << "Name:" << name << surname << endl;
    cout << "ID:" << ID << endl;
    cout << "Birthday:" << date << endl;
    cout << "Sex:" << sex << endl;
    cout << "adress:" << adress << endl;
    cout << "Phone:" << phone << endl;
}

int Customer_VIP::getCreditCard() {
    return creditCard;
}

void Customer_VIP::setCreditCard(int newCreditCard) {
    creditCard = newCreditCard;
}

string Customer_VIP::getBank() {
    return bank;
}

void Customer_VIP::setBank(string newBank) {
    bank = newBank;
}

int Customer_VIP::getCvn() {
    return cvn;
}

void Customer_VIP::setCvn(int newCvn) {
    cvn = newCvn;
}

std::ostream & operator<<(ostream &out, Customer_VIP& s) {
    out << s.ID << '\n';
    out << s.adress << '\n';
    out << s.date << '\n';
    out << s.name << '\n';
    out << s.phone << '\n';
    out << s.sex << '\n';
    out << s.surname << '\n';
    out << s.bank << '\n';
    out << s.creditCard << '\n';
    out << s.cvn << '\n';
    return out;
}

std::istream & operator>>(istream &in, Customer_VIP& s) {
    in >> s.ID;
    in >> s.adress;
    in >> s.date;
    in >> s.name;
    in >> s.phone;
    in >> s.sex;
    in >> s.surname;
    in >> s.bank;
    in >> s.creditCard;
    in >> s.cvn;
    return in;
}
