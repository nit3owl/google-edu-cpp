CC= g++
CFLAGS= -g -std=c++11
INC= -I include/
all: Database

Database: DatabaseTest.o Composer.o Database.o
	$(CC) $(CFLAGS) $(INC) Database.o Composer.o DatabaseTest.o -o Database

DatabaseTest.o: DatabaseTest.cpp
	$(CC) $(CFLAGS) $(INC) -c DatabaseTest.cpp

Database.o: Database.cpp
	$(CC) $(CFLAGS) $(INC) -c Database.cpp

Composer.o: Composer.cpp
	$(CC) $(CFLAGS) $(INC) -c Composer.cpp

clean:
	rm *.o DatabaseTest