CC = g++
<<<<<<< HEAD
TARGET = access static overloading contruct_order rule5 explicit
=======
TARGET = access static overloading contruct_order rule5 protected dispatch child_permiss abstract dynamic
>>>>>>> d40e018c657045a981cc2ddda02c75af65a849f3

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
<<<<<<< HEAD
explicit: explicit.cpp
	$(CC) $< -o $@

=======
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
>>>>>>> d40e018c657045a981cc2ddda02c75af65a849f3
clean:
	rm $(TARGET)
