#include <iostream>

class MyClass {
 private:
  static int static_member;
  int non_static_member;

 public:
  MyClass() : non_static_member(0) {}

  static void static_method() {
    static_member += 10;
    std::cout << "calling static member " << static_member << std::endl;
    // non_static_member += 10;
  }

  void non_static_method() {
    static_member += 10;
    std::cout << "calling static function " << static_member << std::endl;
    non_static_member += 10;
    std::cout << "calling non static function " << non_static_member << std::endl;
  }
};

int MyClass::static_member = -1;

int main() {
  MyClass mc;
  mc.static_method();
  mc.non_static_method();
  // MyClass.static_method();
  MyClass mc2;
  mc2.static_method();
  mc2.non_static_method();
}
