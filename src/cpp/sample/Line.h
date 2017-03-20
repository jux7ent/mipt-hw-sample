#pragma once

#include "Point.h"

class Line {
public:
    double a, b, c; //коэфф. ур-я ax + by + c = 0
    Line();
    Line(const Point &, const Point &);
    void insert(const Point &, const Point &);
    friend bool intersection(const Line &, const Line &, Point &);
};