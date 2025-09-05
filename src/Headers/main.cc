// ============================================================================
// FILE: main.cc - Using all the components together
// ============================================================================
#include <iostream>
#include <vector>
#include <memory>

// Include what you use - be explicit
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeFactory.h"
#include "GeometryUtils.h"

void demonstratePolymorphism() {
    std::cout << "\n=== POLYMORPHISM DEMO ===" << std::endl;
    
    // Create shapes using the interface pointer
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Rectangle>(3.0, 3.0));  // Square
    
    // Polymorphic behavior - calling virtual functions
    for (const auto& shape : shapes) {
        shape->printInfo();  // Calls the correct override
    }
}

void demonstrateFactory() {
    std::cout << "\n=== FACTORY PATTERN DEMO ===" << std::endl;
    
    // Using factory to create shapes
    auto circle = ShapeFactory::createShape(ShapeFactory::ShapeType::CIRCLE, 7.0);
    auto rect = ShapeFactory::createShape(ShapeFactory::ShapeType::RECTANGLE, 5.0, 10.0);
    auto square = ShapeFactory::createShape(ShapeFactory::ShapeType::SQUARE, 4.0);
    
    circle->printInfo();
    rect->printInfo();
    square->printInfo();
    
    // Create from string
    auto shape1 = ShapeFactory::createFromDescription("circle 3.5");
    auto shape2 = ShapeFactory::createFromDescription("rectangle 2.0 8.0");
    
    std::cout << "\nShapes from descriptions:" << std::endl;
    shape1->printInfo();
    shape2->printInfo();
}

void demonstrateUtilities() {
    std::cout << "\n=== UTILITIES DEMO ===" << std::endl;
    
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(3.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 5.0));
    shapes.push_back(std::make_unique<Circle>(6.0));
    shapes.push_back(std::make_unique<Rectangle>(10.0, 10.0));
    
    double total = GeometryUtils::totalArea(shapes);
    std::cout << "Total area of all shapes: " << total << std::endl;
    
    const Shape* largest = GeometryUtils::largestPerimeter(shapes);
    if (largest) {
        std::cout << "Shape with largest perimeter: ";
        largest->printInfo();
    }
    
    // Using template function
    double avg = GeometryUtils::averageArea(shapes);
    std::cout << "Average area: " << avg << std::endl;
}

void demonstrateConcreteClassUsage() {
    std::cout << "\n=== CONCRETE CLASS USAGE ===" << std::endl;
    
    // Using Circle directly (not through interface)
    Circle c1(5.0);
    Circle c2(5.0);
    Circle c3(7.0);
    
    std::cout << "Circle radius: " << c1.getRadius() << std::endl;
    std::cout << "Static method: Area of radius 10 = " 
              << Circle::calculateArea(10) << std::endl;
    
    // Using friend function
    if (c1 == c2) {
        std::cout << "c1 and c2 are equal" << std::endl;
    }
    if (!(c1 == c3)) {
        std::cout << "c1 and c3 are not equal" << std::endl;
    }
    
    // Using Rectangle-specific features
    Rectangle r1(5.0, 5.0);
    std::cout << "Rectangle is square? " << (r1.isSquare() ? "Yes" : "No") << std::endl;
}

int main() {
    std::cout << "=====================================" << std::endl;
    std::cout << "  MULTI-FILE C++ PROJECT STRUCTURE  " << std::endl;
    std::cout << "=====================================" << std::endl;
    
    try {
        demonstratePolymorphism();
        demonstrateFactory();
        demonstrateUtilities();
        demonstrateConcreteClassUsage();
        
        // Example of error handling
        std::cout << "\n=== ERROR HANDLING ===" << std::endl;
        try {
            Circle bad_circle(-5.0);  // This will throw
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    std::cout << "\n=====================================" << std::endl;
    std::cout << "         DEMO COMPLETE!              " << std::endl;
    std::cout << "=====================================" << std::endl;
    
    return 0;
}



// ============================================================================
// FILE: CMakeLists.txt - Build configuration (for reference)
// ============================================================================
/*
cmake_minimum_required(VERSION 3.10)
project(ShapeProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# List all source files
set(SOURCES
    main.cc
    shape.cc
    circle.cc
    rectangle.cc
    shape_factory.cc
    geometry_utils.cc
)

# Create executable
add_executable(shapes ${SOURCES})

# Include directories (if headers are in separate folder)
# target_include_directories(shapes PRIVATE include)
*/