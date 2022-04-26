#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Flight.h"
using namespace std;

class Admin
{
public:
	 string  uname; 
	 string password;
public:
	
	     void addFlight(vector<Flight> flightlist);

		 void modifyFlightDetails(vector<Flight> flightlist);
	
		 void deleteFlight(vector<Flight> flightlist);
	 
		 bool isValidId(string  id);
		 void saveFlightInFile(vector<Flight> flightlist);
		void  PrintVec(vector<Flight> flightlistt);
		int  findFlight(vector<Flight> flightlist, string fid);
		
};



