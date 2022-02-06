#include <iostream>

class Shape {
 public:
  virtual double calcArea() = 0;
  virtual ~Shape() {}
};

class Triangle : public Shape {
  double base;
  double height;

 public:
  virtual double calcArea() { return (base * height) / 2; }
  Triangle(double base_t, double height_t) : base(base_t), height(height_t) {}
  virtual ~Triangle() {}
};

class Rectangle : public Shape {
  double width;
  double height;

 public:
  virtual double calcArea() { return width * height; }
  Rectangle(double width_t, double height_t) : width(width_t), height(height_t) {}
  virtual ~Rectangle() {}
};

int main() {
  Shape * rec = new Rectangle(2, 3);
  Shape * tre = new Triangle(2, 3);
  std::cout << "Area of rectangle: " << rec->calcArea() << std::endl;
  std::cout << "Area of triangle: " << tre->calcArea() << std::endl;

  delete rec;
  delete tre;
}
