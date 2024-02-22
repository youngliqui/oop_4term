//
// Created by youngliqui on 21.02.2024.
//

#include "Line.h"

Line::Line(float a, float b, float c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

Line::~Line() = default;

float Line::getA() const {
    return a;
}

float Line::getB() const {
    return b;
}

float Line::getC() const {
    return c;
}

Point *Line::intersectionWithOX() const {
    float x = -c / a;
    return new Point(x, 0);
}

Point *Line::intersectionWithOY() const {
    float y = -c / b;
    return new Point(0, y);
}

Point *Line::intersectionWithLine(Line &secondLine) const {
    float x = (b * secondLine.getC() - secondLine.getB() * c) / (a * secondLine.getB() - b * secondLine.getA());
    float y = (-secondLine.getC() - secondLine.getA() * x) / secondLine.getB();

    return new Point(x, y);
}

std::ostream &operator<<(std::ostream &os, const Line &line) {
    os << "line:{a: " << line.a << " b: " << line.b << " c: " << line.c << "};";
    return os;
}

bool Line::operator==(const Line &rhs) const {
    return a == rhs.a &&
           b == rhs.b &&
           c == rhs.c;
}

bool Line::operator!=(const Line &rhs) const {
    return !(rhs == *this);
}

Line *Line::operator+(const Line &line) const {
    return new Line(a + line.getA(), b + line.getB(), c + line.getC());
}

Line *Line::operator-(const Line &line) const {
    return new Line(a - line.getA(), b - line.getB(), c - line.getC());
}

Line *Line::operator*(float scalar) const {
    return new Line(a * scalar, b * scalar, c * scalar);
}

Line *Line::operator/(float scalar) const {
    return new Line(a / scalar, b / scalar, c / scalar);
}

