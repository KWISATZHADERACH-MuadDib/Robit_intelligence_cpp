#include <iostream>
#include "intData.hpp"

using namespace std;

Vector::Vector() {	//class가 생성되면 생성자가 자동으로 실행된다.
	cout << "몇 개의 원소를 할당하겠습니까? : ";
	cin >> size;

	intData = new int[size];	//int intData[] 동적 할당

	cout << "정수형 데이터 입력 : ";
	cin >> num;
	intData[0] = num;	
	min = num;	//초기 최솟값 선언
	max = num;	//초기 최댓값 선언
	sum = num;

	for (i = 1; i < size; i++) {
		cout << "정수형 데이터 입력 : ";
		cin >> num;
		intData[i] = num;
		sum += num;
		if (num < min)
			min = num;
		if (num > max)
			max = num;
	}

	avg = (double)sum / size;
}

Vector::~Vector() {	// 소멸자
	delete[] intData;	//동적 할당 해제
}

void Vector::print_result() {	//결과 출력
	cout << "최대값 : " << max << endl;
	cout << "최솟값 : " << min << endl;
	cout << "전체합 : " << sum << endl;
	cout << "평균 : " << avg;
}

int main() {
	Vector v;	//class 선언
	v.print_result();
}