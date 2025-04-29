CXX = g++
CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

all:clean hw4

hw4: src/main.cpp obj/unordered_list.o
	$(CXX) $(CXXFLAGS) src/main.cpp obj/unordered_list.o -o bin/hw4

obj/unordered_list.o: src/unordered_list.cpp src/unordered_list.h
	$(CXX) $(CXXFLAGS) -c src/unordered_list.cpp -o obj/unordered_list.o

clean:
	rm -f obj/*.o bin/hw4
