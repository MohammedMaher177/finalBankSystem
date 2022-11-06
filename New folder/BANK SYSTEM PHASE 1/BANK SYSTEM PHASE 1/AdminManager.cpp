#include "AdminManager.h"
#include "EmployeeManager.h"
#include "FilesHelper.h"
#include "Screen.h"
#include "Log.h"
#include <Windows.h>
FileManager f14;
void AdminManager::printAdminMenu() {
	cout << "\n(1) Display my infot\t\t\t\t(2) Add new client\n\n(3) Search for client\t\t\t\t(4) List all clients\n\n"
		<< "(5) Edit client info\t\t\t\t(6) Add new Employee\n\n(7) Search for Employee\t\t\t\t(8) List all Employees\n\n"
		<< "(9) Edit Employee info\t\t\t\t(10) Logout\n";
}

double AdminManager::enterSalary() {
	string salary1;
	double salary;
	system("cls");
	cout << "ENTER YOUR SALARY PLEASE\n\n";
	cout << "Min Salary 5000\n";
	cin >> salary1;
	if (Validation::checkDouble(salary1)) {
		salary = stod(salary1);
		if (salary >= 5000) 
		{
			return salary;
		}		
		else 
		{
			cout << "\t\t\t\tMin Salary 5000\n";
			system("pause");
			enterSalary();
		}
	}
	else
	{
		cout << "\t\t\t\tINVALID INPUT\n";
		system("pause");
		enterSalary();
	}
}
Employee* AdminManager::newEmployee() {
	Employee* s = new Employee;
	//Log::log("CREAT NEW ACCOUNT");
	s->setName(EmployeeManager::enterName());
	s->setPasswword(EmployeeManager::enterPAssword());
	s->setSalary(AdminManager::enterSalary());
	s->setId(FilesHelper::getLast("EmployeeId.txt"));
	cout << "\n\t\t\t\t\tEMPLOYEE WAS ADDED\n\n";
	cout << "ID\t  NAME\t\t\t\tPASSWORD\t\t      BALANCE\n";
	s->display();
	system("pause");
	return s;
}

int AdminManager::searchEmpl(Admin admin) {
	int id; string idS;
	Log::log("SEARCHING");
	cout << "ENTER ID: \n\n";
	cin >> idS;
	if (Validation::checkInt(idS))
	{
		id = stoi(idS);
	}
	else
	{
		system("cls");
		cout << "INVALID INPUT\n";
		return searchEmpl(admin);
	}
	if (admin.searchEmployee(id) != nullptr) { return id; }
	else
	{
		system("cls");
		cout << "ID not found\n";
		return searchEmpl(admin);
	}
}
void AdminManager::editEmployeeData(Employee employee) {
	Admin admin;
	admin.editEmployee(employee.getId(), employee.getName(), employee.getPassword(), employee.getSalary());
}

void AdminManager::editEmployeeInfo(Admin admin, Employee employee) {
	string optionS;
	int option;
	system("cls");
	cout << "EDIT PROFILE DATA\n";
	cout << "ID\t  NAME\t\t\t\tPASSWORD\t\t      BALANCE\n";
	employee.display();
	cout << "\n=======================================================\n\n";
	cout << "\n1. EDIT NAME\t\t\t\t2. EDIT PASSWORD\n3. EDIT BALANCE\t\t\t\t4. MAIN MENUE\n"
		<< "YOUR OPTION ==> ";
	cin >> optionS;
	if (Validation::checkInt(optionS))
	{
		option = stoi(optionS);
	}
	else
	{
		cout << "\t\t\t\tINVALID INPUT\n";
		system("pause");
		return editEmployeeInfo(admin, employee);
	}
	switch (option)
	{
	case 1:
		employee.setName(EmployeeManager::enterName());
		editEmployeeData(employee);
		system("pause");
		editEmployeeInfo(admin, employee);
		break;
	case 2:
		employee.setPasswword(EmployeeManager::enterPAssword());
		editEmployeeData(employee);
		system("pause");
		editEmployeeInfo(admin, employee);
		break;
	case 3:
		employee.setSalary(AdminManager::enterSalary());
		editEmployeeData(employee);
		system("pause");
		editEmployeeInfo(admin, employee);
		break;
	case 4:
		AdminOptions(&admin);
		break;
	default:
		cout << "\t\t\t\tINVALID INPUT\n";
		system("pause");
		editEmployeeInfo(admin, employee);
		break;
	}
}
void AdminManager::editEmployee(Admin admin) {
	int id;
	vector<Employee> v = f14.getAllEmployees();
	Employee employee;
	id = searchEmpl(admin);
	for (int i = 0; i < v.size(); i++) {
		if (id == v[i].getId()) {
			employee = v[i];
			break;
		}
	}
	editEmployeeInfo(admin, employee);
}
void AdminManager::searchEmployee(Admin admin) {
	system("cls");
	Employee* employee = new Employee;
	employee = admin.searchEmployee(searchEmpl(admin));
	employee->display();
	cout << "\n=====================================\n"
		<< "\n1. EDTI DATA\t\t\t\t2. RESEARCH NEW ACCOUNT\t\t\t\t3. MAIN MENU\n";
	getOption(admin,*employee);
}
void AdminManager::getOption(Admin admin,Employee employee) {
	string optionS; int option;
	cout << "YOUR OPTION ==> ";
	cin >> optionS;
	if (Validation::checkInt(optionS))
	{
		option = stoi(optionS);
	}
	else
	{
		cout << "\nINVALID INPUT\n";
		getOption(admin,employee);
	}
	switch (option)
	{
	case 1:
		AdminManager::editEmployeeInfo(admin, employee);
		system("pause");
		getOption(admin, employee);
		break;
	case 2:
		AdminManager::searchEmployee(admin);
		system("pause");
		getOption(admin, employee);
		break;
	case 3:
		AdminManager::AdminOptions(&admin);
		system("pause");
		getOption(admin, employee);
		break;
	default:
		cout << "INVALID OPTION\tPLEASE REENTER YOUR OPTION\n";
		getOption(admin,employee);
		break;
	}
}
bool AdminManager::AdminOptions(Admin* admin) {
	system("cls");
	system("color f1");
	Log::successfu("LOG IN");
	cout << "\t\tHELLO, " << admin->getName() << endl;
	printAdminMenu();
	string optionS;
	cout << "\nENTER YOUR OPTION ==> ";
	cin >> optionS;
	int option;
	if (Validation::checkInt(optionS))
	{
		option = stoi(optionS);
	}
	else
	{
		cout << "\t\t\t\tINVALID INPUT\n";
		system("pause");
		return AdminOptions(admin);
	}
	switch (option)
	{
	case 1:
		system("cls");
		Log::log("DISPLAY INFO");
		cout << "ID\t  NAME\t\t\t\tPASSWORD\t\t      BALANCE\n";
		admin->display();
		system("pause");
		AdminOptions(admin);
		break;
	case 2:
		system("cls");
		EmployeeManager::newClient(admin);
		system("pause");
		AdminOptions(admin);
		break;
	case 3:
		system("cls");
		EmployeeManager::searchForClient(admin);
		system("pause");
		AdminOptions(admin);
		break;
	case 4:system("cls");
		EmployeeManager::listAllClients(admin); system("pause");
		AdminOptions(admin);
		break;
	case 5:system("cls");
		EmployeeManager::editClientInfo(admin); system("pause");
		AdminOptions(admin);
		break;
	case 6:system("cls");
		admin->addEmployee(*newEmployee());
		AdminOptions(admin);
		break;
	case 7:system("cls");
		searchEmployee(*admin);
		AdminOptions(admin);
		break;
	case 8:system("cls");
		admin->listEmployee(); system("pause");
		AdminOptions(admin);
		break;
	case 9:system("cls");
		editEmployee(*admin); system("pause");
		AdminOptions(admin);
		break;
	case 10:
		Log::thanks();
		Sleep(2000);
		system("cls");
		Screen::loginOptions();
		break;	
	default:
		cout << "\t\t\t\tINVALID INPUT\n";
		system("pause");
		return AdminOptions(admin);
		break;
	}
	return true;
}

Admin* AdminManager::login(int id, string password) {
	vector<Admin> v = f14.getAllAdmins();
	Admin* admin = new Admin;
	for (int i = 0; i < v.size(); i++) {
		if (id == v[i].getId() && password == v[i].getPassword()) {
			*admin = v[i];
			AdminOptions(admin);
			return admin;
		}
	}
	return nullptr;
}