#include <iostream>

struct _Point {
	int x;
	int y;
};

class Point {
public:
	_Point* arr;	
	Point();
	~Point();
	void generatePoint(int size, int min_coor, int max_coor);	//점의 위치를 무작위로 생성하고 동적 할당한 배열에 저장한다.
	void calcPointDist(int size, _Point* arr, double* MinDist, double* MaxDist, _Point* minPoint1, _Point* minPoint2, _Point* maxPoint1, _Point* maxPoint2);	
	//점들 사이의 거리를 계산하고 최소거리, 최대 거리를 구한다.
	//최소거리, 최대거리, 점의 좌표들을 반환받을 주소에 계산 값을 저장한다.
};