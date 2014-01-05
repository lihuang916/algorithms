all: clean test.o myStack.o myQueue.o stacks.o setofstacks.o
	g++ test.o myStack.o myQueue.o stacks.o setofstacks.o -o test -g
	./test
myStack.o:
	g++ -c myStack.cpp -o myStack.o -g
myQueue.o:
	g++ -c myQueue.cpp -o myQueue.o -g
stacks.o:
	g++ -c stacks.cpp -o stacks.o -g
setofstacks.o:
	g++ -c setofstacks.cpp -o setofstacks.o -g
test.o:
	g++ -c test.cpp -o test.o -g
clean:
	rm -rf *o