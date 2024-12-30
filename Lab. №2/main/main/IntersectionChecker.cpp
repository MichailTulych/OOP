#include "IntersectionChecker.h"
#include "Triangle.h"
#include "Tetragon.h"

bool IntersectionChecker::DoSegmentsIntersect(double x1, double y1, double x2, double y2,
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

bool IntersectionChecker::DoPolygonsIntersect(const Triangle& t1, const Triangle& t2) {
    return DoSegmentsIntersect(t1.x1_, t1.y1_, t1.x2_, t1.y2_, t2.x1_, t2.y1_, t2.x2_, t2.y2_) ||
        DoSegmentsIntersect(t1.x1_, t1.y1_, t1.x2_, t1.y2_, t2.x2_, t2.y2_, t2.x3_, t2.y3_) ||
        DoSegmentsIntersect(t1.x1_, t1.y1_, t1.x2_, t1.y2_, t2.x3_, t2.y3_, t2.x1_, t2.y1_) ||
        DoSegmentsIntersect(t1.x2_, t1.y2_, t1.x3_, t1.y3_, t2.x1_, t2.y1_, t2.x2_, t2.y2_) ||
        DoSegmentsIntersect(t1.x2_, t1.y2_, t1.x3_, t1.y3_, t2.x2_, t2.y2_, t2.x3_, t2.y3_) ||
        DoSegmentsIntersect(t1.x2_, t1.y2_, t1.x3_, t1.y3_, t2.x3_, t2.y3_, t2.x1_, t2.y1_) ||
        DoSegmentsIntersect(t1.x3_, t1.y3_, t1.x1_, t1.y1_, t2.x1_, t2.y1_, t2.x2_, t2.y2_) ||
        DoSegmentsIntersect(t1.x3_, t1.y3_, t1.x1_, t1.y1_, t2.x2_, t2.y2_, t2.x3_, t2.y3_) ||
        DoSegmentsIntersect(t1.x3_, t1.y3_, t1.x1_, t1.y1_, t2.x3_, t2.y3_, t2.x1_, t2.y1_);
}

bool IntersectionChecker::DoPolygonsIntersect(const Triangle& t, const Tetragon& q) {
    return DoSegmentsIntersect(t.x1_, t.y1_, t.x2_, t.y2_, q.x1_, q.y1_, q.x2_, q.y2_) ||
        DoSegmentsIntersect(t.x1_, t.y1_, t.x2_, t.y2_, q.x2_, q.y2_, q.x3_, q.y3_) ||
        DoSegmentsIntersect(t.x1_, t.y1_, t.x2_, t.y2_, q.x3_, q.y3_, q.x4_, q.y4_) ||
        DoSegmentsIntersect(t.x1_, t.y1_, t.x2_, t.y2_, q.x4_, q.y4_, q.x1_, q.y1_) ||
        DoSegmentsIntersect(t.x2_, t.y2_, t.x3_, t.y3_, q.x1_, q.y1_, q.x2_, q.y2_) ||
        DoSegmentsIntersect(t.x2_, t.y2_, t.x3_, t.y3_, q.x2_, q.y2_, q.x3_, q.y3_) ||
        DoSegmentsIntersect(t.x2_, t.y2_, t.x3_, t.y3_, q.x3_, q.y3_, q.x4_, q.y4_) ||
        DoSegmentsIntersect(t.x2_, t.y2_, t.x3_, t.y3_, q.x4_, q.y4_, q.x1_, q.y1_) ||
        DoSegmentsIntersect(t.x3_, t.y3_, t.x1_, t.y1_, q.x1_, q.y1_, q.x2_, q.y2_) ||
        DoSegmentsIntersect(t.x3_, t.y3_, t.x1_, t.y1_, q.x2_, q.y2_, q.x3_, q.y3_) ||
        DoSegmentsIntersect(t.x3_, t.y3_, t.x1_, t.y1_, q.x3_, q.y3_, q.x4_, q.y4_) ||
        DoSegmentsIntersect(t.x3_, t.y3_, t.x1_, t.y1_, q.x4_, q.y4_, q.x1_, q.y1_);
}

bool IntersectionChecker::DoPolygonsIntersect(const Tetragon& q, const Triangle& t) {
    return DoPolygonsIntersect(t, q);
}

bool IntersectionChecker::DoPolygonsIntersect(const Tetragon& q1, const Tetragon& q2) {
    return DoSegmentsIntersect(q1.x1_, q1.y1_, q1.x2_, q1.y2_, q2.x1_, q2.y1_, q2.x2_, q2.y2_) ||
        DoSegmentsIntersect(q1.x1_, q1.y1_, q1.x2_, q1.y2_, q2.x2_, q2.y2_, q2.x3_, q2.y3_) ||
        DoSegmentsIntersect(q1.x1_, q1.y1_, q1.x2_, q1.y2_, q2.x3_, q2.y3_, q2.x4_, q2.y4_) ||
        DoSegmentsIntersect(q1.x1_, q1.y1_, q1.x2_, q1.y2_, q2.x4_, q2.y4_, q2.x1_, q2.y1_) ||
        DoSegmentsIntersect(q1.x2_, q1.y2_, q1.x3_, q1.y3_, q2.x1_, q2.y1_, q2.x2_, q2.y2_) ||
        DoSegmentsIntersect(q1.x2_, q1.y2_, q1.x3_, q1.y3_, q2.x2_, q2.y2_, q2.x3_, q2.y3_) ||
        DoSegmentsIntersect(q1.x2_, q1.y2_, q1.x3_, q1.y3_, q2.x3_, q2.y3_, q2.x4_, q2.y4_) ||
        DoSegmentsIntersect(q1.x2_, q1.y2_, q1.x3_, q1.y3_, q2.x4_, q2.y4_, q2.x1_, q2.y1_) ||
        DoSegmentsIntersect(q1.x3_, q1.y3_, q1.x4_, q1.y4_, q2.x1_, q2.y1_, q2.x2_, q2.y2_) ||
        DoSegmentsIntersect(q1.x3_, q1.y3_, q1.x4_, q1.y4_, q2.x2_, q2.y2_, q2.x3_, q2.y3_) ||
        DoSegmentsIntersect(q1.x3_, q1.y3_, q1.x4_, q1.y4_, q2.x3_, q2.y3_, q2.x4_, q2.y4_) ||
        DoSegmentsIntersect(q1.x3_, q1.y3_, q1.x4_, q1.y4_, q2.x4_, q2.y4_, q2.x1_, q2.y1_) ||
        DoSegmentsIntersect(q1.x4_, q1.y4_, q1.x1_, q1.y1_, q2.x1_, q2.y1_, q2.x2_, q2.y2_) ||
        DoSegmentsIntersect(q1.x4_, q1.y4_, q1.x1_, q1.y1_, q2.x2_, q2.y2_, q2.x3_, q2.y3_) ||
        DoSegmentsIntersect(q1.x4_, q1.y4_, q1.x1_, q1.y1_, q2.x3_, q2.y3_, q2.x4_, q2.y4_) ||
        DoSegmentsIntersect(q1.x4_, q1.y4_, q1.x1_, q1.y1_, q2.x4_, q2.y4_, q2.x1_, q2.y1_);
}