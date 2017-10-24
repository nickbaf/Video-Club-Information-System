#include <string>

#ifndef CUSTOMER_H
#define	CUSTOMER_H


using namespace std;

class Customer {
public:
    Customer(int newID,string newName,string newSurname,string newDate,bool newSex,string newAdress,int newPhone);
    Customer();

    int getID();
    void setID(int newID);
    
    string getName();
    void setName(string newName);
    
    string getSurname();
    void setSurname(string newSurname);
    
    string getDate();
    void setDate(string newDate);
    
    bool getSex();
    void setSex(bool newSex);
    
    string getAdress();
    void setAdress(string newAdress);
    void print();
    int getPhone();
    void setPhone(int newPhone);
    friend std::ostream& operator<< (std::ostream &out,Customer &s);
    friend std::istream& operator>> (std::istream &in,Customer &s);
protected:
    int ID; //arithmos tautothtas
    string name;
    string surname;
    string date;
    bool sex;
    string adress;
    int phone;
};

#endif	/* CUSTOMER_H */

