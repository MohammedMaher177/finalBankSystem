#include "ClientManger.h"
#include "FileManager.h"
#include "Screen.h"
#include "Client.h"
#include<fstream>
#include "Log.h"
#include "EmployeeManager.h"
#include <Windows.h>
void ClientManger::printClientMenu() {
	system("cls");
	system("color 50");
	Log::successfu("LOG IN");
	cout << "\n1. DISPLAY INFORMATION \n\n2. CHECK BALANCE \n\n3. UPDATE MY PASSWORD \n\n4. DEPOSIT AMOUNT \n\n5. WITHDRARW AMOUNT \n\n"
		<< "6. TRANSFER TO ANOTHER ACCOUNT \n\n7. LOG OUT\n\n";
}
string passwordSet()
{
	string password;
	do {
		
		cout << "Enter New Password: ";
		cin >> password;
	} while (!(Validation::checkPassword(password)));
	return password;
}
void ClientManger::updatePassword(Person* p)//me7taga tetrage3
{
	FileManager f;
	Employee e;
	vector<Client> v =f.getAllClients();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getId() == p->getId())
		{
			v[i].setPasswword(passwordSet());
			p->setPasswword(v[i].getPassword());
			e.editClient(v[i].getId(), v[i].getName(), v[i].getPassword(), v[i].getBalance());
			return;
		}	
	}

}
Client* ClientManger::login(int id, string password)
{
	FileManager f;
	vector<Client> v = f.getAllClients();
	Client* cl1 = new Client;
	bool flag = false;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getId() ==id && v[i].getPassword()==password)
		{
			*cl1 = v[i];
			clientOptions(cl1);
			return cl1;
		}
		else {
			flag = true;
		}
	}
	if (flag == true)
	{
		return nullptr;
	}
}

double ClientManger::enterWithdraw(Client* ccc) {
	double amount;
	system("cls");
	Log::log("WITHDRAW");
	cout << "ENTER AMOUNT PLEASE\n\n";
	amount = Validation::checkDouble();
	//cin >> amount;
	if (amount <= 0)
	{
		
		cout << "YOU CAN NOT WITHDRAW NEGATIVE AMOUNT, PLEASE STOP ESTE3BAT\n\n"
			<< "ENTER REAL AMOUNT PLEASE\n\n";
		system("pause");
		withdraw(ccc);
	}
	if (amount > ccc->getBalance())
	{
		cout << "NOT ALLOWED \t\tPLEASE ENTER ANOTHER AMOUNT\n\n"
			<< "YOUR BALANCE: " << ccc->getBalance() << endl << endl;
		system("pause");
		withdraw(ccc);
	}
	if (amount > 0 && amount > ccc->getBalance()) {
		Log::successfu("withdraw");
	}
	return amount;
}
void ClientManger::withdraw(Client* client)
{
	client->withdraw(enterWithdraw(client));
}
double ClientManger::depositting(Client* client)
{
	double amount;
	system("cls");
	Log::log("DEPOSIT");
	cout << "ENTER AMOUNT PLEASE\n\n";
	amount = Validation::checkDouble();
	//cin >> amount;
	if (amount < 0)
	{
		do
		{
			system("cls");
			Log::log("DEPOSIT");
			cout << "YOU CAN NOT DEPOSIT NEGATIVE AMOUNT, PLEASE STOP ESTE3BAT\n\n"
				<< "ENTER REAL AMOUNT PLEASE\n\n";
			amount = Validation::checkDouble();
			//cin >> amount;
		} while (amount < 0);
	}
	if (amount >= 0) {
		return amount;
	}
}
double ClientManger::enterTransfer(Client* ccc) {
	double amount; int id;
	system("cls");
	Employee* employee = new Employee;
	Client* client2 = new Client;
	Log::log("TRANFER");
	do
	{
		cout << "ENTER ACCOUNT ID recipient\n\n";
		id = Validation::checkInt();
		//cin >> id;
		if (id == ccc->getId())
		{
			system("cls");
			Log::log("TRANFER");
			cout << "YOU CAN NOT TRANSFER TO YOUR SELF\n\n";
		}
		else if (employee->searchClient(id) == nullptr)
		{
			system("cls");
			Log::log("TRANFER");
			cout << "ID NOT FOUND\n\n";
		}
	} while (employee->searchClient(id) == nullptr || id == ccc->getId());
	client2 = employee->searchClient(id);
	do
	{
		cout << "ENTER AMOUNT PLEASE\n\n";
		amount = Validation::checkDouble();
		//cin >> amount;
		if (amount > ccc->getBalance())
		{
			system("cls");
			Log::log("TRANFER");
			cout << "NOT ALLOWED \t\tPLEASE ENTER ANOTHER AMOUNT\n\n";
		}
		else if (amount <= 0) {
			system("cls");
			Log::log("TRANFER");
			cout << "YOU CAN NOT TRANSFER NEGATIVE AMOUNT \t\tPLEASE ENTER ANOTHER AMOUNT AND STOP ESTE3BAT\n\n";
		}
	} while (amount > ccc->getBalance() || amount <= 0);
	
	double balance;
	balance = ccc->getBalance() - amount;
	client2->deposit(amount);
	employee->editClient(id, client2->getName(), client2->getPassword(), client2->getBalance());
	Log::successfu("TRANSFER");
	return balance;
}

bool ClientManger::clientOptions(Client* ccc)
{
	Client* client = new Client;
	double res;
	printClientMenu();
	int option, id;
	double amount;
	cin >> option;
	Employee el;
	system("cls");
	switch (option)
	{
	case 1:
		ccc->display();
		system("pause");
		clientOptions(ccc);
		break;
	case 2:
		ccc->checkBalance();
		system("pause");
		clientOptions(ccc);
		break;
	case 3:
		updatePassword(ccc);
		system("pause");
		clientOptions(ccc);
		break;
	case 4:
		ccc->deposit(depositting(ccc));
		el.editClient(ccc->getId(), ccc->getName(), ccc->getPassword(), ccc->getBalance());
		cout << "DEPOSIT SUCCESS\n\n";
		cout << "YOUR NEW BALANCE IS: " << ccc->getBalance() << endl;
		system("pause");
		clientOptions(ccc);
		break;
	case 5:
		withdraw(ccc);
		system("pause");
		clientOptions(ccc);
		break;
	case 6:
		system("cls");
		res = enterTransfer(ccc);
		ccc->setBalance(res);
		el.editClient(ccc->getId(), ccc->getName(), ccc->getPassword(), res);
		system("pause");
		clientOptions(ccc);
		break;
	case 7:
		Log::thanks();
		Sleep(2000);
		Screen::loginOptions();
		break;
	default:
		printClientMenu();
		break;
	}
	return true;
}