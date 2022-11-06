#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Validation.h"
using namespace std;
class Person
{
protected:
	string name, password;
	int id;
public:
	//constructor
	Person();
	Person(string name, int id, string password);
	~Person();
	//setters
	void setName(string nane);
	void setId(int id);
	void setPasswword(string password);
	void setInfo(string name, int id, string password);

	//getters
	string getName();
	int getId();
	string getPassword();
	//methods
};

