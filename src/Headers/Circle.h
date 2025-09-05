// ============================================================================
// FILE: circle.h - Concrete class declaration
// ============================================================================
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"  // Need full definition because we're inheriting

// Forward declaration example (not needed here, but showing the concept)
class Point;  // If we only used Point*, we could forward declare

class Circle : public Shape {
private:
    double radius;
    static constexpr double PI = 3.14159265359;  // Static member in header is OK
    
public:
    // Constructors
    Circle();  // Default constructor
    explicit Circle(double r);  // Explicit to prevent implicit conversions
    
    // Copy constructor and assignment operator
    Circle(const Circle& other) = default;  // Let compiler generate
    Circle& operator=(const Circle& other) = default;
    
    // Override virtual functions from Shape
    double getArea() const override;
    double getPerimeter() const override;
    std::string getName() const override;
    
    // Circle-specific methods
    void setRadius(double r);
    double getRadius() const { return radius; }  // Inline definition in header
    
    // Static method - can be called without an object
    static double calculateArea(double radius);
    
    // Friend function declaration (defined elsewhere)
    friend bool operator==(const Circle& c1, const Circle& c2);
};

// Inline function definition (must be in header if used across files)
inline double Circle::calculateArea(double radius) {
    return PI * radius * radius;
}

#endif // CIRCLE_H