#include "Game.h"
#include <iostream>
using namespace std;
Game::Game(int id,int s, std::string titl, std::string gnr, int prod, std::string console):Stuff(id,s,titl,gnr,prod)
{
    this->console=console;
}

Game::~Game()
{
    //dtor
}

Game::Game(){
    
}
void Game::print(){
    cout<<"Title:"<<title<<endl;
    cout<<"ID:"<<id<<" SerialNumber:"<<serial<<endl;
    cout<<"Genre:"<<genre<<endl;
    cout<<"Production Year:"<<prodYear<<endl;
    cout<<"Console"<<console<<endl;
}


std::string Game::getConsole(){
    return console;
}


void Game::setConsole(std::string co){
    console=co;
}

std::ostream & operator<<(ostream &out, Game& s) {
    out << s.title << '\n';
    out << s.genre << '\n';
    out << s.id << '\n';
    out << s.prodYear << '\n';
    out << s.rented << '\n';
    out << s.serial << '\n';
    out << s.console << '\n';
    return out;
}

std::istream & operator>>(istream &in, Game& s) {
    in >> s.title;
    in >> s.genre;
    in >> s.id;
    in >> s.prodYear;
    in >> s.rented;
    in >> s.serial;
    in >> s.console;
    return in;
}