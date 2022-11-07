#pragma once
#include "Employee.h"
class EmployeeManager
{
public:
	static void printEmployeeMenu();
	static string enterPAssword();
	static string enterName();
	static double enterBalance();
	static void newClient(Employee* employee);
	static void listAllClients(Employee* employee);
	static void searchForClient(Employee* employee);
	static void editClientInfo(Employee* employee);
	static Employee* login(int id, string password);
	static bool employeeOptions(Employee* employee);
	static string passwordSet();
	static void updatePassword(Employee* p);
	static void getOption(Client& client);
	static void EditClientData(Employee employee, Client client);
};

