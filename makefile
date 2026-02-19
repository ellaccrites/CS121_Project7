dataBase: main.o address.o date.o student.o
	g++ -g main.o address.o date.o student.o  -o dataBase

main.o: main.cpp student.h
	g++ -g -c main.cpp

address.o: address.h address.cpp
	g++ -g -c address.cpp

date.o: date.h date.cpp
	g++ -g -c date.cpp

student.o: student.h student.cpp
	g++ -g -c student.cpp

clean:
	rm dataBase main.o address.o date.o student.o

run:
	./dataBase

debug: dataBase
	gdb dataBase

