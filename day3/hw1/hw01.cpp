#include <iostream>
#include "queue.hpp"

using namespace std;

int main() {
	yhw::queue<int> q;
	yhw::queue<int> p;
	yhw::queue<int> r;
	q.push(1);
	q.push(2);
	q.push(3);

	p.push(4);
	p.push(5);
	p.push(6);

	r = q + p;
	r + 3;
	r + 6;
	r + 73;

	while (!r.empty()) {
		cout << r.front() << endl;
		r.pop();
	}


	return 0;
}