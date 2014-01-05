all: clean myStack.o hanoi.o
#	g++ test.o myStack.o myQueue.o stacks.o setofstacks.o -o test -g
	g++ hanoi.o myStack.o -o hanoi -g
	./hanoi
hanoi.o:
	g++ -c hanoi.cpp -o hanoi.o -g
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