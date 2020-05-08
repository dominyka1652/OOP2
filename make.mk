main: Source.o setget.o
	g++ -o test main.cpp Source.o setget.o
Source:
	g++ -c Source.cpp
setget:
	g++ -c setget.cpp
clean: 
	rm *.o main