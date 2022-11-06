#include <iostream>
#include <vector>
#include <string>
#include "Client.h"
#include "Admin.h"
#include "DataSource.h"
#include "FileManager.h"
#include "Parser.h"
#include "ClientManger.h"
#include "Screen.h"
#include "FilesHelper.h"
#include "EmployeeManager.h"
#include "AdminManager.h"

using namespace std;




int main()
{
	Screen::runApp();
	Employee e;
	//EmployeeManager::employeeOptions(&e);
	Client c;
	//ClientManger::clientOptions(&c);
}
