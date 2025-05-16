#pragma once
#include "Vortex.h"
#include <memory>
#include <vector>

class Organizer {
public:
    std::vector<std::shared_ptr<Shape::BaseShape>> shapes;

    void addShape(Shape::BaseShape* shape) {
        shapes.push_back(std::shared_ptr<Shape::BaseShape>(shape));
    }
};
