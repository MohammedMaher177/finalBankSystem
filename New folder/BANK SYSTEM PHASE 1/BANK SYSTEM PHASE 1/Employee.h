#pragma once
#include "Person.h"
#include "Client.h"
class Employee :
    public Person
{
protected:
    double salary;
public:
    Employee();
    Employee(string , int , string , double );
    ~Employee();
    //setters
    void setSalary(double salary);
    void setInfo(string, int d, string , double );
    //getters
    double getSalary();
    void display();
    void addClient(Client& c);
    Client* searchClient(int id);
    void listClient();
    void editClient(int , string , string , double );

};

