// ============================================================================
// FILE: geometry_utils.cc
// ============================================================================
#include "GeometryUtils.h"
#include "Shape.h"  // Now we need the full definition

namespace GeometryUtils {
    
double totalArea(const std::vector<std::unique_ptr<Shape>>& shapes) {
    double total = 0.0;
    for (const auto& shape : shapes) {
        if (shape) {  // Check if pointer is valid
            total += shape->getArea();
        }
    }
    return total;
}

const Shape* largestPerimeter(const std::vector<std::unique_ptr<Shape>>& shapes) {
    if (shapes.empty()) return nullptr;
    
    const Shape* largest = nullptr;
    double maxPerimeter = 0.0;
    
    for (const auto& shape : shapes) {
        if (shape && shape->getPerimeter() > maxPerimeter) {
            maxPerimeter = shape->getPerimeter();
            largest = shape.get();
        }
    }
    
    return largest;
}

} // namespace GeometryUtils