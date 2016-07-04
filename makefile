all: main.o text.o
	g++ main.o text.o -o out
	rm *.o 

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp

text.o: ./src/text.cpp
	g++ -c ./src/text.cpp 