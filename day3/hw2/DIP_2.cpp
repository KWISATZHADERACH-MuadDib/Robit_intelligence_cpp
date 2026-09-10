#include <iostream>

// 켜고 끌 수 있는 장치를 위한 인터페이스
class Switchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Switchable() = default;
};

// 인터페이스를 구현하는 저수준 클래스
class Fan : public Switchable {
public:
    void turnOn() override {
        std::cout << "Fan is spinning" << std::endl;
    }

    void turnOff() override {
        std::cout << "Fan is stopping" << std::endl;
    }
};

// 고수준 클래스
class Switch {
private:
    Switchable* device;

public:
    Switch(Switchable* device) : device(device) {}

    void turnOn() {
        device->turnOn();
    }

    void turnOff() {
        device->turnOff();
    }
};

int main() {
    Fan fan;
    Switch switcher(&fan);

    switcher.turnOn();  // Fan is spinning
    switcher.turnOff(); // Fan is stopping

    return 0;
}