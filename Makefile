CC = g++
TARGET = access static overloading contruct_order rule5

all: $(TARGET)
access:access.cpp
	$(CC) $< -o $@
static:static.cpp
	$(CC) $< -o $@
overloading: overloading.cpp
	$(CC) $< -o $@
contruct_order: contruct_order.cpp	
	$(CC) $< -o $@
rule5: rule5.cpp
	$(CC) -g --std=c++11 $< -o $@

clean:
	rm $(TARGET)
