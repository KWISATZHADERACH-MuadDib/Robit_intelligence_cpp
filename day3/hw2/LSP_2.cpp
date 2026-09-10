#include <iostream>

// 날 수 있는 새를 위한 독립된 인터페이스
class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() = default;
};

// 기본 클래스 Bird
class Bird {
public:
    void eat() {
        std::cout << "Bird is eating" << std::endl;
    }

    virtual ~Bird() = default;
};

// 날 수 있는 새인 참새 클래스
class Sparrow : public Bird, public Flyable {
public:
    void fly() override {
        std::cout << "Sparrow is flying" << std::endl;
    }
};

// 날 수 없는 새 클래스
class Penguin : public Bird {
    // Penguin은 Flyable을 구현하지 않음
};

int main() {
    Bird* sparrow = new Sparrow();
    sparrow->eat(); // Bird is eating
    dynamic_cast<Flyable*>(sparrow)->fly();      

    Bird* penguin = new Penguin();
    penguin->eat(); // Bird is eating

    delete sparrow;
    delete penguin;

    return 0;
}