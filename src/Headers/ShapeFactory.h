// ============================================================================
// FILE: shape_factory.h - Factory pattern using the interface
// ============================================================================
#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include <memory>
#include <string>

// Forward declarations instead of including headers (when possible)
class Shape;  // We only return Shape*, so forward declaration is enough

// Factory class to create shapes
class ShapeFactory {
public:
    enum class ShapeType {
        CIRCLE,
        RECTANGLE,
        SQUARE
    };
    
    // Static factory method returning smart pointer
    static std::unique_ptr<Shape> createShape(ShapeType type, double param1, double param2 = 0);
    
    // Create from string description
    static std::unique_ptr<Shape> createFromDescription(const std::string& description);
    
private:
    // Private constructor prevents instantiation
    ShapeFactory() = default;
};

#endif // SHAPE_FACTORY_H