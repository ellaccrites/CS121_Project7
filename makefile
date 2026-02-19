dataBase: main.o address.o
	g++ -g main.o address.o -o dataBase

main.o: main.cpp address.h
	g++ - g -c main.cpp

address.o: address.h address.cpp
	g++ -g -c horse.cpp

clean: rm dataBase main.o address.o

run:
	./dataBase

debug: dataBase
	gdb horseRace

