#include <iostream>

class IntArr {
  size_t size;
  int * data;
  size_t number_of_element;

 public:
  IntArr(int size_arg) : size(size_arg), data(new int[size]), number_of_element(0) {
    std::cout << "Default Construtor is called" << std::endl;
  }
  // Copy Constructor
  IntArr(const IntArr & rhs);
  // Destructor
  // ~IntArr();
  // Assignment Operator
  IntArr & operator=(const IntArr & rhs);
  // Move Constructor
  // IntArr(IntArr && rhs);
  // Move Assignment
  // IntArr & operator(IntArr && rhs);
  void add(int element);
  // print operator
  friend std::ostream & operator<<(std::ostream & os, IntArr & rhs);
};

void IntArr::add(int element) {
  if (number_of_element >= size) {
    size_t newSize = size * 2;
    IntArr tmp(newSize);
    tmp = *this;  // assignment operator
    std::swap(this->data, tmp.data);
  }

  data[number_of_element] = element;
  number_of_element += 1;
}

IntArr & IntArr::operator=(const IntArr & rhs) {
  std::cout << "Assignment operator is called" << std::endl;
  if (this != &rhs) {
    int * tmp = new int[rhs.size];
    for (int i = 0; i < rhs.size; i++) {
      tmp[i] = rhs.data[i];
    }

    delete[] data;
    data = tmp;
    size = rhs.size;
    number_of_element = rhs.number_of_element;
  }

  return *this;
}

std::ostream & operator<<(std::ostream & os, IntArr & rhs) {
  for (int i = 0; i < rhs.number_of_element; i++) {
    os << rhs.data[i] << ", ";
  }

  return os;
}

int main() {
  IntArr arr(5);
  for (int i = 0; i < 10; i++) {
    arr.add(i);
  }

  std::cout << arr << std::endl;
}
