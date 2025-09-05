// ============================================================================
// FILE: shape.h - Abstract interface (base class)
// ============================================================================
#ifndef SHAPE_H
#define SHAPE_H

#include <string>

// Abstract base class (interface in C++ terms)
class Shape {
public:
    // Pure virtual functions make this an abstract class
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual std::string getName() const = 0;
    
    // Virtual destructor is crucial for proper cleanup in polymorphic hierarchies
    virtual ~Shape() = default;
    
    // Non-virtual function that uses the virtual ones
    void printInfo() const;  // Declaration only - definition in shape.cc
};

#endif // SHAPE_H
