CC=g++ -std=c++17

GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include

LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

testList: ListTest.cpp ../List.h
	$(CC) ListTest.cpp -o ListTest $(LD_FLAGS)
	./ListTest

testArray: ArrayTest.cpp ../Array.h
	$(CC) ArrayTest.cpp -o ArrayTest $(LD_FLAGS)
	./ArrayTest

testStack: StackTest.cpp ../Stack.h
	$(CC) StackTest.cpp -o StackTest $(LD_FLAGS)
	./StackTest

testAll:
	./ListTest
	./ArrayTest
	./StackTest

.PHONY: clean
clean:
	rm -rf *.o 