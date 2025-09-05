// ============================================================================
// FILE: circle.cc - Circle implementation
// ============================================================================
#include "Circle.h"
#include <stdexcept>

// Default constructor
Circle::Circle() : radius(1.0) {
    // Could also write: radius = 1.0; but initialization list is better
}

// Parameterized constructor
Circle::Circle(double r) : radius(r) {
    if (r <= 0) {
        throw std::invalid_argument("Radius must be positive");
    }
}

// Implement pure virtual functions
double Circle::getArea() const {
    return PI * radius * radius;
}

double Circle::getPerimeter() const {
    return 2 * PI * radius;
}

std::string Circle::getName() const {
    return "Circle";
}

// Circle-specific method
void Circle::setRadius(double r) {
    if (r <= 0) {
        throw std::invalid_argument("Radius must be positive");
    }
    radius = r;
}

// Friend function definition
bool operator==(const Circle& c1, const Circle& c2) {
    return c1.radius == c2.radius;
}
