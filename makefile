main: v1.5setget.o v1.5fun.o
        g++ -o test v1.5main.cpp v1.5setget.o v1.5fun.o

setget:
        g++ -c v1.5setget.cpp

fun: 
        g++ -c v1.5fun.cpp

clean:
        rm *.o main


