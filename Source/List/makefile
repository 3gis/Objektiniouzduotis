main: functions.o
	g++ -o main main.cpp functions.o
unittesting: unittesting.o functions.o
	g++ -o unittesting unittesting.cpp functions.o
functions:
	g++ -c functions.cpp

clean:
	rm *.o main unittesting
