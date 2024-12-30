#include "Tetragon.h"
#include "Triangle.h"
#include <iostream>

using namespace std;

Tetragon::Tetragon(const string& id, double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
    : Shape(id), x1_(x1), y1_(y1), x2_(x2), y2_(y2), x3_(x3), y3_(y3), x4_(x4), y4_(y4) {
}

void Tetragon::Move(double dx, double dy) {
    setlocale(LC_ALL, "Russian");
    x1_ += dx; y1_ += dy;
    x2_ += dx; y2_ += dy;
    x3_ += dx; y3_ += dy;
    x4_ += dx; y4_ += dy;
    cout << "Четырехугольник перемещен на: (" << dx << ", " << dy << ")\n";
}

void Tetragon::Show() const {
    setlocale(LC_ALL, "Russian");
    cout << "Четырехугольник " << GetID() << " с вершинами: "
        << "(" << x1_ << ", " << y1_ << "), "
        << "(" << x2_ << ", " << y2_ << "), "
        << "(" << x3_ << ", " << y3_ << "), "
        << "(" << x4_ << ", " << y4_ << ")\n";
}

bool Tetragon::IsIntersect(const Shape& other) const {
    setlocale(LC_ALL, "Russian");
    const Tetragon* otherTetragon = dynamic_cast<const Tetragon*>(&other);
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);

    if (otherTetragon) {
        return IntersectionChecker::DoPolygonsIntersect(*this, *otherTetragon);
    }
    else if (otherTriangle) {
        return IntersectionChecker::DoPolygonsIntersect(*this, *otherTriangle);
    }
    else {
        cout << "Пересечение возможно только с другим четырехугольником или треугольником.\n";
        return false;
    }
}