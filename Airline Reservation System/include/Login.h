#pragma once
#include<string>
#include <iostream>
#include<vector>
#include <Customer.h>

using namespace std;
class Login
{
public:
 string userType;

public:
	int  loginProcess(string userType, string username, string password,vector<Customer> customerlist);
	bool saveUser(vector<Customer> customerlist);
};

