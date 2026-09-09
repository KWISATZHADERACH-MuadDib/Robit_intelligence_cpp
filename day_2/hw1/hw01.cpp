#include <iostream>
#include "queue.hpp"

using namespace std;

int main() {
	yhw::queue<int> q;
	yhw::queue<int> p;

	cout << "empty: " << q.empty() << endl;

	//q : 1, 2, 3 / p : 5, 6, 7
	q.push(1);
	q.push(2);
	q.push(3);
	p.push(5);
	p.push(6);
	p.push(7);

	cout << "q size: " << q.size() << endl;
	cout << "q fornt: " << q.front() << endl;
	cout << "q back: " << q.back() << endl;

	cout << "p size: " << p.size() << endl;
	cout << "p fornt: " << p.front() << endl;
	cout << "p back: " << p.back() << endl;

	q.pop();
	cout << "pop 후 front " << q.front() << endl;
	cout << "pop 후 size: " << q.size() << endl;
	q.push(4);

	//q : 2, 3, 4 / p : 5, 6, 7
	q.swap(p);
	cout << "swap 후 "<< endl;
	cout << "q size: " << q.size() << endl;
	cout << "q fornt: " << q.front() << endl;
	cout << "q back: " << q.back() << endl;

	cout << "p size: " << p.size() << endl;
	cout << "p fornt: " << p.front() << endl;
	cout << "p back: " << p.back() << endl;

	q.clear();
	cout << "clear 후 empty: " << q.empty() << endl;

	return 0;
}