#ifndef GAME_H
#define GAME_H
#include "Stuff.h"
#include <string>

class Game : public Stuff {
public:
    Game(int id, int s, std::string titl, std::string gnr, int prod, std::string console);
    void setConsole(std::string co);
    Game();
    virtual ~Game();
    void print();
    std::string getConsole();
    friend std::ostream& operator<<(std::ostream &out, Game &s);
    friend std::istream& operator>>(std::istream &in, Game &s);
protected:
private:
    std::string console;
};

#endif // GAME_H
