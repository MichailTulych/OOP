#pragma once

class IntersectionChecker {
public:
    // �������� ����������� ���� ��������
    static bool DoSegmentsIntersect(double x1, double y1, double x2, double y2,
        double x3, double y3, double x4, double y4);

    // �������� ����������� ���� �������������
    static bool DoPolygonsIntersect(const class Triangle& t1, const class Triangle& t2);

    // �������� ����������� ������������ � ����������������
    static bool DoPolygonsIntersect(const class Triangle& t, const class Tetragon& q);

    // �������� ����������� ���������������� � ������������
    static bool DoPolygonsIntersect(const class Tetragon& q, const class Triangle& t);

    // �������� ����������� ���� �����������������
    static bool DoPolygonsIntersect(const class Tetragon& q1, const class Tetragon& q2);
};