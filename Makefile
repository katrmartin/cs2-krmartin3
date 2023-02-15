

CXX = g++
CXXFLAGS = -g -Wall 
Stacks:stack.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ *.o
	@echo "successfully compiled"

run:Stacks
	./$<

clean:
	rm Stack