all: clear test.o
	g++ test.o -o test -g 
	./test
#myList.o:  
#	g++ -c myList.cpp -o myList.o -std=c++11 -g -Wall
test.o:
	g++ -c test.cpp -o test.o -std=c++11 -g
clear:
	rm -rf *o
