#include "Screen.h"
#include "ClientManger.h"
#include <Windows.h>
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "Log.h"
#include <limits>
#include <limits.h>
#include <cmath>
#include <iostream>
#include <ios>
using namespace std;
void Screen::bankName() {
	system("cls");
	system("color 81");
	cout << "\n\n\n\n\n"
		<< "\t\t\t\t\t***********    ********   ************\n";
	Sleep(1000);
	cout << "\t\t\t\t\t*                 **      *           \n";
		Sleep(1000);
		cout << "\t\t\t\t\t*                 **      *           \n";
		Sleep(1000);
		cout<< "\t\t\t\t\t************      **      ************\n";
		Sleep(1000);
		cout<< "\t\t\t\t\t           *      **                 *\n";
		Sleep(1000);
		cout<< "\t\t\t\t\t           *      **                 *\n";
		Sleep(1000);
		cout<< "\t\t\t\t\t           *      **                 *\n";
		Sleep(1000);
		cout<< "\t\t\t\t\t************   ********   ************\n\n";
	Sleep(2000);
	cout << "\t\t\t\t\t********       **      ****       **  **   **\n"
		<< "\t\t\t\t\t*       *     ** **    ** **      **  **  **\n"
		<< "\t\t\t\t\t*        *   **   **   **  **     **  ** **\n"
		<< "\t\t\t\t\t*********   **     **  **   **    **  ****\n"
		<< "\t\t\t\t\t*        *  *********  **    **   **  ** **\n"
		<< "\t\t\t\t\t*         * **     **  **     **  **  **  **\n"
		<< "\t\t\t\t\t*         * **     **  **      ** **  **   **\n"
		<< "\t\t\t\t\t**********  **     **  **       ****  **    **\n\n";
	Sleep(5000);
}
void Screen::welcome() {
	system("cls");
	system("color 9f");
	cout << "\n\n\n\n\n\n\n\n";
	cout << "**            ****            **  **************  **            **************  ************** ****            ****\n"
		<< " **          **  **          **   **              **            **              *            * ** **          ** **\n"
		<< "  **        **    **        **    **              **            **              *            * **  **        **  **\n"
		<< "   **      **      **      **     ************    **            **              *            * **   **      **   **\n"
		<< "    **    **        **    **	  **              **            **              *            * **    **    **    **\n"
		<< "     **  **          **  **       **              **            **              *            * **     **  **     **\n"
		<< "      ****            ****        *************** ************* **************  ************** **      ****      **\n";
	Sleep(2000);
	system("cls");
}
void Screen::loginOptions()
{	
	system("cls");
	system("color 81");
	cout << "LOG IN AS: \n\n";
	cout << "1. ADMIN\n\n"
		<< "2. EMPLOYEE\n\n"
		<< "3. CLIENT\n\n"
		<< "4. EXITE\n\n";
	loginAs();
}
int Screen::loginAs()
{
	int option = 0;
	string s;
	cout << "--> ";
	
	
	cin >> s;
	if (Validation::checkInt(s)) {
		option = stoi(s);
	}
	else {
		cout << "INVALID INPUT\n";
		system("pause");
		loginOptions();
	}
		
	
	if (option == 1 || option == 2 || option == 3) {
		loginScreen(option);
	}
	else if (option == 4) {
		system("pause");
		exit(0);
	}
	else {
		cout << "WRONG CHOICE\n\nPLEASE TRY AGAINE\n";
		system("pause");
		loginOptions();
	}
	
	return option;
}
void Screen::loginScreen(int c)
{
	int id; string password, idS;
	system("cls");
	Log::log("SIGN IN");
	cout << "ENTER YOUR ID PLEASE\n\n";
	cin >> idS;
	if (Validation::checkInt(idS))
	{
		id = stoi(idS);
	}
	else
	{
		cout << "INVALID INPUT\n";
		system("pause");
		loginScreen(c);
	}
	cout << "EENTER YOUR PASSWORD PLEASE\n\n";
	cin >> password;
	switch (c)
	{
	case 1:
		if (AdminManager::login(id, password) == nullptr) 
		{
			system("cls");
			return invalid(c);
		}
		AdminManager::login(id, password);
		break;
	case 2:
		if (EmployeeManager::login(id, password) == nullptr)
		{
			system("cls");
			return invalid(c);
		}
		EmployeeManager::login(id, password);
		break;
	case 3:
		if (ClientManger::login(id, password) == nullptr)
		{
			system("cls");
			return invalid(c);
		}
		ClientManger::login(id,password);
		break;
	
	default:
		system("cls");
		cout << "INVALID INPUT\n";
		system("pause");
		loginOptions();
			break;
	}
}
void Screen::invalid(int c)
{
	cout << "\t\t\t\t\tINVALID LOG N\n\n";
	system("pause");
	loginOptions();
}

void Screen::runApp() {
	//bankName();
	//welcome();
	loginOptions();
}