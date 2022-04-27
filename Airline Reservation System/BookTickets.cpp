#include <BookTickets.h>

//function  to find perticular ticket in  vector of booking records 
int  BookTickets::findTicket(vector<BookTickets> bookinglist, int fid)
{
	for (int i = 0; i < bookinglist.size(); i++)
	{
		BookTickets t = bookinglist.at(i);
		if (t.bookingID == fid)
			return i;
	}
	return -1;
}
//function  to cancel ticket  
bool  BookTickets::cancelTicket(vector<BookTickets> list, int id,Admin admin)
{

	
	int result= findTicket(list, id);
	if (result != -1)
	{
		BookTickets ticket = list.at(result);
		ticket.ticketStatus= false;
		list.erase(list.begin() + result);
		list.push_back(ticket);
		//PrintVec(flightlist);
		saveBookingDetails(list,admin);
		cout << "\n\n\t\tBooking Cancelled Successfully !!!";
		return true;
	}
	return false;


}

	//function for check status of ticket 
   bool BookTickets::statusoftickets(vector<BookTickets> list,int id)
{
	   for (int i = 0; i < list.size(); i++)
	   {

		   BookTickets ticket = list.at(i);
		   if (id == ticket.bookingID)
			   return ticket.ticketStatus;
	   }
	   cout << "\n\t\t Booking ID Not Exits ...";
	return false;

}
   
 // function that seact availability 
bool BookTickets:: checkAvailbilityOfFlight(vector<Flight> flightlist, Admin  admin)
{
	cout << "\n\t\t checking  seats Availability .......\n";


	for (int i = 0; i < flightlist.size(); i++)
	{
		
		Flight flight = flightlist.at(i);
		

		if (flight.source == this->source && flight.flightId == this->flightId && flight.destination == this->destination && (flight.Number_of_seats > this->numberoftickets))
		{
			
			cout << "\n\t\t Flight seats Available ..\n";
			cout << "\n\n\t\tFlight ID:-" << flight.flightId << "\tSource:-" << flight.source << "\tDestination:-" << flight.destination;
			flight.Number_of_seats -= this->numberoftickets;
			int result = admin.findFlight(flightlist, flight.flightId);
			flightlist.erase(flightlist.begin() + result);
			flightlist.push_back(flight);

			admin.saveFlightInFile(flightlist);
			this->totalfare = this->totalfare+ (flight.fares*this->numberoftickets);
			return true;
		}

	}
	cout << "\n\t\t Flight seats NOT Available ......\n";
	return false;
}

// save data from vetor to file(database)
bool BookTickets::saveBookingDetails(vector<BookTickets> booklist,  Admin admin)
{
	ofstream outdata; // outdata is like cin
	int i = 0;

	outdata.open("bookingRecord.txt");
	for (i = 0; i < booklist.size(); i++)
	{
		BookTickets ticket = booklist.at(i);

		outdata << ticket.bookingID<< " " << ticket.flightId << " " <<ticket.customerName << " " << ticket.customerIdProof << " " << ticket.source
			<< " " << ticket.destination << " " << ticket.journeyDate<< " " <<ticket.ReturnJourneyDate << " " << ticket.numberoftickets <<" "<<ticket.package
			<<" "<<ticket.hotel<<" "<<ticket.totalfare<<" "<<ticket.ticketStatus<<"\n";

	}

return true;

}
//fucntion to book ticket 
bool BookTickets :: bookTicket(vector<BookTickets> list, vector<Flight> flightlist,Admin admin)
{

	int tripType;
	do
	{
		do
		{
			//futures menu 
			cout << "\n\t\t choose follwing option";
			cout << " \n\n\t\t1. One Way Trip \n\t\t2. Round Trip:\n\t\t3. Package Trip \n\t\t4. Low Fare:\n\t\t5. Accomodation:\n\t\t6. done\n\t\t Enter  choice :";
			cin >> tripType;
			if (tripType < 1 || tripType>6)
				cout << "\n\\t\tEnter Correct Choice:";
		} while (tripType < 1 || tripType>6);


		switch (tripType)
		{
		case 1:
			break;
		case 2:
			cout << "\n\t\tEnter Return Journey Date:";
			cin >> this->ReturnJourneyDate;
			break;

		case 3:
			int pch;
			do
			{ //package list 
				cout << "\n\t\tSeletc Package\n\t\t1.honeymoon(75000)\n\t\t2.pilgrimage(100000)\n\t\t3.adventure(150000) ";
				cout << "Enter choice:";
				cin >> pch;


			} while (pch != 1 && pch != 2 && pch != 3);
			if (pch == 1)
			{
				this->package = "honeymoon";
				this->totalfare += 75000;
			}
			if (pch == 1)
			{
				this->package = "pilgrimage";
				this->totalfare += 100000;
			}
			if (pch == 3)
			{
				this->package = "adventure";
				this->totalfare += 150000;
			}break;

		case 4:
			this->lowfare = true;
			break;

		case 5:
			int hch;
			do {
				// Hotel list 
				cout << "\n\n\t\tSelect Hotel \n\n\t\1.Hotel_1\tcontact-1234567890\n\t\t2.Hotel_2\tcontact-09087654321\n\t\t3.Hotel_3 contact-09587654321";
				cout << "\n\n\t\tEnter Choice:";
				cin >> hch;
			} while (hch != 1 && hch != 2 && hch != 3);

			if (hch == 1)
				this->totalfare += 5000;
			if (hch == 2)
				this->totalfare += 10000;
			if (hch == 3)
				this->totalfare += 15000;
			break;
		}//type
	} while (tripType != 6);//do while


	bool result = checkAvailbilityOfFlight(flightlist,admin);
	this->ticketStatus = result;
	list.push_back(*this);
	saveBookingDetails(list, admin);
	
	if (result == true)
	{
		cout << "\n\t\tTicket BookingID:-" << this->bookingID;
		cout << "\n\n\t\tFlight Ticket booking Successfull !!";
	}
	else
	{
		cout << "\n\t\tTicket BookingID:-" << this->bookingID;
		cout << "\n\t\tFlight Ticket booking booking Failed !!";
	}
	return result;
}