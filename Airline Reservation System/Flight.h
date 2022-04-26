#pragma once
#include<string>
#include <iostream>
using namespace std;

class Flight
{
	// flight all data 
public:
	string flightId;
	string flightName;
	string source;
	string  destination;
	string journeydate;
	string  	departure;
	string ArrivalTime;
	int	Number_of_seats;
	float	fares;
	

public:
	Flight()
	{
		


	}
	//construtor to intilize flight object 
	Flight(string FlightId, string flightName, string source, string  destination, string journeydate, string  	departure, string ArrivalTime, int	Number_of_seats, float	fares)
	{
		this->flightId = FlightId;
		this->flightName = flightName;
		this->source = source;
		this->destination = destination;
		this->journeydate = journeydate;
		this->departure = departure;
		this->ArrivalTime = ArrivalTime;
		this->Number_of_seats = Number_of_seats;
		this->fares = fares;
	}

	void print();
};
