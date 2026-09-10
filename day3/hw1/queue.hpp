#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "DATAFRAME.hpp"

namespace yhw {
	template <class T>
	class queue : public DataFrame<T> {
		size_t front_ = 0;
		size_t capacity_ = 0;

	public:
		queue();
		~queue();

		bool empty();		//비어있으면 1, 비어있지 않으면 0 반환	
		size_t size();		//queue의 크기 반환
		T front();			//queue의 첫번째 요소 반환
		T back();			//queue의 마지막 요소 반환
		void push(T val);	//queue에 요소를 마지막에 추가
		void pop();			//queue의 첫번째 요소 삭제
		void swap(queue<T>& other);	//다른 queue와 기존 queue의 data 바꾸기
		void clear();		//queue 요소 삭제
		queue<T> operator+(queue<T>& other);			//queue 추가
		queue<T>& operator=(const queue<T>& other);		//새로운 queue를 만들고 거기에 queue를 합친값을 저장한다(p + q를 했을 때 p에 추가하면 p의 원본이 훼손되기 때문)
		void operator+(T val);						//queue + data 구현
	};
}

#endif