#include <iostream>

using namespace std;

class Vector {
private:
	int* intData;
	int size;
	int num;
	int max;
	int min;
	int sum;
	double avg;
	int i;

public :
	Vector();	//생성자
	~Vector();	//소멸자
	void print_result();	// 결과값(최대값, 최솟값, 전체합, 평균) 출력함수
};