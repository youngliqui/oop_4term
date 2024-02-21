//
// Created by youngliqui on 21.02.2024.
//

#include <sstream>
#include "Point.h"

Point::Point(float x, float y) {
    this->x = x;
    this->y = y;
}

Point::~Point() = default;

float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

std::string Point::toString() const {
    std::stringstream info;
    info << "(" << x << ", " << y << ")";
    return info.str();
}


