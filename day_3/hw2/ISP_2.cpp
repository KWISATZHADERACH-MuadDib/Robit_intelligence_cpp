#include <iostream>

// 작업 관련 동작을 위한 인터페이스
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() = default;
};

// 식사 관련 동작을 위한 인터페이스
class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() = default;
};

// 일반 작업자를 나타내는 클래스
class Employee : public Workable, public Eatable {
public:
    void work() override {
        std::cout << "Employee is working" << std::endl;
    }

    void eat() override {
        std::cout << "Employee is eating" << std::endl;
    }
};

// 로봇을 나타내는 클래스
class Robot : public Workable {
public:
    void work() override {
        std::cout << "Robot is working" << std::endl;
    }
    // Robot은 Eatable 인터페이스를 구현하지 않음
};

int main() {
    Workable* employee = new Employee();
    employee->work(); // Employee is working
    dynamic_cast<Eatable*>(employee)->eat(); // Employee is eating

    Workable* robot = new Robot();
    robot->work(); // Robot is working

    delete employee;
    delete robot;

    return 0;
}