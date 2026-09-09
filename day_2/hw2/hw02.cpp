#include <iostream>
#include "queue.hpp"

using namespace std;

int main() {
	yhw::queue<int> q;
	string filename = "input.txt";

	// 기존 파일 내용 불러오기, 파일 없으면 새로 생성
	q.load(filename);
	cout << "load 완료" << endl;
	cout << "현재 파일에 저장된 데이터 개수: " << q.size() << endl;


	int n;
	cout << "\n추가할 데이터 개수를 입력하세요 : ";	// 사용자로부터 추가할 데이터 입력받기
	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cout << (i + 1) << "번째 값 입력 : ";
		cin >> val;
		q.push(val);
	}

	
	q.save(filename);		// 입력받은 내용을 파일에 반영
	cout << "\nsave 완료, 입력한 내용이 " << filename << " 에 저장되었습니다." << endl;

	cout << "현재 size: " << q.size() << endl;
	cout << "front: " << q.front() << ", back: " << q.back() << endl;

	q.clear();
	cout << "\nclear 후 empty: " << q.empty() << endl;

	return 0;
}