#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <ctime>

#include "Stuff.h"
#include "Game.h"
#include "Film.h"
#include "Series.h"
#include "Rent.h"
#include "Customer.h"
#include "Customer_VIP.h"

using namespace std;

struct films {
    Film dat;
    films *next;
} *headF = NULL;

struct series {
    Series dat;
    series *next;
} *headS = NULL;

struct games {
    Game dat;
    games *next;
} *headG = NULL;

struct clients{
    Customer cust;
    clients *next;
}*headC=NULL;

struct clientsVIP{
    Customer_VIP cust;
    clientsVIP *next;
}*headCV=NULL;


struct rents{
    Rent r;
    rents *next;
}*headR=NULL;

games* insertGame(Game aClass, games *head);
series* insertSeries(Series aClass, series *head);
films * insertFilm(Film aClass, films *head);
clients *insertCl(Customer aClass, clients *head);
clientsVIP *insertClVIP(Customer_VIP aClass, clientsVIP *head);
rents *insertRent(Rent aClass, rents *head);
clients *deleteCl(clients *head, int serial);
clientsVIP *deleteClVIP(clientsVIP *head, int serial);
rents *deleteRent(rents *head, int prodID,int custID);
films *deleteFilm(films *head, int serial,int id);
series *deleteSeries(series *head, int serial, int id);
games *deleteGames(games *head, int serial,int id);
games *findGames(int id,int serial, string title,games *head,bool available_only);
series *findSeries(int id,int serial, string title,series *head,bool available_only);
films *findFilm(int id,int serial, string title,films *head,bool available_only);
clients *findClient(int id,string name, struct clients *head);
clientsVIP *findClientVIP(int id,string name,clientsVIP *head);
rents *findRents(int prodID,int custID, rents *head);

void menu();

void edit_prod();
void edit_game(Game &prod);
void edit_game_specs(Game &prod);
void edit_film(Film &prod);
void edit_film_specs(Film &prod);
void edit_series(Series &prod);
void edit_series_specs(Series &prod);

void cust_menu();
void edit_cust(Customer &cust);
void edit_custVIP(Customer_VIP &cust);

void search_cust(bool edit);
void search_custByID(bool edit);
void search_custBySurname(bool edit);

void rent_prod();
void return_prod();

void search_prod(bool edit);
void search_prodByID(bool edit);
void search_prodByTitle(bool edit);

void add_cust();
void add_custRegular();
void add_custVIP();
void add_game();
void add_series();
void add_film();

void printGames();
void printSeries();
void printFilms();
void printClients();
void printClientsVIP();

int main(int argc, char** argv) {
   
   menu(); 
   return 0;
}

void menu(){
    int x;
    bool end;
    end = false;
    do{
        cout<<endl<<"Welcome to the video club manager application. Please choose an action from the list."<<endl;
        cout<<"1. Edit content"<<endl;
        cout<<"2. Edit customers"<<endl;
        cout<<"3. Rent product"<<endl;
        cout<<"4. Return product"<<endl;
        cout<<"5. Search product"<<endl;
        cout<<"6. Show all products"<<endl;
        cout<<"7. Show all customers"<<endl;
        cout<<"8. Save/Load"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"Selection: ";
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (x) {
            case 1 :
                edit_prod();
                break;
            case 2 :
                cust_menu();
                break;
            case 3 :
                rent_prod();
                break;
            case 4 :
                return_prod();
                break;
            case 5 :
                search_prod(false);
                break;
            case 6 :
                printGames();
                printFilms();
                printSeries();
                break;
            case 7 :
                printClients();
                printClientsVIP();
                break;
            case 8 :
                //SAVE LOAD
                break;    
            case 9 :
                end=true;
                break;
            default :
                cout<<"Wrong input"<<endl;
                break;
        }
    }while(!end);
}

void edit_prod(){
    int x;
    bool end;
    end=false;
    cout<<"Selection: ";
    do{
        
        cout<<endl<<"Please choose if you want to edit an existing product or to add a new product."<<endl;
        cout<<"1. Search for product"<<endl;
        cout<<"2. Add product"<<endl;
        cout<<"9. Go back"<<endl;
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (x) {
            case 1 :
                search_prod(true);
            case 2 :
                do{
                    
                    cout<<endl<<"Choose the type of product you want to add"<<endl;
                    cout<<"1. Game"<<endl;
                    cout<<"2. Film"<<endl;
                    cout<<"3. Series"<<endl;
                    cout<<"9. Back"<<endl;
                    cin>>x;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    switch (x) {
                        case 1 :
                            add_game();
                            break;
                        case 2 :
                            add_film();
                            break;
                        case 3 :
                            add_series();
                            break;    
                        case 9 :
                            end=true;
                            break;
                        default :
                        cout<<"Wrong input"<<endl;
                        break;
                    }
                }while(!end);
                end=false;
                break;
            case 9 :
                end=true;
                break;
            default :
                cout<<"Wrong input"<<endl;
                break;
        }
    }while(!end);
}



void add_game(){
    int id,serial,year;
    string title,genre,console;
    cout<<"Please insert the required information."<<endl;
    cout<<"ID : ";
    cin>>id;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Serial number : ";
    cin>>serial;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Title : ";
    cin>>title;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Genre : ";
    cin>>genre;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Year of production : ";
    cin>>year;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Platform : ";
    cin>>console;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Game g = Game(id, serial, title, genre, year, console);
    headG=insertGame(g,headG);
}

void add_film(){
    int id,serial,year;
    string title,genre,director,actors;
    int length;
    bool blue=false;
    cout<<"Please insert the required information."<<endl;
    cout<<"ID : ";
    cin>>id;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Serial number : ";
    cin>>serial;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Title : ";
    cin>>title;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Genre : ";
    cin>>genre;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Year of production : ";
    cin>>year;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Director : ";
    cin>>director;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Actors (seperate each name by comma): ";
    cin>>actors;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Film length : ";
    cin>>length;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Is it DVD or BluRay? (0:DVD 1:BluRay) : ";
    cin>>length;
    if (length==1){
        blue=true;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Film f = Film (id, serial, title, genre, year, director,actors,length,blue);
    headF=insertFilm(f,headF);
}

void add_series(){
    int id,serial,year,epA,epB,season;
    string title,genre,director,actors;
    bool blue = false;
    cout<<"Please insert the required information."<<endl;
    cout<<"ID : ";
    cin>>id;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Serial number : ";
    cin>>serial;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Title : ";
    cin>>title;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Genre : ";
    cin>>genre;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Year of production : ";
    cin>>year;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Director : ";
    cin>>director;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Actors (seperate each name by comma): ";
    cin>>actors;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Season : ";
    cin>>season;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"First episode : ";
    cin>>epA;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Last episode : ";
    cin>>epB;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Is it DVD or BluRay? (0:DVD 1:BluRay) : ";
    cin>>id;
    if (id==1){
        blue=true;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Series s = Series (id, serial, title, genre, year,season,epA,epB, director,actors,blue);
    headS=insertSeries(s,headS);
}

void edit_game(Game &prod){
    int x;
    bool end;
    int sn; //serial number
    end=false;
    Game newProd = prod;
    do{
        
        cout<<endl<<"Choose your desired action"<<endl;
        cout<<"1. Add a copy of the game"<<endl;
        cout<<"2. Remove a copy of the game"<<endl;
        cout<<"3. Edit the game's properties"<<endl;
        cout<<"4. Remove the game completely"<<endl;
        cout<<"9. Go back"<<endl;
        cout<<"Selection: ";
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(x) {
            case 1 :
                cout<<"Enter the serial number of the new copy"<<endl;
                cout<<"Serial Number : ";
                cin>>sn;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                newProd.SetSerial(sn);
                headG = insertGame(newProd,headG);
                cout<<"Added one more copy of "<<prod.GetTitle()<<endl;
                break;
            case 2 :
                cout<<"Enter the serial number of the copy you wish to delete"<<endl;
                cout<<"Serial Number : ";
                cin>>sn;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                headG = deleteGames(headG,sn,-1);
                cout<<"Removed one copy of "<<prod.GetTitle()<<endl;
                break;
            case 3 :
                edit_game_specs(prod);
                break;
            case 4 :
                headG = deleteGames(headG,-1,prod.GetId());
                cout<<"Deleted all copies of "<<prod.GetTitle()<<endl;
                break;
            case 9 :
                end=true;
                break;
            default :
                cout<<"Wrong input"<<endl;
                break; 
        }
    }while(!end);    
}

void edit_game_specs(Game &prod){
    int x;
    bool end=false;
    string str;
    int year;
    do{
        //show
        cout<<endl<<"Choose the feature you would like to edit of the game."<<endl;
        cout<<"1. Title"<<endl;
        cout<<"2. Genre"<<endl;
        cout<<"3. Year of production"<<endl;
        cout<<"4. Platform"<<endl;
        cout<<"9. Go back"<<endl;
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(x) {
            case 1 :
                cout<<"Enter the new title : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.SetTitle(str);
                break;
            case 2 :
                cout<<"Enter the new genre : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.SetGenre(str);
                break;
            case 3 : 
                cout<<"Enter the new year of production : ";
                cin>>year;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.SetProdYear(year);
                break;
            case 4 :
                cout<<"Enter the new platform : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.setConsole(str);
                break;
            case 9 :
                end=true;
                break;
            default :
                cout<<"Wrong input"<<endl;
                break;
        }
    }while(!end);
}

void edit_film(Film &prod){
    int x;
    bool end;
    int sn; //serial number
    end=false;
    Film newProd = prod;
    do{
        
        cout<<endl<<"Choose your desired action"<<endl;
        cout<<"1. Add a copy of the film"<<endl;
        cout<<"2. Remove a copy of the film"<<endl;
        cout<<"3. Edit the film's properties"<<endl;
        cout<<"4. Remove the film completely"<<endl;
        cout<<"9. Go back"<<endl;
        cout<<"Selection: ";
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(x) {
            case 1 :
                cout<<"Enter the serial number of the new copy"<<endl;
                cout<<"Serial Number : ";
                cin>>sn;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                newProd.SetSerial(sn);
                headF = insertFilm(newProd,headF);
                cout<<"Added one more copy of "<<prod.GetTitle()<<endl;
                break;
            case 2 :
                cout<<"Enter the serial number of the copy you wish to delete"<<endl;
                cout<<"Serial Number : ";
                cin>>sn;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                headF = deleteFilm(headF,sn,-1);
                cout<<"Removed one copy of "<<prod.GetTitle()<<endl;
                break;
            case 3 :
                edit_film_specs(prod);
                break;
            case 4 :
                headF = deleteFilm(headF,-1,prod.GetId());
                cout<<"Deleted all copies of "<<prod.GetTitle()<<endl;
                break;
            case 9 :
                end=true;
                break;
            default :
                cout<<"Wrong input"<<endl;
                break; 
        }
    }while(!end);    
}

void edit_film_specs(Film &prod){
    int x;
    bool end=false;
    string str;
    int integ;
    bool blue;
    do{
        //show
        cout<<endl<<"Choose the feature you would like to edit of the film."<<endl;
        cout<<"1. Title"<<endl;
        cout<<"2. Genre"<<endl;
        cout<<"3. Year of production"<<endl;
        cout<<"4. Director"<<endl;
        cout<<"5. Actors"<<endl;
        cout<<"6. Length"<<endl;
        cout<<"7. BluRay or DVD"<<endl;
        cout<<"9. Go back"<<endl;
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(x) {
            case 1 :
                cout<<"Enter the new title : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.SetTitle(str);
                break;
            case 2 :
                cout<<"Enter the new genre : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.SetGenre(str);
                break;
            case 3 : 
                cout<<"Enter the new year of production : ";
                cin>>integ;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.SetProdYear(integ);
                break;
            case 4 :
                cout<<"Enter the new director : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.setDirector(str);
                break;
            case 5 :
                cout<<"Enter the new actors (seperate each actor by comma): ";
                getline(cin,str);
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.setActors(str);
            case 6 :
                cout<<"Enter the new length : ";
                cin>>integ;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.setLenth(integ);
            case 7 :
                cout<<"Enter 0 for DVD or 1 for BluRay : ";
                cin>>integ;
                if (integ==0){
                    blue=false;
                }
                else{
                    blue=true;
                }
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.setBlue(blue);
            case 9 :
                end=true;
                break;
            default :
                cout<<"Wrong input"<<endl;
                break;
        }
    }while(!end);
}

void edit_series(Series &prod){
    int x;
    bool end;
    int sn; //serial number
    end=false;
    Series newProd = prod;
    do{
        
        cout<<endl<<"Choose your desired action"<<endl;
        cout<<"1. Add a copy of the series"<<endl;
        cout<<"2. Remove a copy of the series"<<endl;
        cout<<"3. Edit the series's properties"<<endl;
        cout<<"4. Remove the series completely"<<endl;
        cout<<"9. Go back"<<endl;
        cout<<"Selection: ";
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(x) {
            case 1 :
                cout<<"Enter the serial number of the new copy"<<endl;
                cout<<"Serial Number : ";
                cin>>sn;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                newProd.SetSerial(sn);
                headS = insertSeries(newProd,headS);
                cout<<"Added one more copy of "<<prod.GetTitle()<<endl;
                break;
            case 2 :
                cout<<"Enter the serial number of the copy you wish to delete"<<endl;
                cout<<"Serial Number : ";
                cin>>sn;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                headS = deleteSeries(headS,sn,-1);
                cout<<"Removed one copy of "<<prod.GetTitle()<<endl;
                break;
            case 3 :
                edit_series_specs(prod);
                break;
            case 4 :
                headS = deleteSeries(headS,-1,prod.GetId());
                cout<<"Deleted all copies of "<<prod.GetTitle()<<endl;
                break;
            case 9 :
                end=true;
                break;
            default :
                cout<<"Wrong input"<<endl;
                break; 
        }
    }while(!end);    
}

void edit_series_specs(Series &prod){
    int x;
    bool end=false;
    string str;
    int integ;
    bool blue;
    do{
        //show
        cout<<endl<<"Choose the feature you would like to edit of the series."<<endl;
        cout<<"1. Title"<<endl;
        cout<<"2. Genre"<<endl;
        cout<<"3. Year of production"<<endl;
        cout<<"4. Director"<<endl;
        cout<<"5. Actors"<<endl;
        cout<<"6. Season"<<endl;
        cout<<"7. First episode"<<endl;
        cout<<"8. Final episode"<<endl;
        cout<<"9. Go back"<<endl;
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(x) {
            case 1 :
                cout<<"Enter the new title : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.SetTitle(str);
                break;
            case 2 :
                cout<<"Enter the new genre : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.SetGenre(str);
                break;
            case 3 : 
                cout<<"Enter the new year of production : ";
                cin>>integ;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.SetProdYear(integ);
                break;
            case 4 :
                cout<<"Enter the new director : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.setDirector(str);
                break;
            case 5 :
                cout<<"Enter the new actors (seperate each actor by comma): ";
                getline(cin,str);
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.setActors(str);
            case 6 :
                cout<<"Enter the new season : ";
                cin>>integ;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.setSeason(integ);
            case 7 :
                cout<<"Enter the new first episode : ";
                cin>>integ;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.setEpA(integ);
            case 8 :
                cout<<"Enter the new final episode : ";
                cin>>integ;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.setEpB(integ);
            case 10 :
                cout<<"Enter 0 for DVD or 1 for BluRay : ";
                cin>>integ;
                if (integ==0){
                    blue=false;
                }
                else{
                    blue=true;
                }
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                prod.setBlue(blue);
            case 9 :
                end=true;
                break;
            default :
                cout<<"Wrong input"<<endl;
                break;
        }
    }while(!end);
}

void cust_menu(){
    int x;
    bool end;
    end=false;
    do{
        
        cout<<endl<<"Please choose if you want to edit an existing customer or to add a new one."<<endl;
        cout<<"1. Search for customer to edit"<<endl;
        cout<<"2. Add customer"<<endl;
        cout<<"9. Go back"<<endl;
        cout<<"Selection: ";
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (x) {
            case 1 :
                search_cust(true);
                break;
            case 2 :
                add_cust();
                break;
            case 9 :
                end=true;
                break;
            default :
                cout<<"Wrong input"<<endl;
                break;
        }
    }while(!end);
}

void add_cust(){
    int x;
    bool end = false;
    do{         
        cout<<endl<<"Choose the type of customer you want to add"<<endl;
        cout<<"1. Regular"<<endl;
        cout<<"2. VIP"<<endl;
        cout<<"9. Back"<<endl;
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (x) {
            case 1 :
                add_custRegular();
                break;
            case 2 :
                add_custVIP();
                break;   
            case 9 :
                end=true;
                break;
            default :
            cout<<"Wrong input"<<endl;
            break;
        }
    }while(!end);
}

void add_custRegular(){
    int id,phone;
    bool sex;
    string name,surname,adress,birth;
    cout<<"Please enter the required information"<<endl;
    cout<<endl<<"ID : "<<endl;
    cin>>id;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Name : "<<endl;
    cin>>name;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Surname : "<<endl;
    cin>>surname;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Date of birth : "<<endl;
    cin>>birth;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Sex : "<<endl;
    cin>>sex;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin>>adress;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Phone : "<<endl;
    cin>>phone;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    headC = insertCl(Customer(id,name,surname,birth,sex,adress,phone),headC);
}

void add_custVIP(){
    int id,phone,credit,cvn;
    bool sex;
    string name,surname,adress,bank,birth;
    cout<<"Please enter the required information"<<endl;
    cout<<endl<<"ID : "<<endl;
    cin>>id;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Name : "<<endl;
    cin>>name;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Surname : "<<endl;
    cin>>surname;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Date of birth : "<<endl;
    cin>>birth;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Sex : "<<endl;
    cin>>sex;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin>>adress;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Phone : "<<endl;
    cin>>phone;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Credit card number : "<<endl;
    cin>>credit;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Bank : "<<endl;
    cin>>bank;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"CVN : "<<endl;
    cin>>cvn;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    headCV = insertClVIP(Customer_VIP(id,name,surname,birth,sex,adress,phone,credit,bank,cvn),headCV);
}

void search_cust(bool edit){
    int x;
    bool end = false;
    do{
                    
        cout<<endl<<"Choose how you want to search for the customer"<<endl;
        cout<<"1. Search by ID"<<endl;
        cout<<"2. Search by Surname"<<endl;
        cout<<"9. Go back"<<endl;
        cout<<"Selection: ";
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (x) {
            case 1 :
                search_custByID(edit);
                break;
            case 2 :
                search_custBySurname(edit);
                break;
            case 9 :
                end=true;
                break;
            default :
            cout<<"Wrong input"<<endl;
            break;
        }
    }while(!end);
}

void search_custByID(bool edit){
    int custID;
    cout<<"Please enter the ID of the customer you wish to search. Enter 0 to exit this menu."<<endl;
    cout<<"Customer ID: ";
    cin>>custID;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (custID!=0){
        clients *found;
        found = findClient(custID,"whatever",headC);
        if (found!=NULL){
            if (edit){
                edit_cust(found->cust);
            }
            else{
                //show
            }
        }
        else{
            clientsVIP *foundVIP;
            foundVIP = findClientVIP(custID,"whatever",headCV);
            if (foundVIP!= NULL){
                if (edit){
                    edit_custVIP(foundVIP->cust);
                }
                else{
                    //show
                }
            }
            else{
                cout<<"Customer not found"<<endl;
            }
        }
    }
    else{
        cout<<"Operation canceled"<<endl;
    }
}

void search_custBySurname(bool edit){
    string s;
    cout<<"Please enter the surname of the customer you wish to search. Enter 0 to exit this menu."<<endl;
    cout<<"Surname : ";
    cin>>s;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (s!="0"){
        clients *found;
        found = findClient(-1,s,headC);
        if (found!=NULL){
            if (edit){
                edit_cust(found->cust);
            }
            else{
                //show
            }
        }
        else{
            clientsVIP *foundVIP;
            foundVIP = findClientVIP(-1,s,headCV);
            if (foundVIP!= NULL){
                if (edit){
                    edit_custVIP(foundVIP->cust);
                }
                else{
                    //show
                }
            }
            else{
                cout<<"Customer not found"<<endl;
            }
        }
    }
    else{
        cout<<"Operation canceled"<<endl;
    }
}

void edit_cust(Customer &cust){
    int x,integ;
    string str;
    bool sex;
    bool end = false;
    do{
        //na emfanizei ta current stoixeia tou
        cout<<endl<<"Choose the information you wish to change"<<endl;
        cout<<"1. Name"<<endl;
        cout<<"2. Surname"<<endl;
        cout<<"3. Date of birth"<<endl;
        cout<<"4. Sex"<<endl;
        cout<<"5. Adress"<<endl;
        cout<<"6. Phone number"<<endl;
        cout<<"9. Go back"<<endl;
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (x){
            case 1 :
                cout<<endl<<"Enter the new name"<<endl<<"Name : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setName(str);
                break;
            case 2 :
                cout<<endl<<"Enter the new surname"<<endl<<"Surname : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setSurname(str);
                break;
            case 3 :
                cout<<endl<<"Enter the new date of birth"<<endl<<"Date of birth : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setDate(str);
                break;
            case 4 :
                cout<<endl<<"Enter the new sex"<<endl<<"Sex : ";
                cin>>sex;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setSex(sex);
                break;
            case 5 :
                cout<<endl<<"Enter the new adress"<<endl<<"Adress : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setAdress(str);
                break;
            case 6 :
                cout<<endl<<"Enter the new phone number"<<endl<<"Phone number : ";
                cin>>integ;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setPhone(integ);
                break;
            case 9 :
                end=true;
                break;
            default:
                cout<<"Wrong input"<<endl;
                break;
        }
    }while(!end);
}

void edit_custVIP(Customer_VIP &cust){
    int x,integ;
    string str;
    bool sex;
    bool end = false;
    do{
        //na emfanizei ta current stoixeia tou
        cout<<endl<<"Choose the information you wish to change"<<endl;
        cout<<"1. Name"<<endl;
        cout<<"2. Surname"<<endl;
        cout<<"3. Date of birth"<<endl;
        cout<<"4. Sex"<<endl;
        cout<<"5. Adress"<<endl;
        cout<<"6. Phone number"<<endl;
        cout<<"7. Credit card number"<<endl;
        cout<<"8. Bank"<<endl;
        cout<<"10. CVN"<<endl;
        cout<<"9. Go back"<<endl;
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (x){
            case 1 :
                cout<<endl<<"Enter the new name"<<endl<<"Name : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setName(str);
                break;
            case 2 :
                cout<<endl<<"Enter the new surname"<<endl<<"Surname : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setSurname(str);
                break;
            case 3 :
                cout<<endl<<"Enter the new date of birth"<<endl<<"Date of birth : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setDate(str);
                break;
            case 4 :
                cout<<endl<<"Enter the new sex"<<endl<<"Sex : ";
                cin>>sex;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setSex(sex);
                break;
            case 5 :
                cout<<endl<<"Enter the new adress"<<endl<<"Adress : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setAdress(str);
                break;
            case 6 :
                cout<<endl<<"Enter the new phone number"<<endl<<"Phone number : ";
                cin>>integ;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setPhone(integ);
                break;
            case 7 :
                cout<<endl<<"Enter the new credit card number"<<endl<<"Credit card number : ";
                cin>>integ;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setCreditCard(integ);
                break;
            case 8 :
                cout<<endl<<"Enter the new bank"<<endl<<"Bank : ";
                cin>>str;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setBank(str);
                break;
            case 10 :
                cout<<endl<<"Enter the new CVN"<<endl<<"CVN : ";
                cin>>integ;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cust.setCvn(integ);
                break;
            case 9 :
                end=true;
                break;
            default:
                cout<<"Wrong input"<<endl;
                break;
        }
    }while(!end);
}

void rent_prod(){
    int custID, prodID;
    cout<<"Please enter the ID of the customer and the ID of the product for rent. Enter 0 for both values to exit this menu."<<endl;
    cout<<"Customer ID: ";
    cin>>custID;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Product ID: ";
    cin>>prodID;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (custID != 0 || prodID != 0){
        clients *foundCl;
        clientsVIP *foundClVIP;
        foundClVIP = findClientVIP(custID,"whatever",headCV);
        foundCl = findClient(custID,"whatever",headC);
        if (foundCl!=NULL || foundClVIP!=NULL){
            games *foundG;
            foundG = findGames(prodID,-1,"whatever",headG,true);
            if (foundG!=NULL){
                Rent newRent = Rent(custID,prodID);
                foundG->dat.SetRented(true);
            }
            else{
                films *foundF;
                foundF = findFilm(prodID,-1,"whatever",headF,true);
                if (foundF!=NULL){
                    Rent newRent = Rent(custID,prodID);
                    foundF->dat.SetRented(true);
                }
                else{
                    series *foundS;
                    foundS = findSeries(prodID,-1,"whatever",headS,true);
                    if (foundS!=NULL){
                        Rent newRent = Rent(custID,prodID);
                        foundF->dat.SetRented(true);
                    }
                    else{
                        cout<<"Customer found. Product not found"<<endl;
                    }
                }
            }
        }    
        else{
            cout<<"Customer not found"<<endl;
        }
        cout<<endl<<"Operation succesfull."<<endl;
    }
    else{
        cout<<"Operation canceled."<<endl;
    }
}

void return_prod(){
    int prodID,custID,year,month,day;
    float cost;
    cout<<"Please enter the ID of the customer and the ID of the product you want to return. Enter 0 for both values to exit this menu."<<endl;
    cout<<"Customer ID: ";
    cin>>custID;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<endl<<"Product ID: ";
    cin>>prodID;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int rentDays;
    if (prodID != 0 and custID!=0){
        rents *foundR;
        foundR = findRents(prodID,custID,headR);
        if (foundR!=NULL){
            clients *foundCl;
            clientsVIP *foundClVIP;
            foundClVIP = findClientVIP(custID,"whatever",headCV);
            foundCl = findClient(custID,"whatever",headC);
            if (foundCl!=NULL || foundClVIP!=NULL){
                time_t now = time(0);
                tm *ltm = localtime(&now);

                year = 1900 + ltm->tm_year;
                month = 1 + ltm->tm_mon;
                day = ltm->tm_mday;
                Rent r = foundR->r;
                rentDays = (day + month*30 + year*365) - ( r.getDay() + r.getMonth()*30 + r.getYear()*365);
                
                games *foundG;
                foundG = findGames(prodID,-1,"whatever",headG,false);
                if (foundG!=NULL){
                    if (rentDays<=2){
                        cost = 3;
                    }
                    else{
                        cost = 3 + (rentDays-2);
                    }
                }
                else{
                    films *foundF;
                    foundF = findFilm(prodID,-1,"whatever",headF,false);
                    if (foundF!=NULL){
                        if (foundF->dat.getBlue()){
                            cost = rentDays*2;
                        }
                        else{
                            if (rentDays<=3){
                                cost = 1;
                            }
                            else{
                                cost = 1 + (rentDays-3)*0.5;
                            }
                        }
                        if (rentDays<365){
                            cost += cost*0.5;
                        }
                    }
                    else{
                        series *foundS;
                        foundS = findSeries(prodID,-1,"whatever",headS,false);
                        if (foundS!=NULL){
                            if (rentDays<=3){
                                cost = 2;
                            }
                            else{
                                cost = 2 + (rentDays-3)*0.5;
                            }
                            if (foundS->dat.getBlue()){
                                cost += 1;
                            }
                        }
                        else{
                            cout<<"Customer found. Product not found"<<endl;
                        }
                    }
                }
                if (foundClVIP!=NULL){
                    cost -= cost*0.05;
                }
                cout<<"Cost : "<<cost<<endl;
                headR = deleteRent(headR,prodID,custID);
                cout<<endl<<"Operation succesfull."<<endl;
            }
            else{
                cout<<"Customer not found"<<endl;
            }
        }
        else{
            cout<<"Rented product not found"<<endl;
        }
    }
    else{
        cout<<"Operation canceled."<<endl;
    }
}


void search_prod(bool edit){
    int x;
    bool end;
    end=false;
    do{
        
        cout<<endl<<"Would you like to search for a product using its ID or its Title?"<<endl;
        cout<<"1. Search by ID"<<endl;
        cout<<"2. Search by Title"<<endl;
        cout<<"9. Go back"<<endl;
        cout<<"Selection: ";
        cin>>x;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (x) {
            case 1 :
                search_prodByID(edit);
                break;
            case 2 :
                search_prodByTitle(edit);
                break;
            case 9 :
                end=true;
                break;
            default :
                cout<<"Wrong input"<<endl;
                break;    
        }
    }while(!end);
}

void search_prodByID(bool edit){
    int prodID;
    string s;
    cout<<"Please enter the ID of the product you wish to search. Enter 0 to exit this menu."<<endl;
    cout<<"Product ID: ";
    cin>>prodID;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (prodID != 0){
        games *foundG;
        foundG = findGames(prodID,-1,"whatever",headG,false);
        if (foundG!=NULL){
            if (edit){
                edit_game(foundG->dat);
            }
            else{
                //show
            }
        }
        else{
            films *foundF;
            foundF = findFilm(prodID,-1,"whatever",headF,false);
            if (foundF!=NULL){
                if (edit){
                    edit_film(foundF->dat);
                }
                else{
                    //show
                }
            }
            else{
                series *foundS;
                foundS = findSeries(prodID,-1,"whatever",headS,false);
                if (foundS!=NULL){
                    if (edit){
                        edit_series(foundS->dat);
                    }
                    else{
                        //show
                    }
                }
                else{
                    cout<<"Product not found"<<endl;
                }
            }
        }
    }
    else{
        cout<<"Operation canceled."<<endl;
    }
}

void search_prodByTitle(bool edit){
    string title;
    cout<<"Please enter the title of the product you wish to search. Enter 0 to exit this menu."<<endl;
    cout<<"Product Title: ";
    cin>>title;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (title != "0"){
        games *foundG;
        foundG = findGames(-1,-1,title,headG,false);
        if (foundG!=NULL){
            if (edit){
                edit_game(foundG->dat);
            }
            else{
                //show
            }
        }
        else{
            films *foundF;
            foundF = findFilm(-1,-1,title,headF,false);
            if (foundF!=NULL){
                if (edit){
                    edit_film(foundF->dat);
                }
                else{
                    //show
                }
            }
            else{
                series *foundS;
                foundS = findSeries(-1,-1,title,headS,false);
                if (foundS!=NULL){
                    if (edit){
                        edit_series(foundS->dat);
                    }
                    else{
                        //show
                    }
                }
                else{
                    cout<<"Product not found"<<endl;
                }
            }
        }
    }
    else{
        cout<<"Operation canceled."<<endl;
    }
}

//******************************************************************************

films * insertFilm(Film aClass, films *head) {
    films *newStuff, *p = head;
    newStuff = new films;
    newStuff->dat = aClass;
    if (head == NULL) {
        newStuff->next = head;
        return newStuff;
    }
    while (p->next != NULL) {
        p = p->next;
    }
    newStuff->next = p->next;
    p->next = newStuff;
    return head;

}
series* insertSeries(Series aClass, series *head) {
    series *newStuff, *p = head;
    newStuff = new series;
    newStuff->dat = aClass;
    if (head == NULL) {
        newStuff->next = head;
        return newStuff;
    }
    while (p->next != NULL) {
        p = p->next;
    }
    newStuff->next = p->next;
    p->next = newStuff;
    return head;

}
games* insertGame(Game aClass, games *head) {
    games *newStuff, *p = head;
    newStuff = new games;
    newStuff->dat = aClass;
    if (head == NULL) {
        newStuff->next = head;
        return newStuff;
    }
    while (p->next != NULL) {
        p = p->next;
    }
    newStuff->next = p->next;
    p->next = newStuff;
    return head;

}


films *findFilm(int id,int serial, string title,films *head,bool available_only) {
    struct films *p = head;
    if (id == -1 && serial==-1) {
        while (p != NULL) {
            if (p->dat.GetTitle() == title) {
                if (available_only){
                    if (p->dat.IsRented()==false){
                        return p;
                    }    
                }else{
                    return p;
                }    
            } else {
                p = p->next;
            }
        }
    } else if(serial==-1){
        while (p != NULL) {
            if (p->dat.GetId() == id) {
                if (available_only){
                    if (p->dat.IsRented()==false){
                        return p;
                    }    
                }else{
                    return p;
                }
            } else {
                p = p->next;
            }
        }
    }else{
         while (p != NULL) {
            if (p->dat.GetSerial() == serial) {
                if (available_only){
                    if (p->dat.IsRented()==false){
                        return p;
                    }    
                }else{
                    return p;
                }
            } else {
                p = p->next;
            }
        }
    }
    return NULL;
}

series *findSeries(int id,int serial, string title,series *head,bool available_only) {
    struct series *p = head;
    if (id == -1 && serial==-1) {
        while (p != NULL) {
            if (p->dat.GetTitle() == title) {
                if (available_only){
                    if (p->dat.IsRented()==false){
                        return p;
                    }    
                }else{
                    return p;
                }
            } else {
                p = p->next;
            }
        }
    } else if(serial==-1){
        while (p != NULL) {
            if (p->dat.GetId() == id) {
                if (available_only){
                    if (p->dat.IsRented()==false){
                        return p;
                    }    
                }else{
                    return p;
                }
            } else {
                p = p->next;
            }
        }
    }else{
         while (p != NULL) {
            if (p->dat.GetSerial() == serial) {
                if (available_only){
                    if (p->dat.IsRented()==false){
                        return p;
                    }    
                }else{
                    return p;
                }
            } else {
                p = p->next;
            }
        }
    }
    return NULL;
}
games *findGames(int id,int serial, string title,games *head,bool available_only) {
    struct games *p = head;
    if (id == -1 && serial==-1) {
        while (p != NULL) {
            if (p->dat.GetTitle() == title) {
                if (available_only){
                    if (p->dat.IsRented()==false){
                        return p;
                    }    
                }else{
                    return p;
                }
            } else {
                p = p->next;
            }
        }
    } else if(serial==-1){
        while (p != NULL) {
            if (p->dat.GetId() == id) {
                if (available_only){
                    if (p->dat.IsRented()==false){
                        return p;
                    }    
                }else{
                    return p;
                }
            } else {
                p = p->next;
            }
        }
    }else{
         while (p != NULL) {
            if (p->dat.GetSerial() == serial) {
                if (available_only){
                    if (p->dat.IsRented()==false){
                        return p;
                    }    
                }else{
                    return p;
                }
            } else {
                p = p->next;
            }
        }
    }
    return NULL;
}


films *deleteFilm(films *head, int serial,int id) {
    films *p, *pp;
    if (head == NULL) {
        return NULL;
    }
    p = head->next;
    if (id==-1){
        if (head->dat.GetSerial() == serial) {
            free(head);
            return (p);
        }
        pp = head;
        while (p != NULL) {
            if (p->dat.GetSerial() == serial) {
                pp->next = p->next;
                free(p);
                p = pp->next;
            }
            else{
                p = p->next;
                pp = pp->next;
            }
        }
    }
    else{ //sbhnei ola me to idio id (mono auth h leitourgia xreiazetai)
        if (head->dat.GetId() == id) {
            free(head);
        }
        pp = head;
        while (p != NULL) {
            if (p->dat.GetId() == id) {
                if (pp==NULL){
                    pp = p;
                    p = p->next;
                    free(pp);
                }
                else{
                    pp->next = p->next;
                    free(p);
                    p = pp->next;
                }
            }
            else{
                if (pp==NULL){
                    pp = p;
               p = p->next;
                }
                else{
                    p = p->next;
                    pp = pp->next;
                }
            }
        }     
    }
    return head;
}


series *deleteSeries(series *head, int serial,int id) {
    series *p, *pp;
    if (head == NULL) {
        return NULL;
    }
    p = head->next;
    if (id==-1){
        if (head->dat.GetSerial() == serial) {
            free(head);
            return (p);
        }
        pp = head;
        while (p != NULL) {
            if (p->dat.GetSerial() == serial) {
                pp->next = p->next;
                free(p);
                p = pp->next;
            }
            else{
                p = p->next;
                pp = pp->next;
            }
        }
    }
    else{ //sbhnei ola me to idio id (mono auth h leitourgia xreiazetai)
        if (head->dat.GetId() == id) {
            free(head);
        }
        pp = head;
        while (p != NULL) {
            if (p->dat.GetId() == id) {
                if (pp==NULL){
                    pp = p;
                    p = p->next;
                    free(pp);
                }
                else{
                    pp->next = p->next;
                    free(p);
                    p = pp->next;
                }
            }
            else{
                if (pp==NULL){
                    pp = p;
               p = p->next;
                }
                else{
                    p = p->next;
                    pp = pp->next;
                }
            }
        }     
    }
    return head;
}

games *deleteGames(games *head, int serial,int id) {
    games *p, *pp;
    if (head == NULL) {
        return NULL;
    }
    p = head->next;
    if (id==-1){
        if (head->dat.GetSerial() == serial) {
            free(head);
            return (p);
        }
        pp = head;
        while (p != NULL) {
            if (p->dat.GetSerial() == serial) {
                pp->next = p->next;
                free(p);
                p = pp->next;
            }
            else{
                p = p->next;
                pp = pp->next;
            }
        }
    }
    else{ //sbhnei ola me to idio id (mono auth h leitourgia xreiazetai)
        if (head->dat.GetId() == id) {
            free(head);
        }
        pp = head;
        while (p != NULL) {
            if (p->dat.GetId() == id) {
                if (pp==NULL){
                    pp = p;
                    p = p->next;
                    free(pp);
                }
                else{
                    pp->next = p->next;
                    free(p);
                    p = pp->next;
                }
            }
            else{
                if (pp==NULL){
                    pp = p;
               p = p->next;
                }
                else{
                    p = p->next;
                    pp = pp->next;
                }
            }
        }     
    }
    return head;
}


clients *insertCl(Customer aClass, clients *head) {
    clients *newCl, *p = head;
    newCl =new clients;
    newCl->cust = aClass;
    if (head == NULL) {
        newCl->next = head;
        return newCl;
    }
    while (p->next != NULL) {
        p = p->next;
    }
    newCl->next = p->next;
    p->next = newCl;
    return head;
    
}

rents *insertRent(Rent aClass, rents *head) {
    rents *newRnt, *p = head;
    newRnt =new rents;
    newRnt->r = aClass;
    if (head == NULL) {
        newRnt->next = head;
        return newRnt;
    }
    while (p->next != NULL) {
        p = p->next;
    }
    newRnt->next = p->next;
    p->next = newRnt;
    return head;
    
}

clients *deleteCl(clients *head, int id) {
    clients *p, *pp;
    if (head == NULL) {
        return NULL;
    }
    p = head->next;
    if (head->cust.getID()==id) {
        free(head);
        return (p);
    }
    pp = head;
    while (p != NULL) {
        if (p->cust.getID() == id) {
            pp->next = p->next;
            free(p);
            p = pp->next;
        }
        else{
            p = p->next;
            pp = pp->next;
        }
    }
    return head;
}

rents *deleteRent(rents *head, int prodID,int custID) {
    rents *p, *pp;
    if (head == NULL) {
        return NULL;
    }
    p = head->next;
    if (head->r.getProductID()==prodID && head->r.getCustomerID()==custID) {
        free(head);
        return (p);
    }
    pp = head;
    while (p != NULL) {
        if (p->r.getProductID()==prodID && p->r.getCustomerID()==custID){
            pp->next = p->next;
            free(p);
            p = pp->next;
        }
        else{
            p = p->next;
            pp = pp->next;
        }
    }
    return head;
}

clients *findClient(int id,string name, clients *head) {
    struct clients *p = head;
    if(id==-1){
        while (p != NULL) {
            if (p->cust.getSurname()==name) {
                return p;
            } else {
                p = p->next;
            }
        }
    }else{
        while (p != NULL) {
            if (p->cust.getID()==id) {
                return p;
            } else {
                p = p->next;
            }
        }
    }
    return NULL;

}

rents *findRents(int prodID,int custID, rents *head) {
    struct rents *p = head;
    while (p != NULL) {
        if (p->r.getProductID()==prodID && p->r.getCustomerID()==custID) {
            return p;
        } else {
            p = p->next;
        }
    }
    return NULL;
}

void printGames() {
    games *p = headG;
    while (p != NULL) {
        //show
        p = p->next;
    }
}

void printFilms() {
    films *p = headF;
    while (p != NULL) {
        //show
        p = p->next;
    }
}

void printSeries() {
    series *p = headS;
    while (p != NULL) {
        //show
        p = p->next;
    }
}

void printClients() {
    clients *p = headC;
    while (p != NULL){
        //show
        p = p->next;
    }
}

void printClientsVIP(){
    clientsVIP *p = headCV;
    while (p != NULL){
        //show
        p = p->next;
    }
}

/*void WriteBinaryFile() {
    FILE *bin_file;
   Stuff st(12,33 ,"star trek","comedy",2012);
    string fname;

    printf("\n Give filename\n");
    cin>>fname;
    std::ofstream ofs(fname, ios::out);
    ofs<<st;
    
}*/
