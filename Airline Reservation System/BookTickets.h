#pragma once
#include<string>
#include "Admin.h"
using namespace std;
class BookTickets
{
public :
	
	    int bookingID;
	    string	customerName;
		string customerIdProof;
		string	source;
		string destination;
		string journeyDate;
		string	flightId;
		string ReturnJourneyDate;
		string package;
		string  hotel;
		bool lowfare;
		float totalfare;

		bool ticketStatus;
		int  numberoftickets;
		BookTickets()
		{
			bookingID = 0;
			ticketStatus = false;
			lowfare = false;
			totalfare = 0.0;
		}

		BookTickets(string	customerName, string customerIdProof, string source ,string destination, string journeyDate, string	flightId, int  nmberoftickets)
		{
			
			this->customerName = customerName;
			this->customerIdProof = customerIdProof;
			this->destination = destination;
			this->source = source;
			this->journeyDate = journeyDate;
			this->flightId = flightId;
			this->numberoftickets = numberoftickets;
		}
		bool bookTicket(vector<BookTickets> list, vector<Flight> flightlist,Admin admin);
		bool cancelTicket(vector<BookTickets> list, int id, Admin admin);
		bool  statusoftickets(vector<BookTickets> list, int id);
		bool checkAvailbilityOfFlight(vector<Flight> flightlist, Admin  admin);
		bool saveBookingDetails(vector<BookTickets> booklist, Admin admin);
		int  findTicket(vector<BookTickets> bookinglist, int fid);

};

