CC = g++
TARGET = access static overloading contruct_order rule5 protected dispatch child_permiss abstract dynamic

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
child_permiss:	child_permiss.cpp
	$(CC) -g --std=c++11 $< -o $@
abstract: abstract.cpp
	$(CC) -g --std=c++11 $< -o $@
dynamic: dynamic.cpp
	$(CC) $< -o $@
clean:
	rm $(TARGET)
