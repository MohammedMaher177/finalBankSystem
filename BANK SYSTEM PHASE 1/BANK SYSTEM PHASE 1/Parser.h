#pragma once
#include <vector>
#include <string>
#include "Client.h"
#include "Admin.h"
using namespace std;
class Parser
{
private:
	static vector<string> split(string line);
public:
	static Client parseToClient(string line);
	static Employee parseToEmployee(string line);
	static Admin parseToAdmin(string line);
};

