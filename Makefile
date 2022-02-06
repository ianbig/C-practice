CC = g++
TARGET = access static overloading contruct_order rule5 protected dispatch

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
protected: protected.cpp
	$(CC) -g --std=c++11 $< -o $@
dispatch: dispatch.cpp
	$(CC) -g --std=c++11 $< -o $@

clean:
	rm $(TARGET)
