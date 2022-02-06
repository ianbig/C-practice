#include <stdio.h>

#include "code_w_static.h"

void func() {
  static int a = 0;
  a += 1;
  printf("in func a is %d\n", a);
}

int main() {
  static int a = 10;
  func();
  printf("in main a is %d\n", a);
  func();
  printf("in main a is %d\n", a);
}
