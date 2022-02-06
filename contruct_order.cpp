#include <iostream>

class MyClass {
  static int id;

 public:
  MyClass() {
    std::cout << "Id " << id << "is created" << std::endl;
    id += 1;
  }

  ~MyClass() {
    std::cout << "Id " << id << "is destructed" << std::endl;
    id -= 1;
  }
};

int MyClass::id = 0;

int main() {
  /*
  MyClass * ptr = new MyClass[5];
  delete[] ptr;
  */

  MyClass arr[3];
}
