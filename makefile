debug: main.o IndexManager.o mybuffer.o mystr.o
	g++ -g -o debug.out main.o IndexManager.o mybuffer.o mystr.o
main.o: main.cpp
	g++ -g -c main.cpp
IndexManager.o: IndexManager.cpp
	g++ -g -c IndexManager.cpp
mybuffer.o: mybuffer.cpp
	g++ -g -c mybuffer.cpp
mystr.o: mystr.cpp
	g++ -g -c mystr.cpp
clean:
	rm debug.out *.o
