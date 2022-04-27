#include<vector>
#include<string>
#include<iostream>
#include <Flight.h>
#include <Admin.h>
#include <Login.h>
#include<limits>
#include<string>
#include<iostream>
#define MAX_NAME_LEN 60
#include <Customer.h>
#include <BookTickets.h>

using namespace std;
class AirlineReservationSystem
{
public:
	// function used to seprate data from file by line by line and return set of string 
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
};

vector<Customer> customerlist;
vector<Flight> flightlist;
vector<BookTickets> bookingRecord;



// load flights.txt data to vector 
vector<Flight > readFileData(AirlineReservationSystem system)
{
	flightlist.clear();

	ifstream MyReadFile("flights.txt");
	string myText;

	while (getline(MyReadFile, myText))
	{

		string space_delimiter = " ";
		vector<string> words{};

		words = system.split(myText, ' ');
		int seatno;
		float fares;

		stringstream sseat(words[7]);
		sseat >> seatno;

		stringstream sfare(words[8]);
		sfare >> fares;

		Flight f(words[0], words[1], words[2], words[3], words[4], words[5], words[6], seatno, fares);
		flightlist.push_back(f);

	}
	MyReadFile.close();
	return flightlist;
}


// load bookingRecord.txt data to vector 
vector<BookTickets > readTicketBookingFileData(AirlineReservationSystem system)
{
	bookingRecord.clear();

	ifstream MyReadFile("bookingRecord.txt");
	string myText;

	while (getline(MyReadFile, myText))
	{

		BookTickets ticket;
		string space_delimiter = " ";
		vector<string> words{};

		words = system.split(myText, ' ');
		int idno;
		int seatno;
		float fares;
		bool tstatus;

		stringstream sid(words[0]);
		sid >> idno;
		stringstream sstatus(words[12]);
		sstatus >> tstatus;
		stringstream sseat(words[8]);
		sseat >> seatno;

		stringstream sfare(words[11]);
		sfare >> fares;

		
		ticket.bookingID = idno;
	     ticket.flightId= words[1];
		 ticket.customerName= words[2];
		 ticket.customerIdProof=words[3];
		 ticket.source= words[4];
		 ticket.destination= words[5];
		 ticket.journeyDate= words[6];
		 ticket.ReturnJourneyDate= words[7];
		 ticket.numberoftickets= seatno;
		 ticket.package= words[9]; 
		 ticket.hotel= words[10];
		 ticket.totalfare = fares;
		 ticket.ticketStatus = tstatus;
		

		 bookingRecord.push_back(ticket);

	}
	MyReadFile.close();
	return bookingRecord;
}



int main()
{

	Login login;
	Admin admin;
	AirlineReservationSystem system;
	int ch;
	string uname, password;
	do
	{
	cout << "\n\t\t*****WELCOME to AIRLINE RESERVATION  SYSTEM *****";
	cout << "\n\n\t\t Choose User  type: \n\t\t1.Admin\n\t\t2.Customer\n\t\t3.exit\n\t\tEnter Chocie:";
	cin >> ch;
	int result=-1;
	
	if (ch == 1)
	{
		// admin tasks   login followed by list of activity like add ,edit ,delete flight 
		int choice;
		do
		{
			try {
			
				cout << "\n\t\tUser Name:"; // exception will be occur when username is empty 
				cin >> uname;
				if (uname=="")
				{
					throw uname;
					
				}
			}
			catch (string  uname ) {
				cout << "Exception Caught....unamme is empty   \n";
			}

			//cout << "\n\t\tUser Name:";
			//cin >> uname;

			cout << "\n\t\tPassword:";
			cin >> password;
			result = login.loginProcess("admin", uname, password, customerlist);
			if (result == false)
				cout << "\n\t\t Please Enter Valid Admin User name and password and try again ";
		} while (result == false);

		cout << "\n\t\tAdmin Login SuccessFul !!!";

		do
		{

			cout << "\n\n\t\t **** Welcome to Admin Dashboad **  !!!!";

			cout << "\n\n\t\t1. Add flight\n\t\t2. delete Flight\n\t\t3. Modify Flight\n\t\t 4. exit";
			cout << "\n\t\tEnter your choice:";
			cin >> choice;

			switch (choice)
			{
			case 1:
				// admin task 1 : add flight 
				flightlist = readFileData(system); // load flight record to vector 
				admin.addFlight(flightlist);

				break;
			case 2:
				// admin task 2 : delete  flight 
				flightlist = readFileData(system); //load flight record to vector
				admin.deleteFlight(flightlist);
				break;
			case 3:
				// admin task 2 : edit flight 
				flightlist = readFileData(system);// load flight record to vector 
				admin.modifyFlightDetails(flightlist);
				break;

			}
		} while (choice != 4);

		cout << "\n\t\t Thank you !!!";

		//admin task    
	}
	else if (ch == 2)
	{

		//customer task like login and list of task book flight,cance ,check status  
		cout << "\n\n\t\t **** Customer Login  ***!!!";
		int choice;
	
			uname = "";

			password = "";
			result = login.loginProcess("customer", uname, password, customerlist);//login process 
			if (result == false)
			{
				cout << "\n\t\tPlease Enter Valid customer User name and password and try again ";
				result = login.loginProcess("customer", uname, password, customerlist);
			}
			if (result == 2)
			{
				cout << "\n\t\t Customer Login cancelled";
			}

			if (result == true)
			{
				// if  customer login successful then allow to do task  
				cout << "\n\t\tCustomer  Login SuccessFul !!!";
				do
				{
					cout << "\n\n\t\t **** Welcome to Customer Dashboad  ***!!!";
					bookingRecord = readTicketBookingFileData(system); //load booking record to vector 
					flightlist = readFileData(system);////load flight  record to vector 
					cout << "\n\n\t\t Booking data loadded=" << bookingRecord.size();
					cout << "\n\t\t1. Book Flight Ticket \n\t\t2. check Status of Flight\n\t\t3. cancel the Fight Ticket\n\t\t4. exit ";
					cout << "\n\n\t\tEnter Choice :";
					char name[100] = { 0 };
					cin >> choice;
					BookTickets ticket;
					string str;
					int no = 0;
					int bid = 0;
					bool result;
					switch (choice)
					{
						//task 1 of customer book flight 
					case 1:
						int tripType;
						ticket.bookingID = bookingRecord.size() + 1;

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t\tEnter following details  of Customer:";

						cout << "\n\t\tFullName:";
						getline(cin, ticket.customerName);



						cout << "\n\t\tCustomer Id Proof Num:";
						getline(cin, ticket.customerIdProof);

						cout << "\n\t\tSource:";
						getline(cin, ticket.source);

						cout << "\n\t\tDestination:";
						getline(cin, ticket.destination);

						cout << "\n\t\tJourney Date:";
						getline(cin, ticket.journeyDate);


						cout << "\n\t\tFlight Id:";
						getline(cin, ticket.flightId);

						cout << "\n\t\tno_of_ticket:";
						cin >> ticket.numberoftickets;



						ticket.bookTicket(bookingRecord, flightlist, admin);






						break;
					case 2:
						//task 2 of customer  to check status of   flight 
						cout << "\n\t\tEnter Ticket Booking ID:";
						cin >> bid;
						result = ticket.statusoftickets(bookingRecord, bid);

						if (result == true)
							cout << "\n\t\tTicket  confirmed !!";
						else
							cout << "\n\t\tTicket Booking Failed  !!";
						break;

					case 3:
						//task 3 of customer  to cancel the    flight
						cout << "\n\t\tEnter Ticket Booking ID:";

						cin >> no;
						if (ticket.cancelTicket(bookingRecord, no, admin) == false)
							cout << "\n\t\t Such booking ID not exits ...";
						break;

					}
					if (choice > 4 || choice < 1)
						cout << "\n\n\t\t Please enter valid choice   and try again !!!";

				} while (choice != 4);
			}//c login
	}




}while (ch != 3);
}