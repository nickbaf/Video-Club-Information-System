#include "Stuff.h"
#include <iostream>
using namespace std;

Stuff::Stuff(int id, int serial, string title, std::string genre, int prod) {
    this->id = id;
    this->serial = serial;
    this->title = title;
    this->genre = genre;
    this->prodYear = prod;
    this->rented = false;
}

Stuff::~Stuff() {
    //dtor
}

Stuff::Stuff() {

}
void Stuff::print(){
    
}

void Stuff::SetProdYear(int prodYear) {
    this->prodYear = prodYear;
}

int Stuff::GetProdYear() const {
    return prodYear;
}

void Stuff::SetGenre(std::string genre) {
    this->genre = genre;
}

std::string Stuff::GetGenre() const {
    return genre;
}

void Stuff::SetTitle(std::string title) {
    this->title = title;
}

std::string Stuff::GetTitle() const {
    return title;
}

void Stuff::SetSerial(int serial) {
    this->serial = serial;
}

int Stuff::GetSerial() const {
    return serial;
}

void Stuff::SetId(int id) {
    this->id = id;
}

int Stuff::GetId() const {
    return id;
}

void Stuff::SetRented(bool rented) {
    this->rented = rented;
}

bool Stuff::IsRented() const {
    return rented;
}

std::ostream & operator<<(ostream &out, Stuff& s) {
    out << s.title << '\n';
    out << s.genre << '\n';
    out << s.id << '\n';
    out << s.prodYear << '\n';
    out << s.rented << '\n';
    out << s.serial << '\n';
    return out;
}

std::istream & operator>>(istream &in, Stuff& s) {
    in >> s.title;
    in >> s.genre;
    in >> s.id;
    in >> s.prodYear;
    in >> s.rented;
    in >> s.serial;
    return in;
}