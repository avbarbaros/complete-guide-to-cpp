// ============================================================================
// FILE: shape_factory.cc
// ============================================================================
#include "ShapeFactory.h"
#include "Circle.h"      // Now we need the full definitions
#include "Rectangle.h"
#include <sstream>
#include <stdexcept>

std::unique_ptr<Shape> ShapeFactory::createShape(ShapeType type, double param1, double param2) {
    switch (type) {
        case ShapeType::CIRCLE:
            return std::make_unique<Circle>(param1);
            
        case ShapeType::RECTANGLE:
            return std::make_unique<Rectangle>(param1, param2);
            
        case ShapeType::SQUARE:
            return std::make_unique<Rectangle>(param1, param1);
            
        default:
            throw std::invalid_argument("Unknown shape type");
    }
}

std::unique_ptr<Shape> ShapeFactory::createFromDescription(const std::string& description) {
    std::istringstream iss(description);
    std::string shapeType;
    iss >> shapeType;
    
    if (shapeType == "circle") {
        double radius;
        iss >> radius;
        return std::make_unique<Circle>(radius);
    } 
    else if (shapeType == "rectangle") {
        double width, height;
        iss >> width >> height;
        return std::make_unique<Rectangle>(width, height);
    }
    else {
        throw std::invalid_argument("Unknown shape: " + shapeType);
    }
}
