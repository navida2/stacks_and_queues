CXX = g++
CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

all:clean hw4

hw4: src/main.cpp obj/holder.o obj/is_balanced.o
	$(CXX) $(CXXFLAGS) src/main.cpp obj/holder.o obj/is_balanced.o -o bin/hw4

obj/holder.o: src/holder.cpp src/holder.h src/Timer.h
	$(CXX) $(CXXFLAGS) -c src/holder.cpp -o obj/holder.o

clean:
	rm -f obj/*.o bin/hw4
