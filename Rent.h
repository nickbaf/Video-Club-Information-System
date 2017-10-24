#ifndef RENT_H
#define	RENT_H
#include <string>
class Rent {
public:
    Rent(int newCustomerID,int newProductID);
    Rent();
    int getCustomerID();
    int getProductID();
    int getYear();
    int getMonth();
    int getDay();
    friend std::ostream& operator<< (std::ostream &out,Rent &r);
    friend std::istream& operator>> (std::istream &in,Rent &r);
protected:    //na balw metablhth pou na leei ti eidos einai?
    int customerID;
    int productID;
    int year;  
    int month;
    int day;
};

#endif	/* RENT_H */

