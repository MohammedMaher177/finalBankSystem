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
	cout << "PASWORD UPDATED\n";
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
	double amount; string amountS;
	system("cls");
	Log::log("WITHDRAW");
	cout << "ENTER AMOUNT PLEASE\n\n";
	cin >> amountS;
	if (Validation::checkDoubles(amountS))
	{
		amount = stod(amountS);
	}
	else
	{
		cout << "INVALID INPUT\n";
		system("pause");
		enterWithdraw(ccc);
	}
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
		system("cls");
		Log::successfu("withdraw");
		cout << "YOUR NEW BALANCE IS =>> " << ccc->getBalance() << endl;
		system("pause");
	}
	return amount;
}
void ClientManger::withdraw(Client* client)
{
	client->withdraw(enterWithdraw(client));
	cout << "YOUR NEW BALANCE IS =>> " << client->getBalance() << endl;
	system("pause");
}
double ClientManger::depositting(Client* client)
{
	double amount; string amountS;
	system("cls");
	Log::log("DEPOSIT");
	cout << "ENTER AMOUNT PLEASE\n\n";
	cin >> amountS;
	if (Validation::checkDouble(amountS))

	{
		amount = stod(amountS);
	}
	else
	{
		cout << "INVALID INPUT\n";
		system("pause");
		depositting(client);
	}
	if (amount <= 0)
	{
		cout << "YOU CAN NOT DEPOSIT NEGATIVE AMOUNT, PLEASE STOP ESTE3BAT\n\n";
		system("pause");
		depositting(client);
	}
	if (amount >= 0) {
		return amount;
	}
}
void ClientManger::enterClientId(Client* client) {
	int id; string idS;
	Employee* employee = new Employee;
	Client* client2 = new Client;
	system("cls");
	Log::log("TRANFER");
	cout << "ENTER ACCOUNT ID recipient\n\n";
	cin >> idS;
	if (Validation::checkInt(idS))
	{
		id = stoi(idS);
	}
	else
	{
		cout << "INVALID INPUT\n";
		system("pause");
		enterClientId(client);
	}
	if (id == client->getId())
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
		system("pause");
		enterClientId(client);
	}
	client2 = employee->searchClient(id);
	enterTransfer(client, client2);
}
double ClientManger::enterTransfer(Client* client1,Client* client2) {
	double amount; string amountS;
	system("cls");
	Employee* employee = new Employee;
	//Client* client2 = new Client;
	Log::log("TRANFER");
	cout << "ENTER AMOUNT PLEASE\n\n";
	cin >> amountS;
	if (Validation::checkDoubles(amountS))
	{
		amount = stod(amountS);
	}
	else
	{
		cout << "INVAALID INPUT\n";
		system("pause");
		return enterTransfer(client1, client2);
	}
	if (amount > client1->getBalance())
	{
		system("cls");
		Log::log("TRANFER");
		cout << "NOT ALLOWED \t\tPLEASE ENTER ANOTHER AMOUNT\n\n";
		system("pause");
		return enterTransfer(client1, client2);
	}
	else if (amount <= 0) {
		system("cls");
		Log::log("TRANFER");
		cout << "YOU CAN NOT TRANSFER NEGATIVE AMOUNT \t\tPLEASE ENTER ANOTHER AMOUNT AND STOP ESTE3BAT\n\n";
		return enterTransfer(client1, client2);
	}	
	double balance;
	balance = client1->getBalance() - amount;
	client2->deposit(amount);
	employee->editClient(client2->getId(), client2->getName(), client2->getPassword(), client2->getBalance());
	Log::successfu("TRANSFER");
	system("pause");
	client1->setBalance(balance);
	employee->editClient(client1->getId(), client1->getName(), client1->getPassword(), balance);
	clientOptions(client1);
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
		
		clientOptions(ccc);
		break;
	case 6:
		system("cls");
		enterClientId(ccc);
		//ccc->setBalance(res);
		//el.editClient(ccc->getId(), ccc->getName(), ccc->getPassword(), res);
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