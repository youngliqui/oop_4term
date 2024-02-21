//
// Created by youngliqui on 21.02.2024.
//
#pragma once

#ifndef OOP_4TERM_POINT_H
#define OOP_4TERM_POINT_H

#endif //OOP_4TERM_POINT_H

#include "string"

class Point {
public:
    Point(float x, float y);

    ~Point();

    float getX() const;

    float getY() const;

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;

    std::string toString() const;

private:
    float x, y;
};