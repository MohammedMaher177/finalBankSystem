#pragma once
#include <iostream>
using namespace std;
class Screen
{
public:
	static void bankName();
	static void welcome();
	static void loginOptions();
	static int loginAs();
	static void invalid(int c);
	static void loginScreen(int c);
	static void runApp();
};

