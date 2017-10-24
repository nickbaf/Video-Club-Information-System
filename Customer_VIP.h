#include <string>
#include "Customer.h"

#ifndef CUSTOMER_VIP_H
#define	CUSTOMER_VIP_H

using namespace std;

class Customer_VIP : public Customer {
public:
    Customer_VIP(int newID,string newName,string newSurname,string newDate,bool newSex,string newAdress,int newPhone,int newCreditCard,string newBank,int newCvn);
    
    int getCreditCard();
    void setCreditCard(int newCreditCard);
    
    string getBank();
    void setBank(string newBank);
    void print();
    int getCvn();
    void setCvn(int newCvn);
   friend std::ostream& operator<< (std::ostream &out,Customer_VIP &s);
    friend std::istream& operator>> (std::istream &in,Customer_VIP &s);
private:
    int creditCard;
    string bank;
    int cvn;
};

#endif	/* CUSTOMER_VIP_H */

