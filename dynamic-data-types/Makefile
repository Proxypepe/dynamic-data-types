CC=g++ -std=c++17
TARGET=dynamic_data_types
OBJS=dynamic_data_types.o

compile: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

dynamic_data_types.o: dynamic_data_types.cpp  List.h
	$(CC) -c dynamic_data_types.cpp

.PHONY: clean
clean:
	rm -rf *.o  dynamic_data_types

.PHONY: run
run:
	./dynamic_data_types
