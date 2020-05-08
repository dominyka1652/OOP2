main: v1.2setget.o v1.2fun.o
        g++ -o test v1.2main.cpp v1.2setget.o v1.2fun.o

setget:
        g++ -c v1.2setget.cpp

fun: 
        g++ -c v1.2fun.cpp

clean:
        rm *.o main


