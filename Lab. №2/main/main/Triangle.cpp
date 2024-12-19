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
        // Проверяю пересечение с другим треугольником
        return DoPolygonsIntersect(*this, *otherTriangle);
    }
    else if (otherTetragon) {
        // Проверяю пересечение с четырехугольником
        return DoPolygonsIntersect(*this, *otherTetragon);
    }
    else {
        cout << "Пересечение возможно только с другим треугольником или четырехугольником.\n";
        return false;
    }
}

bool Triangle::DoSegmentsIntersect(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4) {
    auto orientation = [](double x1, double y1, double x2, double y2, double x3, double y3) {
        double val = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);
        if (val == 0) return 0;  // Коллинеарность
        return (val > 0) ? 1 : 2; // По часовой или против часовой стрелки
        };

    int o1 = orientation(x1, y1, x2, y2, x3, y3);
    int o2 = orientation(x1, y1, x2, y2, x4, y4);
    int o3 = orientation(x3, y3, x4, y4, x1, y1);
    int o4 = orientation(x3, y3, x4, y4, x2, y2);

    // Общий случай
    if (o1 != o2 && o3 != o4)
        return true;

    return false;
}

// Дружественная функция для проверки пересечения двух треугольников
bool DoPolygonsIntersect(const Triangle& t1, const Triangle& t2) {
    return t1.DoSegmentsIntersect(t1.x1_, t1.y1_, t1.x2_, t1.y2_, t2.x1_, t2.y1_, t2.x2_, t2.y2_) ||
        t1.DoSegmentsIntersect(t1.x1_, t1.y1_, t1.x2_, t1.y2_, t2.x2_, t2.y2_, t2.x3_, t2.y3_) ||
        t1.DoSegmentsIntersect(t1.x1_, t1.y1_, t1.x2_, t1.y2_, t2.x3_, t2.y3_, t2.x1_, t2.y1_) ||
        t1.DoSegmentsIntersect(t1.x2_, t1.y2_, t1.x3_, t1.y3_, t2.x1_, t2.y1_, t2.x2_, t2.y2_) ||
        t1.DoSegmentsIntersect(t1.x2_, t1.y2_, t1.x3_, t1.y3_, t2.x2_, t2.y2_, t2.x3_, t2.y3_) ||
        t1.DoSegmentsIntersect(t1.x2_, t1.y2_, t1.x3_, t1.y3_, t2.x3_, t2.y3_, t2.x1_, t2.y1_) ||
        t1.DoSegmentsIntersect(t1.x3_, t1.y3_, t1.x1_, t1.y1_, t2.x1_, t2.y1_, t2.x2_, t2.y2_) ||
        t1.DoSegmentsIntersect(t1.x3_, t1.y3_, t1.x1_, t1.y1_, t2.x2_, t2.y2_, t2.x3_, t2.y3_) ||
        t1.DoSegmentsIntersect(t1.x3_, t1.y3_, t1.x1_, t1.y1_, t2.x3_, t2.y3_, t2.x1_, t2.y1_);
}

// Дружественная функция для проверки пересечения треугольника и четырехугольника
bool DoPolygonsIntersect(const Triangle& t, const Tetragon& q) {
    return t.DoSegmentsIntersect(t.x1_, t.y1_, t.x2_, t.y2_, q.x1_, q.y1_, q.x2_, q.y2_) ||
        t.DoSegmentsIntersect(t.x1_, t.y1_, t.x2_, t.y2_, q.x2_, q.y2_, q.x3_, q.y3_) ||
        t.DoSegmentsIntersect(t.x1_, t.y1_, t.x2_, t.y2_, q.x3_, q.y3_, q.x4_, q.y4_) ||
        t.DoSegmentsIntersect(t.x1_, t.y1_, t.x2_, t.y2_, q.x4_, q.y4_, q.x1_, q.y1_) ||
        t.DoSegmentsIntersect(t.x2_, t.y2_, t.x3_, t.y3_, q.x1_, q.y1_, q.x2_, q.y2_) ||
        t.DoSegmentsIntersect(t.x2_, t.y2_, t.x3_, t.y3_, q.x2_, q.y2_, q.x3_, q.y3_) ||
        t.DoSegmentsIntersect(t.x2_, t.y2_, t.x3_, t.y3_, q.x3_, q.y3_, q.x4_, q.y4_) ||
        t.DoSegmentsIntersect(t.x2_, t.y2_, t.x3_, t.y3_, q.x4_, q.y4_, q.x1_, q.y1_) ||
        t.DoSegmentsIntersect(t.x3_, t.y3_, t.x1_, t.y1_, q.x1_, q.y1_, q.x2_, q.y2_) ||
        t.DoSegmentsIntersect(t.x3_, t.y3_, t.x1_, t.y1_, q.x2_, q.y2_, q.x3_, q.y3_) ||
        t.DoSegmentsIntersect(t.x3_, t.y3_, t.x1_, t.y1_, q.x3_, q.y3_, q.x4_, q.y4_) ||
        t.DoSegmentsIntersect(t.x3_, t.y3_, t.x1_, t.y1_, q.x4_, q.y4_, q.x1_, q.y1_);
}