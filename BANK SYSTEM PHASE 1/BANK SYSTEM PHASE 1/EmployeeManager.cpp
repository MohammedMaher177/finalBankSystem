#include "EmployeeManager.h"
#include "FilesHelper.h"
#include "ClientManger.h"
#include "Screen.h"
#include "Log.h"
FileManager f;
string EmployeeManager::enterName() {
	string name;
	system("cls");
	Log::log("CREAT NEW ACCOUNT");
	cout << "\nthe name must be alphabetic chars and min size 5 and max size 20\n";
	cout << "ENTER YOUR NAME PLEASE ==> ";
	cin >> name;
	if (Validation::checkName(name)) return name;
	else
	{
		//system("cls");
		cout << "\t\t\t\tINVALID INPUT\nthe name must be alphabetic chars and min size 5 and max size 20\n";
		system("pause");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return enterName();
	}
}
string EmployeeManager::enterPAssword() {
	string password;
	system("cls");
	Log::log("CREAT NEW ACCOUNT");
	cout << "Password must be with min size 8 and max size 20\n";
	cout << "ENTER YOUR PASSWORD PLEASE ==> ";
	cin >> password;
	if (Validation::checkPassword(password)) return password;
	else
	{
		cin.ignore(); cin.clear();
		cout << "\t\t\t\tINVALID INPUT\nPassword must be with min size 8 and max size 20\n";
		system("pause");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return enterPAssword();
	}
}
double EmployeeManager::enterBalance() {
	double balance;
	string balanceS;
	system("cls");
	Log::log("CREAT NEW ACCOUNT");
	cout << "Min balance is 1500\n";
	cout << "ENTER YOUR BALANCE PLEASE ==> ";
	cin >> balanceS;
	if (Validation::checkDouble(balanceS))
	{
		balance = stod(balanceS);
		if(Validation::checkBalance(balance)) return balance;
		else
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\t\t\t\t\tINVALID INPUt\nMin balance is 1500\n\n";
			system("pause");
			return enterBalance();
		}
	}
	else
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\t\t\t\tINVALID INPUT\n";
		system("pause");
		return enterBalance();
	}
}

void EmployeeManager::printEmployeeMenu()
{
	cout << "(1) Display my info" << endl;
	cout << "(2) Update Password" << endl;
	cout << "(3) Add new client" << endl;
	cout << "(4) Search for client" << endl;
	cout << "(5) List all clients" << endl;
	cout << "(6) Edit client info" << endl;
	cout << "(7) Logout\n" << endl;
}
void EmployeeManager::newClient(Employee* employee) {
	system("cls");
	Client* client = new Client();
	client->setName(enterName());
	client->setPasswword(enterPAssword());
	client->setBalance(enterBalance());
	client->setId(FilesHelper::getLast("ClientId.txt"));
	cout << "ID\t  NAME\t\t\t\tPASSWORD\t\t      BALANCE\n";
	client->display();
	employee->addClient(*client);
}

void EmployeeManager::listAllClients(Employee* employee) {
	Log::log("THE CLIENT LIST");
	cout << "ID\t  NAME\t\t\t\tPASSWORD\t\t      BALANCE\n";
	for (int i = 0; i < f.getAllClients().size() - 1; i++) {
		f.getAllClients()[i].display();
	}
	Log::thanks();
}
void EmployeeManager::searchForClient(Employee* employee) {
	bool flag = false;
	string idS;
	int id;
	Client* client = nullptr;
	system("cls");
	Log::log("SEARCHING");
	do
	{
		
		cout << "ENTER ID TO SEARCH \n\n";
		cin >> idS;
		if (Validation::checkInt(idS))
		{
			id = stoi(idS);
		}
		else
		{
			cout << "\t\t\t\tINVALID INPUT\n";
			system("pause");
			return searchForClient(employee);
		}
		client = employee->searchClient(id);
		if (client != nullptr)
		{
			flag = true;
			cout << "ID\t  NAME\t\t\t\tPASSWORD\t\t      BALANCE\n";
			client->display();
			cin.ignore();
		}
		else {
			system("cls");
			cout << "NOT FOUND\t\tPLEAS ENTER CORRECT ID\n\n";
		}
	} while (flag == false);
	cout << "====================================\n";
	cout << "\n1. EDTI DATA\t\t\t\t2. RESEARCH NEW ACCOUNT\t\t\t\t3. MAIN MENU\n";
	string optionS; int option;
	
	do
	{
		do
		{
			cout << "Your option ==> ";
			cin >> optionS;
			if (Validation::checkInt(optionS))
			{
				option = stoi(optionS);
				break;
			}
			else
			{
				cout << "INVALID INPUT\nplease reenter your option\nyour option ==> ";
			}
		} while (true);
		flag = false;
		switch (option)
		{
		case 1:
			getOption(*client);
			break;
		case 2:
			searchForClient(employee);
			break;
		case 3:
			break;
		default:
			cout << "INVALID INPUT\n";
			flag = true;
			system("pause");
			break;
		}
	} while (flag == true);
	system("cls");
}
void EmployeeManager::EditClientData(Employee employee, Client client) {
	vector<Client> v = f.getAllClients();
	for (int i = 0; i < v.size(); i++) {
		if (client.getId() == v[i].getId()) {
			employee.editClient(v[i].getId(), v[i].getName(), v[i].getPassword(), v[i].getBalance());
			break;
		}
	}
}
void EmployeeManager::editClientInfo(Employee* employee) {
	vector<Client> v = f.getAllClients();
	Client client;
	int id; string idS;
	bool flag = false;
	Log::log("EDITTING");
	do
	{
		cout << "ENTER ID: \n\n";
		cin >> idS;
		if (Validation::checkInt(idS))
		{
			id = stoi(idS);
		}
		else
		{
			cout << "\t\t\t\tINVALID INPUT\n";
			system("pause");
			system("cls");
			return editClientInfo(employee);
		}
		for (int i = 0; i < v.size(); i++) {
			if (id ==v[i].getId()) {
				getOption(v[i]);
				employee->editClient(v[i].getId(),v[i].getName(),v[i].getPassword(), v[i].getBalance());
				flag = true;
				break;
			}
		}
		if (flag == false) {
			system("cls");
			cout << "ID NOT FOUND \n\n";
		}
	} while (flag == false);
	cout << "DATA Modified\n\n";
	system("pause");
}

void EmployeeManager::getOption(Client& client) {
	string optionS;
	int option;
	Employee employee;
	system("cls");
	cout << "EDIT PROFILE DATA\n";
	cout << "ID\t  NAME\t\t\t\tPASSWORD\t\t      BALANCE\n";
	client.display();
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
		return getOption(client);
	}
	switch (option)
	{
		
	case 1: client.setName(enterName());
		EditClientData(employee, client);
		cout << "NAME EDITTED";
		system("pause");
		getOption(client);
		break;
	case 2: client.setPasswword(enterPAssword());
		EditClientData(employee, client);
		cout << "PASSWORD EDITTED";
		system("pause");
		getOption(client);
		break;
	case 3: client.setBalance(enterBalance());
		EditClientData(employee, client);
		cout << "BALANCE EDITTED";
		system("pause");
		getOption(client);
		break;
	case 4:
		break;
	default:
		cout << "INVALID INPUT\n";
		system("pause");
		getOption(client);
		break;
	}
}

Employee* EmployeeManager::login(int id, string password) {
	vector <Employee> v = f.getAllEmployees();
	Employee* employee = new Employee;
	bool flag = false;
	for (int i = 0; i < v.size(); i++) {
		if (id == v[i].getId() && password == v[i].getPassword()) {
			*employee = v[i];
			employeeOptions(employee);
			flag = true;
			return employee;
		}
	}
	
	return nullptr;
}

string EmployeeManager::passwordSet()
{
	string password;
	do {

		cout << "Enter New Password: ";
		cin >> password;
	} while (!(Validation::checkPassword(password)));
	return password;
}
void EmployeeManager::updatePassword(Employee* p)//me7taga tetrage3
{
	system("cls");
	Log::log("EDITTING DATA");
	FileManager f;
	Admin e;
	vector<Employee> v = f.getAllEmployees();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getId() == p->getId())
		{
			v[i].setPasswword(passwordSet());
			p->setPasswword(v[i].getPassword());
			e.editEmployee(v[i].getId(), v[i].getName(), v[i].getPassword(), v[i].getSalary());
			cout << "PASSWORD UPDATED\n\n";
			return;
		}
	}

}


bool EmployeeManager::employeeOptions(Employee* employee) {
	system("color 90");
	system("cls");
	Log::successfu("LOG IN");
		printEmployeeMenu();
		int option;
		cin >> option;
		switch (option)
		{
		case 1:
			system("cls");
			employee->display();
			system("pause");
			employeeOptions(employee);
			break;
		case 2:
			EmployeeManager::updatePassword(employee);
			system("pause");
			employeeOptions(employee);
			break;
		case 3:
			newClient(employee);
			system("pause");
			employeeOptions(employee);
			break;
		case 4:
			searchForClient(employee);
			system("pause");
			employeeOptions(employee);
			break;
		case 5:
			system("cls");
			employee->listClient();
			system("pause");
			employeeOptions(employee);
			break;
		case 6:
			editClientInfo(employee);
			system("cls");
			employeeOptions(employee);
			break;
		case 7:
			system("cls");
			Log::thanks();
			system("pause");
			Screen::loginOptions();
			break;
		default:
			system("cls");
			cout << "INCORRECT CHOICE\nPLEASE ENTER THE CORRECT CHOICE\n\n";
			break;
		}
		return true;
}