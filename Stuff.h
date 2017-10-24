#ifndef STUFF_H
#define STUFF_H
#include <string>

class Stuff {
public:
    Stuff(int id, int s, std::string titl, std::string gnr, int prod);
    virtual ~Stuff();
    Stuff();
    void SetProdYear(int prodYear);
    int GetProdYear() const;
    void SetGenre(std::string genre);
    std::string GetGenre() const;
    void SetTitle(std::string title);
    std::string GetTitle() const;
    void SetSerial(int serial);
    int GetSerial() const;
    void SetId(int id);
    int GetId() const;
    void SetRented(bool rented);
    bool IsRented() const;
    virtual void print();
    friend std::ostream& operator<<(std::ostream &out, Stuff &s);
    friend std::istream& operator>>(std::istream &in, Stuff &s);

protected:
    int id;
    int serial;
    std::string title;
    std::string genre;
    bool rented;
    int prodYear;
private:

};

#endif // STUFF_H
