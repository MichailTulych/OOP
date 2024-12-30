#include "Triangle.h"
#include "Tetragon.h"
#include <iostream>
#include <cmath>

using namespace std;

Triangle::Triangle(const string& id, double x1, double y1, double x2, double y2, double x3, double y3)
    : Shape(id), x1_(x1), y1_(y1), x2_(x2), y2_(y2), x3_(x3), y3_(y3) {
}

void Triangle::Move(double dx, double dy) {
    setlocale(LC_ALL, "Russian");
    x1_ += dx; y1_ += dy;
    x2_ += dx; y2_ += dy;
    x3_ += dx; y3_ += dy;
    cout << "Треугольник перемещен на: (" << dx << ", " << dy << ")\n";
}

void Triangle::Show() const {
    setlocale(LC_ALL, "Russian");
    cout << "Треугольник " << GetID() << " с вершинами: "
        << "(" << x1_ << ", " << y1_ << "), "
        << "(" << x2_ << ", " << y2_ << "), "
        << "(" << x3_ << ", " << y3_ << ")\n";
}

bool Triangle::IsIntersect(const Shape& other) const {
    setlocale(LC_ALL, "Russian");
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    const Tetragon* otherTetragon = dynamic_cast<const Tetragon*>(&other);

    if (otherTriangle) {
        return IntersectionChecker::DoPolygonsIntersect(*this, *otherTriangle);
    }
    else if (otherTetragon) {
        return IntersectionChecker::DoPolygonsIntersect(*this, *otherTetragon);
    }
    else {
        cout << "Пересечение возможно только с другим треугольником или четырехугольником.\n";
        return false;
    }
}