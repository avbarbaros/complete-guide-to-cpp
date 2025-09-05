// ============================================================================
// FILE: rectangle.h - Another concrete implementation
// ============================================================================
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double w = 1.0, double h = 1.0);
    
    // Override interface methods
    double getArea() const override;
    double getPerimeter() const override;
    std::string getName() const override;
    
    // Rectangle-specific
    void setDimensions(double w, double h);
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    
    // Special type: Square is a Rectangle
    bool isSquare() const { return width == height; }
};

#endif // RECTANGLE_H