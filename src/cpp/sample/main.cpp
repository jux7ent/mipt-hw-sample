#include <iostream>
#include <cmath>
#include "Vector.h"
#include "Line.h"

//взято из Point.cpp
bool between_points(const Point &p1, const Point &p2, const Point &p3) {
    if (((p3.y - p1.y) * (p2.x - p1.x)) == ((p3.x - p1.x) * (p2.y - p1.y))) { //принадлежность точки прямой
        Vector vec1(p3, p1), vec2(p3, p2);
        return vec1 * vec2 <= 0;
    }

    return false;
}

using std::cout;
using std::cin;
using std::endl;

class BaseShape {
public:
    virtual void shift(const Vector &) = 0;
    virtual bool check_point(double, double) = 0;
    virtual bool intersect_segment(double, double, double, double) = 0;
};

/////////////////////////////

class Polygon : public BaseShape {
protected:
    const static unsigned int count_points = 4;
    Point points[count_points];
public:
    Polygon();
    //   Polygon(const Point *);
    void shift(const Vector &);
    bool check_point(double, double);
    bool intersect_segment(double, double, double, double);
};

void Polygon::shift(const Vector &vector) {
    for (short i = 0; i < count_points; ++i) {
        this->points[i].x += vector.x;
        this->points[i].y += vector.y;
    }
}

Polygon::Polygon() {
    /* for (short i = 0; i < count_points; ++i)     {
         this->points[i] = 0;
     } */
}
/*
Polygon::Polygon(const Point *points) {
    for (short i = 0; i < count_points; ++i) {
        this->points[i] = points[i];
    }
} */

bool Polygon::check_point(double x, double y) {
    //  return (x > this->points[2].x || x < this->points[1].x || y > this->points[1].y || y < this->points[0].y);
    Point p1(x, y), p2(x + 1, y);
    Line line(p1, p2);
    unsigned int count_intersect = 0;
    Line lines[count_points];
    Point intersect_point;

    for (short i = 0; i < count_points; ++i) { //проверка границ
        if (between_points(this->points[i % count_points], this->points[(i + 1) % count_points], p1))
            return true;
    }

    for (short i = 0; i < count_points; ++i) {
        lines[i].insert(this->points[i % count_points], this->points[(i + 1) % count_points]);
        if (intersection(line, lines[i], intersect_point)) { //если прямые пересекаются
            if (!intersect_point.is_none) {
                if (intersect_point.x >= p1.x && between_points(this->points[i % count_points], this->points[(i + 1) % count_points], intersect_point)) {
                    ++count_intersect;
                }
            }
        }
    }

    return count_intersect % 2 != 0;
}

bool Polygon::intersect_segment(double x1, double y1, double x2, double y2) {
    Point p1(x1, y1), p2(x2, y2);
    Line line(p1, p2);
    Line lines[count_points];
    Point intersect_point;

    for (short i = 0; i < count_points; ++i) {
        lines[i].insert(this->points[i % count_points], this->points[(i + 1) % count_points]);
        if (intersection(line, lines[i], intersect_point)) { //если прямые пересекаются
            if (between_points(this->points[i % count_points], this->points[(i + 1) % count_points], intersect_point)) { //если true, то точка лежит на стороне
                if (between_points(p1, p2, intersect_point)) { //если точка лежит на отрезке
                    return true;
                }
            }
        }
    }

    return false;
}

//////////////////////////////////////////////////////

class Rectangle : public Polygon {
protected:
    const static unsigned int count_points = 4;
public:
    Rectangle();
    Rectangle(const Point *);
};

Rectangle::Rectangle() {
    for (short i = 0; i < count_points; ++i) {
        this->points[i] = 0;
    }
}

Rectangle::Rectangle(const Point *points) {
    for (short i = 0; i < count_points; ++i) {
        this->points[i] = points[i];
    }
}
///////////////////////////////////////////////////////


int main() {

}