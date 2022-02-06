#include <iostream>

class MyClass {
 public:
  MyClass(int a) { std::cout << "MyClass(int) is called" << std::endl; }
};

class MyFunction {
 public:
  explicit void dumass_func(MyClass mc) {
    std::cout << "dumacc_func(MyClass) is called" << std::endl;
  }
  // void dumass_func(int c) { std::cout << "dumass_func(int) is called" << std::endl; }
};

int main() {
  MyFunction mf;
  mf.dumass_func(20);  // compile error: conversion from int to MyClass is illegal
}
