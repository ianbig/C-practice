// TODO: complete this
#include <iostream>
#include <vector>

template<typename T, template<typename, typename> class Container>
class MyClass {
  Container<T> container;
};

int main() {
  MyClass<int, std::vector> mc;
}
