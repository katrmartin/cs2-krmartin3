

CXX = g++

CXXFLAGS = -g -Wall

SRC = stack.cpp stack1.cpp
INCLUDES = Stack.hpp

Stacks: $(SRC) $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(SRC)  -o $@ *.o
	@echo "successfully compiled"

run:Stacks
	./$<

clean:
	rm Stack