CC = g++
CFLAGS = -g  -Wall -std=c++11 -Wextra 

INCLUDES = -I ./

run: AirlineReservationSystem.o Admin.o  BookTickets.o Customer.o Flight.o Login.o 
	${CC} ${CFLAGS} AirlineReservationSystem.o Admin.o  BookTickets.o Customer.o Flight.o Login.o -o run

AirlineReservationSystem.o: AirlineReservationSystem.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c AirlineReservationSystem.cpp

Admin.o: Admin.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c Admin.cpp

BookTickets.o: BookTickets.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c BookTickets.cpp

Customer.o: Customer.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c Customer.cpp

Flight.o: Flight.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c Flight.cpp

Login.o: Login.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c Login.cpp

clean:
	echo "Cleaning....."
	rm *.o run
