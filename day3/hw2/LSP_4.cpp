#include <iostream>

// 기본 인터페이스
class Shape {
public:
    virtual int getArea() const = 0;
    virtual ~Shape() = default;
};

// 구현체들
class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle() : width(4), height(5) {}  //기본 생성자
    Rectangle(int width, int height) : width(width), height(height) {}

    int getArea() const override {
        return width * height;
    }
};

class Square : public Shape {
private:
    int side;

public:
    Square() : side(4) {}  // 예시용 기본 생성자
    Square(int side) : side(side) {}

    int getArea() const override {
        return side * side;
    }
};

// 클라이언트 코드
class AreaCalculator {
public:
    void calculateArea(const Shape& shape) {
        std::cout << "Area: " << shape.getArea() << std::endl;
    }
};

// 사용 예시
int main() {
    AreaCalculator calculator;

    // LSP 위반
    Rectangle rectangleDefault;
    calculator.calculateArea(rectangleDefault); // Area: 20

    Square squareDefault;
    calculator.calculateArea(squareDefault); // Area: 16 (예상과 다름)

    // LSP 준수
    Rectangle rectangle(5, 4);
    calculator.calculateArea(rectangle); // Area: 20

    Square square(5);
    calculator.calculateArea(square); // Area: 25 (예상대로)

    return 0;
}