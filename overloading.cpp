#include <iostream>

class myClass {
 public:
  int max(int a, int b) { return (a > b) ? a : b; }

  int max(double a, double b) { return (a > b) ? a : b; }

  /**
   * error overloading return type do not count as overloading, only parameter count as
   **/
  // double max(int a, int b) { return (a > b) ? a : b; }
};

int main() {
  myClass mc;
}
