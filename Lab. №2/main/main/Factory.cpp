#include "Factory.h"
#include <iostream>

using namespace std;

void Factory::CreateObject() {
    setlocale(LC_ALL, "Russian");
    cout << "�������� ��� �������:\n1. �����������\n2. ���������������\n";
    int choice;
    cin >> choice;

    string id;
    cout << "������� �������������: ";
    cin >> id;

    if (choice == 1) {
        double x1, y1, x2, y2, x3, y3;
        cout << "������� ���������� ������ ������������ (x1 y1 x2 y2 x3 y3): ";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        objects_.emplace_back(make_unique<Triangle>(id, x1, y1, x2, y2, x3, y3));
    }
    else if (choice == 2) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cout << "������� ���������� ������ ���������������� (x1 y1 x2 y2 x3 y3 x4 y4): ";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        objects_.emplace_back(make_unique<Tetragon>(id, x1, y1, x2, y2, x3, y3, x4, y4));
    }
    else {
        cout << "�������� �����.\n";
    }
}

void Factory::DeleteObject() {
    setlocale(LC_ALL, "Russian");
    if (objects_.empty()) {
        cout << "��� �������� ��� ��������.\n";
        return;
    }

    cout << "�������� ������ ��� ��������:\n";
    for (size_t i = 0; i < objects_.size(); ++i) {
        cout << i + 1 << ". " << objects_[i]->GetID() << "\n";
    }

    int choice;
    cin >> choice;

    if (choice > 0 && choice <= objects_.size()) {
        objects_.erase(objects_.begin() + choice - 1);
        cout << "������ ������.\n";
    }
    else {
        cout << "�������� �����.\n";
    }
}

void Factory::ShowObjects() const {
    setlocale(LC_ALL, "Russian");
    if (objects_.empty()) {
        cout << "��� �������� ��� �����������.\n";
        return;
    }

    for (const auto& obj : objects_) {
        obj->Show();
    }
}

void Factory::MoveObject() {
    setlocale(LC_ALL, "Russian");
    if (objects_.empty()) {
        cout << "��� �������� ��� �����������.\n";
        return;
    }

    cout << "�������� ������ ��� �����������:\n";
    for (size_t i = 0; i < objects_.size(); ++i) {
        cout << i + 1 << ". " << objects_[i]->GetID() << "\n";
    }

    int choice;
    cin >> choice;

    if (choice > 0 && choice <= objects_.size()) {
        double dx, dy;
        cout << "������� �������� (dx dy): ";
        cin >> dx >> dy;
        objects_[choice - 1]->Move(dx, dy);
    }
    else {
        cout << "�������� �����.\n";
    }
}

void Factory::CheckIntersection() {
    setlocale(LC_ALL, "Russian");
    if (objects_.size() < 2) {
        cout << "������������ �������� ��� �������� �����������.\n";
        return;
    }

    cout << "�������� ��� ������� ��� �������� �����������:\n";
    for (size_t i = 0; i < objects_.size(); ++i) {
        cout << i + 1 << ". " << objects_[i]->GetID() << "\n";
    }

    int choice1, choice2;
    cin >> choice1 >> choice2;

    if (choice1 > 0 && choice1 <= objects_.size() &&
        choice2 > 0 && choice2 <= objects_.size() && choice1 != choice2) {
        bool intersect = objects_[choice1 - 1]->IsIntersect(*objects_[choice2 - 1]);
        cout << "��������� �����������: " << (intersect ? "��" : "���") << "\n";
    }
    else {
        cout << "�������� �����.\n";
    }
}
