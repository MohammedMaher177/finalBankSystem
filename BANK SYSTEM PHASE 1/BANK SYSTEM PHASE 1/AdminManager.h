#pragma once
#include "Admin.h"
#include "FileManager.h"
class AdminManager
{
public:

	static void printAdminMenu();
	static Admin* login(int id, string password);
	static bool AdminOptions(Admin* admin);
	static Employee* newEmployee();
	static double enterSalary();
	static int searchEmpl(Admin);
	static void editEmployee(Admin);
	static void searchEmployee(Admin);
	static void getOption(Admin,Employee);
	static void editEmployeeInfo(Admin, Employee);
	static void editEmployeeData(Employee);
};

