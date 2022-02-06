#include <iostream>

class Parent {
 protected:
  int a;
};

class Child : public Parent {
  void child_func() { a = 10; }  // derived class can access proeceted member
};

class GrandChild : public Child {
  void grandChild_func() {
    a = 20;
  }  // derived of derived class can access protected member
};

int main() {
  GrandChild gc;
  // gc.a = 10;  // cannot access
}
