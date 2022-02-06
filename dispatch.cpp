#include <iostream>

class Parent {
 public:
  virtual void sayhi() { std::cout << "hi from parent" << std::endl; }

  virtual void sayNo() { std::cout << "no from parent" << std::endl; }
};

class Child : public Parent {
 public:
  virtual void sayhi() { std::cout << "hi from child" << std::endl; }  // for readability

  virtual void sayNo() { std::cout << "no from child" << std::endl; }  // for readability
};

int main() {
  Parent * p = new Child();
  p->sayhi();
  p->sayNo();
}
