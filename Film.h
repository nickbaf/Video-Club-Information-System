#ifndef FILM_H
#define FILM_H
#include <string>

#include "Stuff.h"

class Film : public Stuff {
public:
    Film(int id, int s, std::string titl, std::string gnr, int prod, std::string dir, std::string act, int lenth,bool blue);
    virtual ~Film();
    Film();
    std::string getDirect();
    std::string getActors();
    int getLenth();
    void setLenth(int lenth);
    void setActors(std::string actors);
    void setDirector(std::string director);
    void print();
    bool getBlue();
    void setBlue(bool ray);
    friend std::ostream& operator<< (std::ostream &out,Film &s);
    friend std::istream& operator>> (std::istream &in,Film &s);
protected:
private:
    std::string director;
    std::string actors;
    int lenth;
    bool blueRay;
};

#endif // FILM_H
