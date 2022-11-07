#pragma once
#include "Person.h"
class Client :
    public Person
{
private:
    double balance;
public:
    Client();
    Client(string name, int id, string password, double balance);
    ~Client();

    //setters
    void setBalance(double balance);
    void setInfo(string name, int id, string password, double balance);

    //getters
    double getBalance();
    //methods
    void display();
    void deposit(double amount);
    void withdraw(double amount);
    void transfer(Client &recipient, double amount);
    void checkBalance();
};

