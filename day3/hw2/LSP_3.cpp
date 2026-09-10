#include <iostream>

// 기본 클래스
class Rectangle {
protected:
    int width;
    int height;

public:
    virtual void setWidth(int width) {
        this->width = width;
    }

    virtual void setHeight(int height) {
        this->height = height;
    }

    virtual int getArea() const {
        return width * height;
    }

    virtual ~Rectangle() = default;
};

// LSP를 위반하는 서브클래스
class Square : public Rectangle {
public:
    void setWidth(int width) override {
        this->width = width;
        this->height = width;
    }

    void setHeight(int height) override {
        this->width = height;
        this->height = height;
    }
};

// 클라이언트 코드
class AreaCalculator {
public:
    void calculateArea(Rectangle& rectangle) {
        rectangle.setWidth(5);
        rectangle.setHeight(4);
        std::cout << "Area: " << rectangle.getArea() << std::endl;
        // Rectangle에 대한 예상 출력: Area: 20
        // Square에 대한 실제 출력: Area: 16 (LSP 위반)
    }
};

int main() {
    AreaCalculator calculator;

    Rectangle rectangle;
    calculator.calculateArea(rectangle); // Area: 20

    Square square;
    calculator.calculateArea(square); // Area: 16 (LSP 위반)

    return 0;
}