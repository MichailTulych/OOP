#pragma once
#include <vector>
#include <memory>
#include "Shape.h"
#include "Triangle.h"
#include "Tetragon.h"

using namespace std;

class Factory {
public:
    void CreateObject();
    void DeleteObject();
    void ShowObjects() const;
    void MoveObject();
    void CheckIntersection();

private:
    vector<unique_ptr<Shape>> objects_;
};