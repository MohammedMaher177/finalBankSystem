#pragma once
#include "DataSource.h"
class FileManager :
    public DataSource
{
public:
	 void addClient(Client);
	 void addEmployee(Employee);
	 void addAdmin(Admin);
	  vector<Client> getAllClients() ;
	  vector<Employee>getAllEmployees() ;
	  vector<Admin>getAllAdmins() ;
	  void removeAllClients() ;
	  void removeAllEmployees() ;
	  void removeAllAdmins();
};

