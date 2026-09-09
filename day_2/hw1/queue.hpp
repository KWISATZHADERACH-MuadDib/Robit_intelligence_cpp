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
		void clear();	//queue 요소 삭제
	};
}

#endif