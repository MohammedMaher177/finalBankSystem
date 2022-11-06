#include "Employee.h"
#include "Client.h"
#include "EmployeeManager.h"
#include "FileManager.h"
#include <fstream>
#include "FilesHelper.h"
#include "Log.h"
FileManager fff;
ofstream o1;
ifstream i1;
Employee::Employee() {}
Employee::Employee(string name, int id, string password, double salary) 
{
    setName(name);
    this->id = id;
    setPasswword(password);
    if (Validation::checkBalance(salary)) {
        this->salary = salary;
    }
}
Employee::~Employee() {}
//setters
void Employee::setSalary(double salary) {
    if (Validation::checkBalance(salary)) {
        this->salary = salary;
    }
}
//getters
double Employee::getSalary() { return salary; }
void Employee::display() {
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
    cout << salary << endl;
}

void Employee::setInfo(string name, int id, string password, double salary)
{
    setName(name);
    this->id = id;
    setPasswword(password);
    if (Validation::checkBalance(salary)) {
        this->salary = salary;
    }
}

void Employee::addClient(Client& c) {
    fff.addClient(c);
}
Client* Employee::searchClient(int id) {
    Client* cli = new Client;
    for (int i = 0; i < fff.getAllClients().size() - 1; i++) {
        if (id == fff.getAllClients()[i].getId()) {
            *cli = fff.getAllClients()[i];
            return cli;
        }
    }
    return nullptr;
}
void Employee::listClient() {
    Log::log("THE CLIENT LIST");
    cout << "ID\t  NAME\t\t\t\tPASSWORD\t\t      BALANCE\n";
    for (int i = 0; i < fff.getAllClients().size() - 1; i++) {
        fff.getAllClients()[i].display();
    }
}

void Employee::editClient(int id, string name, string password, double balance) {
    vector<Client> temp = fff.getAllClients();
    for (int i = 0; i < temp.size(); i++){
        if (id == temp[i].getId()){
            temp[i].setInfo(name, id, password, balance);
            break;
        }
    }
    o1.open("Client.txt", ios::out | ios::trunc);
    o1.close();
    o1.open("Client.txt", ios::out);
    for (int i = 0; i < temp.size() - 1; i++) {
        o1 << temp[i].getName() << " "
            << temp[i].getId() << " "
            << temp[i].getPassword() << " "
            << temp[i].getBalance() << endl;
    }
    o1.close();
    return;
}

