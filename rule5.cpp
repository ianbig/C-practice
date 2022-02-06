#include <iostream>
#include <vector>

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
  ~IntArr();
  // Assignment Operator
  IntArr & operator=(const IntArr & rhs);
  // Move Constructor
  IntArr(IntArr && rhs);
  // Move Assignment
  IntArr & operator=(IntArr && rhs);
  void add(int element);
  // print operator
  friend std::ostream & operator<<(std::ostream & os, IntArr & rhs);
  void doNothing(IntArr rhs) {}
};

IntArr & IntArr::operator=(IntArr && rhs) {
  std::cout << "Move assignment operator is called" << std::endl;
  if (this != &rhs) {
    std::swap(data, rhs.data);
    std::swap(number_of_element, rhs.number_of_element);
    std::swap(size, rhs.size);
  }

  return *this;
}

void IntArr::add(int element) {
  if (number_of_element >= size) {
    size_t newSize = size * 2;
    IntArr tmp(newSize);
    for (int i = 0; i < this->size; i++) {
      tmp.data[i] = data[i];
    }
    this->size = tmp.size;
    std::swap(this->data, tmp.data);
  }

  data[number_of_element] = element;
  number_of_element += 1;
}

IntArr::~IntArr() {
  std::cout << "Destructor is called" << std::endl;
  delete[] data;
}

IntArr::IntArr(const IntArr & rhs) :
    size(rhs.size), data(new int[rhs.size]), number_of_element(rhs.number_of_element) {
  std::cout << "Copy Constructor is called" << std::endl;
  for (int i = 0; i < rhs.size; i++) {
    data[i] = rhs.data[i];
  }
}

IntArr::IntArr(IntArr && rhs) {
  std::cout << "Move Constructor is called" << std::endl;
  std::swap(data, rhs.data);
  std::swap(number_of_element, rhs.number_of_element);
  std::swap(size, rhs.size);
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
  for (int i = 0; i < 5; i++) {
    arr.add(i);
  }

  std::cout << arr << std::endl;

  std::cout << "======= create new arr2 =======" << std::endl;
  IntArr arr2 = arr;
  std::cout << arr2 << std::endl;
  arr2.add(6);
  arr2.add(7);

  std::cout << "======== new arr3 =========" << std::endl;
  IntArr arr3(4);
  std::cout << arr3 << std::endl;
  arr3 = arr2;
  std::cout << arr3 << std::endl;

  std::cout << "===== test out move operator====" << std::endl;
  std::vector<IntArr> vec;
  vec.push_back(IntArr(10));
  arr3 = IntArr(20);
}
