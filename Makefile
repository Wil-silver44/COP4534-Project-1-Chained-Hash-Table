CXX = g++

 # compiler flags:
 #  -g    adds debugging information to the executable file
 #  -Wall turns on most, but not all, compiler warnings
CXXFLAGS = -std=c++14 -g -Wall

OBJECTS = Cryptographer.o Node.o UserListGen.o HashTable.o UserBaseSim.o

main: main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

hashTest: Tests/hashTest.cpp HashTable.o Node.o
		$(CXX) $(CXXFLAGS) -o $@ $^

cryptoTest: Tests/cryptoTester.cpp Cryptographer.o
	 $(CXX) $(CXXFLAGS) -o $@ $^

userGenTest: Tests/userGenTest.cpp UserListGen.o Cryptographer.o
	 $(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
		$(RM) *.o *.gc* mainTest raw.txt encrypted.txt hashTest userGenTest cryptoTest main
