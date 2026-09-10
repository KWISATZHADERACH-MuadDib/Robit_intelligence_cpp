#include <iostream>
#include <stdexcept>

// 부모 클래스 Bird
class Bird {
public:
    virtual void fly() {
        std::cout << "Bird is flying" << std::endl;
    }

    virtual ~Bird() = default;
};

// LSP를 위반하는 자식 클래스 Penguin
class Penguin : public Bird {
public:
    void fly() override {
        // 펭귄은 날 수 없음
        throw std::logic_error("Penguins cannot fly");
    }
};

int main() {
    Bird bird;
    bird.fly(); // Bird is flying

    Bird* penguin = new Penguin();
    penguin->fly(); // std::logic_error: "Penguins cannot fly"

    delete penguin;

    return 0;
}