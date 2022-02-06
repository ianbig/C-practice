#include <iostream>

class abstractClass {
 public:
  virtual void abstractMethod() = 0;
};

class myClass : abstractClass {
 public:
  virtual void abstractMethod() {}
};

int main() {
  myClass a;
}
