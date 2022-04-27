CC = g++
CFLAGS = -g  -Wall -std=c++11 -Wextra 

INCLUDES = -I include/

run: AirlineReservationSystem.o Admin.o  BookTickets.o Customer.o Flight.o Login.o 
	${CC} ${CFLAGS} AirlineReservationSystem.o Admin.o  BookTickets.o Customer.o Flight.o Login.o -o run

AirlineReservationSystem.o: AirlineReservationSystem.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c AirlineReservationSystem.cpp

Admin.o: src/Admin.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c src/Admin.cpp

BookTickets.o: src/BookTickets.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c src/BookTickets.cpp

Customer.o: src/Customer.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c src/Customer.cpp

Flight.o: src/Flight.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c src/Flight.cpp

Login.o: src/Login.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c src/Login.cpp

clean:
	echo "Cleaning....."
	rm *.o run
