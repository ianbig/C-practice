#include <stdio.h>
#include <stdlib.h>

struct Shape {
  void * vtable;
};

struct Triangle {
  void * vtable;
  double base;
  double height;
};

struct Rectangle {
  void * vtable;
  double width;
  double height;
};

typedef struct Shape Shape;
typedef struct Triangle Triangle;
typedef struct Rectangle Rectangle;
typedef double (**tri_calc)(Triangle *);

double calcArea_Triangle(Triangle * this) {
  return (this->base * this->height) / 2;
}

double getHeight(Triangle * this) {
  return this->height;
}

double getBase(Triangle * this) {
  return this->base;
}

double (*tri[])(Triangle *) = {calcArea_Triangle, getHeight, getBase};

void init_triangle_obj(Triangle * this, int height_t, int base_t) {
  this->vtable = tri;
  this->base = base_t;
  this->height = height_t;
}

// void init_rectangle_obj()

int main() {
  Shape * shape = malloc(sizeof(Triangle));
  init_triangle_obj((Triangle *)shape, 4, 5);
  tri_calc funcs = ((tri_calc)(shape->vtable));
  double area = (*funcs)((Triangle *)(shape));
  double height = (*(funcs + 1))((Triangle *)shape);
  double base = (*(funcs + 2))((Triangle *)shape);
  printf("Triangle Area is %f, height %f, base %f\n", area, height, base);
}
