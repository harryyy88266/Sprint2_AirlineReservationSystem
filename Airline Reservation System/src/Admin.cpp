#include <Admin.h>
#define FLIGHTDB "./data/flights.txt"

//function to add new flight 
void Admin ::addFlight(vector<Flight> flightlist)
{

	Flight flight;
	cout << "\n\t\tEnter Flight  Details :";
	cout<<"\n\t\tflightId:";
	cin >> flight.flightId;
	cout << "\n\t\tflightName:";
	cin >> flight.flightName;

	cout << "\n\t\tsource:";
	cin >> flight.source;

	cout << "\n\t\tdestination:";
	cin >> flight.destination;

	cout << "\n\t\tjourney Date:";
	cin >> flight.journeydate;

	cout << "\n\t\tdeparture Time :";
	cin >> flight.departure;

	cout << "\n\t\tArrivalTime :";
	cin >> flight.ArrivalTime;
	
	cout << "\n\t\tNumber_of_seats:";
	cin >> flight.Number_of_seats;

	cout << "\n\t\tfares:";
	cin >> flight.fares;
	flightlist.push_back(flight);
	saveFlightInFile(flightlist);
	cout << "\n\n\t\tflight added SuccessFully !!!";


}
//linear search function to find perticular flight 
int  Admin::findFlight(vector<Flight> flightlist,string fid)
{
	for (int i = 0; i < flightlist.size(); i++)
	{
		Flight f=flightlist.at(i);
		if (f.flightId == fid)
			return i;
	}
	return -1;

}
// function save  flight data from vector  to file  
void Admin::saveFlightInFile(vector<Flight> flightlist)
{
	ofstream outdata; // outdata is like cin
	int i = 0;


	outdata.open(FLIGHTDB);
	for (i = 0; i < flightlist.size(); i++)
	{
		Flight flight  = flightlist.at(i);

		outdata << flight.flightId<< " " << flight.flightName << " " << flight.source<<" "<< flight.destination << " " << flight.journeydate << " " << flight.ArrivalTime<< " "  << flight.departure << " " << flight.Number_of_seats <<" " << flight.fares << "\n";

	}
	
}
// fucntion for  modify  flight and save updated  data from vector to file(database)
void Admin:: modifyFlightDetails(vector<Flight> flightlist)
{
	int ch;
	string id;
	int result;
	Flight flight;
	do {


		cout << "\n\t\tEnter  flightId to modify :";
		cin >> id;
		result = findFlight(flightlist, id);
		
		if (result == -1)
			cout << "\n\t\tFlight id not found please Enter Correct Flight ID";
	

		if (result != -1)
		{
			 flight = flightlist.at(result);
			cout << "\n\t\tchoose field of flight which want modify ";
			cout << "\n\n\t\t1. Flight Name\n\t\t2. Source\n\t\t3. Destination\n\t\t4. Journey date\n\t\t5. Departure \n\t\t 6. Arrival Time \n\t\t7. Number of seats\n\t\t8. Fares";
			cout << "\n\t\t Enter the choice";
			cin >> ch;
			switch (ch)
			{
			case 1:

				cout << "\n\t\tEnter new Flight Name:";
				cin >> flight.flightName;
				break;
			case 2:

				cout << "\n\t\tEnter new Flight Source:";
				cin >> flight.flightName;
				break;
			case 3:

				cout << "\n\t\tEnter new Flight Destination:";
				cin >> flight.destination;
				break;
			case 4:

				cout << "\n\t\tEnter new Flight  Journey date:";
				cin >> flight.journeydate;
				break;
			case 5:

				cout << "\n\t\tEnter new Flight  Departure time:";
				cin >> flight.departure;
				break;
			case 6:

				cout << "\n\t\tEnter new Flight  Arrival Time:";
				cin >> flight.ArrivalTime;
				break;
			case 7:

				cout << "\n\t\tEnter new Flight  Number of seats:";
				cin >> flight.Number_of_seats;
				break;
			case 8:
				cout << "\n\t\t Enter new Flight  Fares:";
				cin >> flight.fares;
				break;
			case 9:
				exit(0);
				break;
			}
		}
	} while (result == -1);
	flightlist.erase(flightlist.begin() + result);
	flightlist.push_back(flight);
	//PrintVec(flightlist);
	saveFlightInFile(flightlist); //save data to file 
	cout << "\n\n\t\tflight Modified  SuccessFully !!!";
} 



// fucntion for  delete flight from vector and save data from vector to file(database)
void Admin:: deleteFlight(vector<Flight> flightlist)
{
	string id;
	int result;
	do {
		cout << "\n\n \t\t Enter  flightId to delete Flight :";
		cin >> id;
		result = findFlight(flightlist, id);

		if (result == -1)
			cout << "\n\t\tFlight id not found please Enter Correct Flight ID";
		
	} while (result == -1);
	
	 flightlist.erase(flightlist.begin() + result);
	// PrintVec(flightlist);
	 saveFlightInFile(flightlist);
	 cout << "\n\n\t\tflight deleted   SuccessFully !!!";
	
}
bool Admin::isValidId(string  id)
{// todo 

	return true;
}
