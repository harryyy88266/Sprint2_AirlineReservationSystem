#pragma once
#include<string>
#include<iostream>
using namespace std;
class Customer
{
public:
	string name;
	string uname;
	string password;
public:
	Customer(string name, string uname, string password)
	{
		this->name = name;
		this->uname = uname;
		this->password = password;
	}
	string getName()
	{
		return this->name;

	}
	string getUname()
	{
		return this->uname;

	}
	string getPassword()
	{
		return this->password;

	}
	void print();

};

