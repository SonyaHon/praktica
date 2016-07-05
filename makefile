all: main.o text.o ca.o
	g++ main.o text.o ca.o -std=c++11 -o out
	rm *.o 

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp

text.o: ./src/text.cpp
	g++ -c ./src/text.cpp 

ca.o: ./src/clusterAnaliz.cpp
	g++ -c ./src/clusterAnaliz.cpp -o ca.o