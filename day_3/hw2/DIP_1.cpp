#include <iostream>

// 저수준 클래스
class Fan {
public:
    void spin() {
        std::cout << "Fan is spinning" << std::endl;
    }

    void stop() {
        std::cout << "Fan is stopping" << std::endl;
    }
};

// 고수준 클래스
class Switch {
private:
    Fan* fan;

public:
    Switch(Fan* fan) : fan(fan) {}

    void turnOn() {
        fan->spin();
    }

    void turnOff() {
        fan->stop();
    }
};

int main() {
    Fan fan;
    Switch switcher(&fan);

    switcher.turnOn();  // Fan is spinning
    switcher.turnOff(); // Fan is stopping

    return 0;
}