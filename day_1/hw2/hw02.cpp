#include <iostream>
#include <random>
#include <cmath>
#include <cstdio>
#include "Point.hpp"

using namespace std;

void Point::generatePoint(int size, int min_coor, int max_coor) {
	arr = new _Point[size];		//arr를 size만큼 동적 할당
	random_device rd;
	uniform_int_distribution<int> distribution(min_coor, max_coor);	// 난수 생성
	for (int i = 0; i < size; i++) {
		arr[i].x = distribution(rd);	//arr[i].x에 난수 대입
		arr[i].y = distribution(rd);	//arr[i].y에 난수 대입
		cout << "Point " << i << ". nX=" << arr[i].x << " , " << "nY=" << arr[i].y << endl;
	}
	cout << endl;
}

// 두점 사이의 거리를 게산하는 함수. 그리고 계산 결과를 입력받은 주소에 저장한다.
void Point::calcPointDist(int size, _Point* arr, double* MinDist, double* MaxDist, _Point* minPoint1, _Point* minPoint2, _Point* maxPoint1, _Point* maxPoint2) {
	int x1, y1;
	int x2, y2;
	int diff_x, diff_y;
	double dist;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {	//두 점 사이의 거리를 비교할 때 (0번쨰, 1번째) 비교하고 (1번쨰, 0번쨰)를 또 비교할 필요는 없기에 j = i+1로 중복 비교를 피했다. -> nC2
			x1 = arr[i].x;
			y1 = arr[i].y;
			x2 = arr[j].x;
			y2 = arr[j].y;
			diff_x = x1 - x2;
			diff_y = y1 - y2;
			dist = sqrt((double)(diff_x * diff_x + diff_y * diff_y));
			if (i == 0 && j == 1) {
				*MinDist = dist;	// MinDist 초기값 설정
				*MaxDist = dist;	// MaxDist 초기값 설정
				*minPoint1 = arr[i];	//minPoint1 초기값 설정
				*minPoint2 = arr[j];	//maxPoint2 초기값 설정
				*maxPoint1 = arr[i];	//maxPoint1 초기값 설정
				*maxPoint2 = arr[j];	//maxPoint2 초기값 설정
			}
			else {
				if (dist < *MinDist) {	//계산한 거리가 최소거리보다 작을 경우 최소거리 업데이트
					*MinDist = dist;
					*minPoint1 = arr[i];
					*minPoint2 = arr[j];
				}	
				if (dist > *MaxDist) {	//계산한 거리가 최대거리보다 클 경우 최대거리 업데이트
					*MaxDist = dist;
					*maxPoint1 = arr[i];
					*maxPoint2 = arr[j];
				}
			}
		}
	}
}

Point::Point() {
	arr = nullptr;	//배열 초기화
}

Point::~Point() {
	delete[] arr;	//동적할당 배열 삭제
}

int main()
{
	int num;
	int min_coor;
	int max_coor;
	double Mindist, Maxdist;
	_Point minPoint1, minPoint2, maxPoint1, maxPoint2;
	Point p;

	cout << "******** HW 3 Point Distance Computation ********\n\n\n" << endl;
	cout << "Please define the number of points(number > 1) : ";
	cin >> num;

	if (num < 2) {
		cout << "The number must be 2 or greater.";
		return 0;
	}

	cout << "Please define minimum of coor. value : ";
	cin >> min_coor;
	cout << "Please define maximum of coor. value : ";
	cin >> max_coor;
	cout << "Generate Random points\n\n" << endl;

	p.generatePoint(num, min_coor, max_coor);
	p.calcPointDist(num, p.arr, &Mindist, &Maxdist, &minPoint1, &minPoint2, &maxPoint1, &maxPoint2);

	cout << "-------- Result --------" << endl;
	cout << "MinDist=" << Mindist << endl;
	printf("Pair of Min Coor.<x, y>: P1<%d,%d> & P2<%d,%d>\n\n", minPoint1.x, minPoint1.y, minPoint2.x, minPoint2.y);	//cout으로 쓰려니까 너무 길어져서 그냥 <cstdio>추가하고 printf를 사용했다.
	cout << "MaxDist=" << Maxdist << endl;
	printf("Pair of Max Coor.<x, y>: P1<%d,%d> & P2<%d,%d>\n\n", maxPoint1.x, maxPoint1.y, maxPoint2.x, maxPoint2.y);
	cout << "******************** Completed ********************" << endl;
	return 0;
}