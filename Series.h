#ifndef SERIES_H
#define SERIES_H
#include <string>
#include "Stuff.h"

class Series : public Stuff {
public:
    Series(int id, int s, std::string titl, std::string gnr, int prod, int season, int epA, int epB, std::string director, std::string actors,bool blue);
    virtual ~Series();
    Series();
    int getSeason();
    int getEpA();
    int getEpB();
    std::string getActors();
    void setActors(std::string actors);
    void setDirector(std::string director);
    std::string getDirector() const;
    void setEpB(int epB);
    void setEpA(int epA);
    void setSeason(int season);
    void setBlue(bool ray);
    bool getBlue();
    friend std::ostream& operator<< (std::ostream &out,Series &s);
    friend std::istream& operator>> (std::istream &in,Series &s);
    void print();
protected:
private:
    int season;
    int epA;
    int epB; //boroun na ginoun kai se pinaka
    std::string director;
    std::string actors;
    bool blueRay;
};

#endif // SERIES_H
