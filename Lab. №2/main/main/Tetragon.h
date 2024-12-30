#pragma once
#include "Shape.h"
#include "IntersectionChecker.h"
class Triangle;

class Tetragon : public Shape {
public:
    Tetragon(const std::string& id, double x1, double y1, double x2, double y2,
        double x3, double y3, double x4, double y4);

    void Move(double dx, double dy) override;
    void Show() const override;
    bool IsIntersect(const Shape& other) const override;

    // Добавляем IntersectionChecker как друга
    friend class IntersectionChecker;

protected:
    double x1_, y1_, x2_, y2_, x3_, y3_, x4_, y4_;
};