#pragma once
#include <Flight.h>
#include<string>
#include <iostream>
using namespace std;
class PackageOfferedFlight :public Flight
{
	string package;
	int price;

	string getPackage();
	void  setPackage(string p);
	int  getPrice();
	void  setPrice(int price);

	
    

};

