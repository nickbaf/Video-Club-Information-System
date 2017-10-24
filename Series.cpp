#include "Series.h"
#include <iostream>
using namespace std;

Series::Series(int id, int s, std::string titl, std::string gnr, int prod, int season, int epA, int epB, std::string director, std::string actors,bool blue) : Stuff(id, s, titl, gnr, prod) {
    this->season = season;
    this->epA = epA;
    this->epB = epB;
    this->director = director;
    this->actors = actors;
    this->blueRay = blue;
}

Series::~Series() {
    //dtor
}
Series::Series(){
    
}
void Series::print(){
    cout<<"Title:"<<title<<endl;
    cout<<"ID:"<<id<<" SerialNumber:"<<serial<<endl;
    cout<<"Genre:"<<genre<<endl;
    cout<<"Production Year:"<<prodYear<<endl;
    cout<<"Season:"<<season<<" Episodes:"<<epA<<"-"<<epB<<endl;
    cout<<"Actors"<<actors<<endl;
    cout<<"Director"<<director<<endl;
}


void Series::setBlue(bool ray){
    this->blueRay = ray;
}

bool Series::getBlue(){
    return blueRay;
}

std::string Series::getActors() {
    return actors;
}

void Series::setActors(std::string actors) {
    this->actors = actors;
}

void Series::setDirector(std::string director) {
    this->director = director;
}

std::string Series::getDirector() const {
    return director;
}

void Series::setEpB(int epB) {
    this->epB = epB;
}

void Series::setEpA(int epA) {
    this->epA = epA;
}

void Series::setSeason(int season) {
    this->season = season;
}

int Series::getSeason() {
    return season;
}

int Series::getEpA() {
    return epA;
}

int Series::getEpB() {
    return epB;
}

 std::ostream & operator<<(ostream& out, Series& s) {
    out << s.title << '\n';
    out << s.genre << '\n';
    out << s.id << '\n';
    out << s.prodYear << '\n';
    out << s.rented << '\n';
    out << s.serial << '\n';
    out << s.actors << "\n";
    out << s.director << '\n';
    out << s.epA << '\n';
    out << s.epA << '\n';
    out << s.season << '\n';
    return out;
}

std::istream & operator>>(std::istream& in, Series& s) {
    in >> s.title;
    in >> s.genre;
    in >> s.id;
    in >> s.prodYear;
    in >> s.rented;
    in >> s.serial;
    in >> s.actors;
    in >> s.director;
    in >> s.epA;
    in >> s.epB;
    in >> s.season;
    return in;
}
