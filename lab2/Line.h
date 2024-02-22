//
// Created by youngliqui on 21.02.2024.
//
#pragma once

#include <ostream>
#include "Point.h"

#ifndef OOP_4TERM_LINE_H
#define OOP_4TERM_LINE_H

#endif //OOP_4TERM_LINE_H


class Line {
public:
    Line(float a, float b, float c);

    ~Line();

    float getA() const;

    float getB() const;

    float getC() const;

    Point *intersectionWithOX() const;

    Point *intersectionWithOY() const;

    Point *intersectionWithLine(Line &secondLine) const;

    friend std::ostream &operator<<(std::ostream &os, const Line &line);

    bool operator==(const Line &rhs) const;

    bool operator!=(const Line &rhs) const;

    Line *operator+(const Line &line) const;

    Line *operator-(const Line &line) const;

    Line *operator/(float scalar) const;

    Line *operator*(float scalar) const;

private:
    float a, b, c;
};