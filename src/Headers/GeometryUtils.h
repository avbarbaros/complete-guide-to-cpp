// ============================================================================
// FILE: geometry_utils.h - Utility functions working with the interface
// ============================================================================
#ifndef GEOMETRY_UTILS_H
#define GEOMETRY_UTILS_H

#include <vector>
#include <memory>

// Forward declaration is enough here
class Shape;

namespace GeometryUtils {
    // Calculate total area of multiple shapes
    double totalArea(const std::vector<std::unique_ptr<Shape>>& shapes);
    
    // Find shape with largest perimeter
    const Shape* largestPerimeter(const std::vector<std::unique_ptr<Shape>>& shapes);
    
    // Template function must be defined in header
    template<typename T>
    double averageArea(const std::vector<T>& shapes) {
        if (shapes.empty()) return 0.0;
        
        double sum = 0.0;
        for (const auto& shape : shapes) {
            sum += shape->getArea();
        }
        return sum / shapes.size();
    }
}

#endif // GEOMETRY_UTILS_H