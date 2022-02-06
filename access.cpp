#include <iostream>

class Obj {
 private:
  int private_member;

 protected:
  int protected_member;

 public:
  int public_member;

  Obj() : private_member(0), protected_member(1), public_member(2) {}
  int get_protected() { return protected_member; }

  friend void ObjFriend(Obj & obj);
};

class ChildObj : Obj {
 public:
  void print() { std::cout << protected_member << std::endl; }
};

void ObjFriend(Obj & obj) {
  obj.protected_member = 10;
}

int main() {
  Obj myobj;
  ObjFriend(myobj);
  std::cout << myobj.get_protected() << std::endl;
  ChildObj c;
  c.print();
}
