#include <iostream>
#include <stdexcept>

// 작업자를 위한 인터페이스
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual ~Worker() = default;
};

// 일반 작업자를 나타내는 클래스
class Employee : public Worker {
public:
    void work() override {
        std::cout << "Employee is working" << std::endl;
    }

    void eat() override {
        std::cout << "Employee is eating" << std::endl;
    }
};

// 로봇을 나타내는 클래스
class Robot : public Worker {
public:
    void work() override {
        std::cout << "Robot is working" << std::endl;
    }

    void eat() override {
        // 로봇은 먹지 않음
        throw std::logic_error("Robots do not eat");
    }
};

int main() {
    Worker* employee = new Employee();
    employee->work(); // Employee is working
    employee->eat(); // Employee is eating

    Worker* robot = new Robot();
    robot->work(); // Robot is working
    robot->eat(); // std::logic_error: "Robots do not eat"

    delete employee;
    delete robot;

    return 0;
}