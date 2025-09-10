CXX = g++
CXXFLAGS = -Wall -std=c++11

all: programa

programa: main.o pessoa.o
	$(CXX) $(CXXFLAGS) -o programa main.o pessoa.o

main.o: main.cpp pessoa.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

pessoa.o: pessoa.cpp pessoa.hpp
	$(CXX) $(CXXFLAGS) -c pessoa.cpp

run: programa
	./programa

clean:
	rm -f *.o programa
