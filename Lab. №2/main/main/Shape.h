#pragma once
#include <string>

using namespace std;

class Shape {
public:
    explicit Shape(const string& id) : id_(id) {}
    virtual ~Shape() = default;

    virtual void Move(double dx, double dy) = 0;
    virtual void Show() const = 0;
    virtual bool IsIntersect(const Shape& other) const = 0;

    const string& GetID() const { return id_; }

private:
    string id_;
};