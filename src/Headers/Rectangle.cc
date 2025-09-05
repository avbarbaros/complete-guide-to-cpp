// ============================================================================
// FILE: rectangle.cc
// ============================================================================
#include "Rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(double w, double h) : width(w), height(h) {
    if (w <= 0 || h <= 0) {
        throw std::invalid_argument("Dimensions must be positive");
    }
}

double Rectangle::getArea() const {
    return width * height;
}

double Rectangle::getPerimeter() const {
    return 2 * (width + height);
}

std::string Rectangle::getName() const {
    return isSquare() ? "Square" : "Rectangle";
}

void Rectangle::setDimensions(double w, double h) {
    if (w <= 0 || h <= 0) {
        throw std::invalid_argument("Dimensions must be positive");
    }
    width = w;
    height = h;
}
