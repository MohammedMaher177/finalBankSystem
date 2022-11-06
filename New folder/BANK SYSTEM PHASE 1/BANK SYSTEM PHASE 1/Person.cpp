#include "Person.h"

//constructor
Person::Person() {
	name = " ";
	password = " ";
	id = 0;
}
Person::Person(string name, int id, string password) {
	if (Validation::checkName(name)) {
		this->name = name;
	}
	this->id = id;
	if (Validation::checkPassword(password)) {
		this->password = password;
	}
}
Person::~Person() {}
//setters
void Person::setName(string name) {
	/*if (Validation::checkName(name)) {
		this->name = name;
	}*/
	this->name = name;
}
void Person::setId(int id) {	this->id = id; }
void Person::setPasswword(string password) {
	/*if (Validation::checkPassword(password)) {
		this->password = password;
	}*/
	this->password = password;
}
void Person::setInfo(string name, int id, string password) {
	if (Validation::checkName(name)) {
		this->name = name;
	}
	this->id = id;
	if (Validation::checkPassword(password)) {
		this->password = password;
	}
}

//getters
string Person::getName() { return name; }
int Person::getId() { return id; }
string Person::getPassword() { return password; }
//methods