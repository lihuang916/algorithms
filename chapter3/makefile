all: clean test.o myStack.o
	g++ test.o myStack.o -o test -g
	./test
myStack.o:
	g++ -c myStack.cpp -o myStack.o -g
myQueue.o:
	g++ -c myQueue.cpp -o myQueue.o -g
test.o:
	g++ -c test.cpp -o test.o -g
clean:
	rm -rf *o