// ============================================================================
// FILE: shape.cc - Implementation of non-pure-virtual functions
// ============================================================================
#include "Shape.h"
#include <iostream>

void Shape::printInfo() const {
    std::cout << "Shape: " << getName() 
              << " | Area: " << getArea() 
              << " | Perimeter: " << getPerimeter() << std::endl;
}