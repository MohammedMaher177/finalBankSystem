#pragma once
#include "Employee.h"
class ClientManger
{
public:
	static void printClientMenu();
	static void updatePassword(Person* person);
	static Client* login(int id, string password);
	static bool clientOptions(Client* client);
	static double enterWithdraw(Client* client);
	static double enterTransfer(Client* client);
	static double depositting(Client* client);
	static void withdraw(Client* client);
};

