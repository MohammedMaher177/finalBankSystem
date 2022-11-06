#include "Parser.h"
#include <fstream>
ifstream i2;
vector<string> Parser::split(string line) {
	vector<string> word;
	line += " ";
	string temp = "";
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ' ') {
			word.push_back(temp);
			temp = "";
			i++;
		}
		temp += line[i];
	}
	return word;
}

Client Parser::parseToClient(string line) {
	vector<string> v = split(line);
	Client cl;
	cl.setInfo(v[0], stoi(v[1]), v[2], stod(v[3]));
	return cl;
}
Employee Parser::parseToEmployee(string line) {
	vector<string> v = split(line);
	Employee cl;
	cl.setInfo(v[0], stoi(v[1]), v[2], stod(v[3]));
	return cl;
}
Admin Parser::parseToAdmin(string line) {
	vector<string> v = split(line);
	Admin cl;
	cl.setInfo(v[0], stoi(v[1]), v[2], stod(v[3]));
	return cl;
 }