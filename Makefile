CXX = g++

 # compiler flags:
 #  -g    adds debugging information to the executable file
 #  -Wall turns on most, but not all, compiler warnings
CXXFLAGS = -std=c++14 -g -Wall

OBJECTS = Cryptographer.o Node.o UserListGen.o HashTable.o

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

cryptoTest: Tests/cryptoTester.cpp Cryptographer.o
	$(CXX) $(CXXFLAGS) -o $@ $^

nodeTest: Tests/nodeTest.cpp Node.o
	$(CXX) $(CXXFLAGS) -o $@ $^

tableTest: HashTable.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
		$(RM) *.o *.gc* cryptoTest nodeTest 
