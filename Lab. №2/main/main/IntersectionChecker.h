#pragma once

class IntersectionChecker {
public:
    // Проверка пересечения двух отрезков
    static bool DoSegmentsIntersect(double x1, double y1, double x2, double y2,
        double x3, double y3, double x4, double y4);

    // Проверка пересечения двух треугольников
    static bool DoPolygonsIntersect(const class Triangle& t1, const class Triangle& t2);

    // Проверка пересечения треугольника и четырехугольника
    static bool DoPolygonsIntersect(const class Triangle& t, const class Tetragon& q);

    // Проверка пересечения четырехугольника и треугольника
    static bool DoPolygonsIntersect(const class Tetragon& q, const class Triangle& t);

    // Проверка пересечения двух четырехугольников
    static bool DoPolygonsIntersect(const class Tetragon& q1, const class Tetragon& q2);
};