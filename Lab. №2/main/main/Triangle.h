#pragma once
#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(const std::string& id, double x1, double y1, double x2, double y2, double x3, double y3);

    void Move(double dx, double dy) override;
    void Show() const override;
    bool IsIntersect(const Shape& other) const override;

protected:
    double x1_, y1_, x2_, y2_, x3_, y3_;

    // Проверка пересечения двух отрезков
    static bool DoSegmentsIntersect(double x1, double y1, double x2, double y2,
        double x3, double y3, double x4, double y4);

    // Дружественные функции для проверки пересечения многоугольников
    friend bool DoPolygonsIntersect(const Triangle& t1, const Triangle& t2);
    friend bool DoPolygonsIntersect(const Triangle& t, const Tetragon& q);
    friend bool DoPolygonsIntersect(const Tetragon& q, const Triangle& t);
};