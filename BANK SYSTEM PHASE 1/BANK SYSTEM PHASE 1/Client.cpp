#include "Client.h"

Client::Client() {
    balance = 0;
}
Client::Client(string name, int id, string password, double balance) :Person(name, id, password) { 
    if (Validation::checkBalance(balance)) {
        this->balance = balance;
    }
}
Client::~Client() {}

//setters
void Client::setBalance(double balance) { this->balance = balance; }
void Client::setInfo(string name, int id, string password, double balance)
{
    setName(name);
    this->id = id;
    setPasswword(password);
    if (Validation::checkBalance(balance)) {
        this->balance = balance;
    }
}

//getters
double Client::getBalance() { return balance; }
//methods
void Client::display() {
    string ids = to_string(id);
    cout << id;
    for (int i = 0; i < 10 - ids.length(); i++) {
        cout << " ";
    }
    cout << name;
    for (int i = 0; i < 30 - name.length(); i++) {
        cout << " ";
    }
    cout << password;
    for (int i = 0; i < 30 - password.length(); i++) {
        cout << " ";
    }
    cout << balance << endl;
}
void Client::deposit(double amount) {
    balance += amount;
}
void Client::withdraw(double amount)
{
    if (amount <= balance) { balance -= amount; }
    else { cout << "NOT ALLOWED"; }
}
void Client::transfer(Client &recipient, double amount) {
        withdraw(amount);
        recipient.deposit(amount);
}
void Client::checkBalance() {
    cout << "BALANCE: " << balance << endl;
}
