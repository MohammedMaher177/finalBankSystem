#pragma once
#include <string>
#include "Person.h"
using namespace std;
class Validation
{
public:
	static bool checkName(string name) {
		bool flag = true;
		
		if (name.size() >= 5 && name.size() <= 20 ) {
			for (int i = 0; i < name.length(); i++) {
				if (!isalpha(name[i])) {
					return false;
				}
			}
		}
		else {
			flag = false;
		}
		return flag;
	}
	static bool checkPassword(string pass) {
		if (pass.size() >= 8 && pass.size() <= 20) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool checkBalance(double balance) {
		if (balance >= 1500) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool checkSalary(double salary) {
		if (salary >= 5000) {
			return true;
		}
		else {
			return false;
		}
	}

	static double checkDouble() {
		string num;
		double op;
		int pointCount = 0;
		bool flag = false, pointFlag = false, alphaFlag = false;
		do
		{
			flag = true;
			pointFlag = false;
			alphaFlag = false;
			pointCount = 0;
			//cout << "enter number\n";
			cin >> num;
			for (int i = 0; i < num.length(); i++) {
				if (num[i] == '.') {
					pointCount++;
				}
				else if (isalpha(num[i])) {
					alphaFlag = true;
				}
			}
			if (pointCount == 0) {
				pointFlag = true;
			}
			else if (pointCount == 1) {
				pointFlag = false;
				for (int i = 0; i < num.length(); i++) {
					if (num[i] == '.' && i != 0 && i != num.length() - 1) {
						pointFlag = true;

					}
				}
			}
			for (int i = 0; i < num.length(); i++) {
				if ((num[i] < 48 || num[i] > 57) && (num[i] != '.') || alphaFlag) {
					flag = false;
				}
			}
			
		} while (flag == false || pointFlag == false);
		op = stod(num);
		return op;
	}

	static int checkInt() {
		string num;
		int op;
		bool flag = false;
		do
		{
			flag = true;
			cout << "enter number\n";
			cin >> num;
			for (int i = 0; i < num.length(); i++) {
				if (num[i] < 48 || num[i] > 57) {
					flag = false;
				}
			}
		} while (flag == false);
		op = stoi(num);
		return op;
	}
	static bool checkInt(string s) {
		int op;
		bool flag = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] < 48 || s[i] > 57) {
				flag = false;
			}
		}
		return flag;
	}

	static bool checkDouble(string num) {
		int pointCount = 0;
		pointCount = 0;
		for (int i = 0; i < num.length(); i++) {
			if (num[i] == '.') {
				pointCount++;
			}
		}
		if (num[0] == '.' || num[num.length() - 1] == '.') return false;
		if (pointCount == 0 || pointCount == 1)
		{
			for (int i = 0; i < num.length(); i++) {
				if ((num[i] < 48 || num[i] > 57) && (num[i] != '.')) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}

	}

};

