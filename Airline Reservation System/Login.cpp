#pragma once
#include <Login.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;
// function for Parse file data line by line 
vector<string> split(const string& s, char delim)
{
	vector<string> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
	{
		result.push_back(item);
	}

	return result;
}
//function  for  save user  in file 
bool Login::saveUser(vector<Customer> customerlist)
{
	ofstream outdata; // outdata is like cin
	int i=0;


	outdata.open("customers.txt");
	for( i=0;i< customerlist.size(); i++)
	{ 
		Customer c= customerlist.at(i);
		
		outdata<<c.getName()<<" " << c.getUname()<<" "<<c.getPassword()<<"\n";

	}

	return (i-1)==(int)customerlist.size();


}


//this function to check admin / custmer authorization
int Login::loginProcess(string userType,string username,string password, vector<Customer> customerlist)
{
	
	string myText;

	
	if (userType == "admin")
	{
		//admin 
		ifstream MyReadFile("admin.txt");



		while (getline(MyReadFile, myText))
		{

			string space_delimiter = " ";
			vector<string> words{};

			words=split(myText, ' ');

		
			if (words.at(0) == username && words.at(1) == password)
				return true;
		}
		MyReadFile.close();
		return false;
	}

	if (userType == "customer")
	{
		// customer validation 
		int uch=0;
		string name;
		string uname;
		string password;
		do {
			do {
				cout << "\n\n\t\t1. Customer Registration \n\t\t2. Login Customer(already Member)\n\t\t3.Cancel";

				cin.clear();
				cout << "\n\n\t\tEnter Choice:";
				cin >> uch;
				if (uch != 1 && uch != 2 && uch != 3)
					cout << "\n\n\t\t Invalid choice !!try again ..";

			} while (uch != 1 && uch != 2 && uch != 3);

			if (uch == 1)
			{
				// customer will add login details 
				cout << "\n\t\tEnter Customer details:";
				cout << "\n\t\tName:";
				cin >> name;
				cout << "\n\t\tusername:";
				cin >> uname;
				cout << "\n\t\tpassword:";
				cin >> password;
				Customer newCustomer(name, uname, password);
				customerlist.push_back(newCustomer);
				saveUser(customerlist);
				cout << "\n\t\tUser registration is Successfully Completed !!!";

			}
			if (uch == 2)
			{ 
				try {     

					cout << "\n\t\tusername:"; //exception will occur when customer user name is empty 
					cin >> username;
					if (username == "")
					{
						throw username;

					}
				}
				catch (string  username) {
					cout << "Exception Caught....unamme is empty   \n";
				}



				
				cout << "\n\t\tpassword:";
				cin >> password;

				ifstream MyReadFile("customers.txt");

				while (getline(MyReadFile, myText))
				{

					string space_delimiter = " ";
					vector<string> words{};

					words = split(myText, ' ');


					if (words.at(1) == username && words.at(2) == password)
						return true;
				}
				MyReadFile.close();
				return false;
			}
			if (uch == 3)
			{
				
				return 2;
			}
		} while (uch != 3);
	}
	return false;
}