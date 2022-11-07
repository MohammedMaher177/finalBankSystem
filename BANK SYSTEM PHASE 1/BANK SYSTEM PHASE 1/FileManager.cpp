#include "FileManager.h"
#include <fstream>
ifstream ii;
ofstream oo;
void FileManager::addClient(Client c) {
	oo.open("Client.txt", ios::app);
	oo << c.getName() << " " << c.getId() << " " << c.getPassword() << " " << c.getBalance() << endl;
	oo.close();
}

void FileManager::addEmployee(Employee c) {
	oo.open("Employee.txt", ios::app);
	oo << c.getName() << " " << c.getId() << " " << c.getPassword() << " " << c.getSalary() << endl;
	oo.close();
}

void FileManager::addAdmin(Admin c) {
	oo.open("Admin.txt", ios::app);
	oo << c.getName() << " " << c.getId() << " " << c.getPassword() << " " << c.getSalary() << endl;
	oo.close();
}

vector<Client> FileManager::getAllClients() {
	vector<Client> v;
	Client* cl = new Client;
	ii.open("Client.txt", ios::in);
	string a, c;
	int b;
	double d;
	while (!ii.eof())
	{
		ii >> a >> b >> c >> d;
		cl->setInfo(a, b, c, d);
		v.push_back(*cl);
	}
	ii.close();
	return v;
}

vector<Employee> FileManager::getAllEmployees() {
	vector<Employee> v;
	Employee* cl = new Employee;
	ii.open("Employee.txt", ios::in);
	string a, c;
	int b;
	double d;
	while (!ii.eof())
	{
		ii >> a >> b >> c >> d;
		cl->setInfo(a, b, c, d);
		v.push_back(*cl);
	}
	ii.close();
	return v;
}
vector<Admin> FileManager::getAllAdmins() {
	vector<Admin> v;
	Admin* cl = new Admin;
	ii.open("Admin.txt", ios::in);
	string a, c;
	int b;
	double d;
	while (!ii.eof())
	{
		ii >> a >> b >> c >> d;
		Admin aa(a, b, c, d);
		cl = &aa;
		v.push_back(*cl);
	}
	ii.close();
	return v;
}

void FileManager::removeAllClients() {
	remove("Client.txt");
	oo.open("Client.txt", ios::out);
	oo.close();
}

void FileManager::removeAllEmployees() {
	remove("Employee.txt");
	oo.open("Employee.txt", ios::out);
	oo.close();
}
void FileManager::removeAllAdmins() {
	remove("Admin.txt");
	oo.open("Admin.txt", ios::out);
	oo.close();
}