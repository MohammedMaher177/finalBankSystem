#pragma once
#include "Employee.h"
class Admin :
    public Employee
{
private:

public:
    Admin();
    Admin(string name, int id, string password, double salary);
    ~Admin(){}
    void display();
    void addEmployee(Employee&);
    Employee* searchEmployee(int);
    void editEmployee(int id, string name, string password, double salary);
    void listEmployee();
    
   
};
