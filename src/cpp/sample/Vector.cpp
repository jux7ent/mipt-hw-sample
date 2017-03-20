#include "Vector.h"

Vector plus_minus(const Vector &vec1, const Vector &vec2, bool sign) {
    int factor = (int(sign) * 2) - 1;

    Vector *result = new Vector(vec1.x + factor * vec2.x, vec1.y + factor * vec2.y);

    return *result;
}

Vector operator + (const Vector &vec1, const Vector &vec2) {
    return plus_minus(vec1, vec2, true);
}

Vector operator - (const Vector &vec1, const Vector &vec2) {
    return plus_minus(vec1, vec2, false);
}

double operator * (const Vector &vec1, const Vector &vec2) {
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

std::ostream &operator << (std::ostream &out, const Vector &vec) {
    out << vec.x << ' ' << vec.y;

    return out;
}

Vector::Vector() {
    this->x = this->y = 0;
}

Vector::Vector(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector::Vector(const Point &p1, const Point &p2) {
    this->x = p2.x - p1.x;
    this->y = p2.y - p1.y;
}

double Vector::length() {
    return sqrt(this->x * this->x + this->y * this->y);
}