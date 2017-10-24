#include "Film.h"
#include <iostream>
using namespace std;

Film::Film(int id, int s, std::string titl, std::string gnr, int prod,
        std::string dir, std::string act, int lenth,bool blue) : Stuff(id, s, titl, gnr, prod) {
    this->actors = act;
    this->director = dir;
    this->lenth = lenth;
    this->blueRay = blue;
}

Film::~Film() {
    //dtor
}
Film::Film(){
    
}
void Film::print(){
    cout<<"Title:"<<title<<endl;
    cout<<"ID:"<<id<<" SerialNumber:"<<serial<<endl;
    cout<<"Genre:"<<genre<<endl;
    cout<<"Production Year:"<<prodYear<<endl;
    cout<<"Length"<<lenth<<endl;
    cout<<"Actors"<<actors<<endl;
    cout<<"Director"<<director<<endl;
}

void Film::setBlue(bool ray){
    this->blueRay = ray;
}

bool Film::getBlue(){
    return blueRay;
}

std::string Film::getActors() {
    return actors;
}

std::string Film::getDirect() {
    return director;
}

int Film::getLenth() {
    return lenth;
}

void Film::setLenth(int lenth) {
    this->lenth = lenth;
}

void Film::setActors(std::string actors) {
    this->actors = actors;
}

void Film::setDirector(std::string director) {
    this->director = director;
}

std::ostream & operator<<(ostream &out, Film& s) {
    out << s.title << '\n';
    out << s.genre << '\n';
    out << s.id << '\n';
    out << s.prodYear << '\n';
    out << s.rented << '\n';
    out << s.serial << '\n';
    out << s.actors << '\n';
    out << s.director << '\n';
    out << s.lenth << '\n';
    return out;
}

std::istream & operator>>(istream &in, Film& s) {
    in >> s.title;
    in >> s.genre;
    in >> s.id;
    in >> s.prodYear;
    in >> s.rented;
    in >> s.serial;
    in >> s.actors;
    in >> s.director;
    in >> s.lenth;
    return in;
}