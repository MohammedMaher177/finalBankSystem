#include "FilesHelper.h"
#include "FileManager.h"
#include <fstream>
ofstream ofl;
ifstream ifl;
FileManager f3;
void FilesHelper::saveLast(string fileName, int id) {
	ofl.open(fileName,ios::out);
	ofl << id;
	ofl.close();
}
int FilesHelper::getLast(string fileName) {
	int id = 1;
	ifl.open(fileName, ios::in);
	if (ifl.eof()) {
		ifl.close();
		ofl.open(fileName, ios::out);
		ofl << id;
		ofl.close();
		int x = id + 1;
		saveLast(fileName, x);
	}
	else {
		ifl >> id;
		int x = id + 1;
		saveLast(fileName, x);
		ifl.close();
	}
	return id;
}
void FilesHelper::saveClient(Client c) {
	f3.addClient(c);
}
void FilesHelper::saveEmployee(string fileName, string lastIdFile, Employee e){//me7taga tetrage3
	int id;
	ifl.open(lastIdFile, ios::in);
	ifl >> id;
	ifl.close();
	id += 1;
	e.setId(id);
	ofl.open(fileName, ios::app);
	ofl << e.getName() << " " << e.getId() << " "
		<< e.getPassword() << " " << e.getSalary() << endl;
	ofl.close();
}
void FilesHelper::getClients() {
	for (int i = 0; i < f3.getAllClients().size(); i++)
	{
		f3.getAllClients()[i].display();
	}
}
void FilesHelper::getEmployees() {
	for (int i = 0; i < f3.getAllEmployees().size(); i++)
	{
		f3.getAllEmployees()[i].display();
	}
}
void FilesHelper::getAdmins() {
	for (int i = 0; i < f3.getAllAdmins().size(); i++)
	{
		f3.getAllAdmins()[i].display();
	}
}
void FilesHelper::clearFile(string fileName, string lastIdFile) {
	ifl.open(fileName, ios::out | ios::trunc);
	ifl.close();
	ofl.open(lastIdFile, ios::out | ios::trunc);
	ofl.close();
}