# Sprint2_AirlineReservationSystem
Airline Reservation System

Airline Reservation System




Case Summary:

An airline reservation system has been designed and developed to manage the process of customer reservations. In order to make a reservation, the customer must be a member else the customer has to register. After that, the system obtains journey details from the customer. Based on the flight information provided by the customer, the system then determines a suitable flight for the customer. It then finds the availability of seats on the flight. If the seats are available, then the system presents the flight information along with the fares to the customer. The system initiates the process of making a reservation which requires updating the flight status in the database and obtaining payment from the user. Once the database is updated and payment received from the customer, a ticket is issued to the user.
This whole process of reservation can be done only by the administrators of the airline company. Admin/superior user plays a vital role in airline reservation system as only he is allowed to add or delete flights.
 
Functionalities provided to the Customer:
The following functionalities are provided to the customer while booking tickets.

1.	One Way Trip:

The Customer can book tickets for a one way journey. The customer is asked for low-fare flights before proceeding. All the low fare flights are displayed to the customer if he/she chooses low fare flights else regular flights are displayed. After booking a flight the customer can also book accommodation in the hotels nearby.

2.	Round Trip:

The Customer can book tickets for two way journey. The customer can book flights to a destination and can book a return journey from the same destination. After booking a flight the customer can also book accommodation in the hotels nearby.

3.	Package Trip:

The Customer can book tickets for a package trip like honeymoon, pilgrimage, adventure etc. The customer can book a package according to its requirements. Suitable discounts are provided for customers in bulk. Accommodations are provided in the package trip.

4.	Low Fare:

The customer can search for flight details with lowest fare flight detail at starting and thereafter in the ascending order. Customer can also search for flight of specific airlines. Customer can also set a fare limit such that flights with fare below price limit only are displayed.

5.	Accomodation:

Accommodation to the customers is provided in every type of trip based on destination. User can also choose many types of hotels based on short description provided with contact number. Hotel booking is optional i.e. if user does not want accommodation, hotel details will not be provided and the final details will be appended to the final ticket if he choose a particular hotel.
 
Roles of Administrator:
Administrator is responsible for framing the structure of the application and ensuring that application is working at optimal level. Admin details were already available in database. Admin is the one and only superior authority, who can perform all the operations. The major tasks of administrator are as below:

1.	Add/Delete Flights:
Administrator is also responsible for introducing new flights. According to need, he can disable flights as well.
To add new flights, admin will use following information.
•	Flight Id
•	Flight Name
•	Source and Destination
•	Journey date
•	Departure and Arrival Time
•	Number of seats
•	Fares
2.	Modify Flight Details

Administrator can modify flights details.

To modify flights, following details can be modified
•	Flight Name
•	Source and Destination
•	Journey date
•	Departure and Arrival Time
•	Number of seats
•	Fares
 
Roles of Customer:

Customer can book tickets as well as cancel booked tickets.

Book Tickets:

Customer has to give following details for the journey and will book tickets accordingly. Following are various details, Manager will ask to customer while booking tickets.
•	Customer Name
•	Customer Id Proof
•	Source and Destination
•	Journey Date
•	Flight Id
•	Number of tickets
1.	Cancellation:
In order to cancel tickets customer will ask details needed and will cancel tickets. Post cancellation, seats will get available for further bookings. The 20% of ticket fares will be deducted and remaining will return back to the customer.
2.	Status of tickets:
Customer can check status of booked tickets and can give feedback to the customers.
 
Limitations:

•	DATABASE is Limited.
•	Seat avalibility based on dates is not taken into consideration

Out of Scope:

•	Real time transactions are out of scope.

