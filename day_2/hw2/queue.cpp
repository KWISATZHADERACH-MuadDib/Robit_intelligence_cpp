#include <fstream>
#include <iostream>
#include "queue.hpp"

namespace yhw {
	template <class T>
	queue<T>::queue() {}	//queue 생성

	template <class T>
	queue<T>::~queue() {
		clear();		//queue 삭제
	}

	template <class T>			//empty 구현 : queue 비우기
	bool queue<T>::empty() {
		return this->size_ == 0;
	}

	template <class T>			//size 반환
	size_t queue<T>::size() {
		return this->size_;
	}

	template <class T>
	T queue<T>::front() {		//맨 처음 요소 반환
		return this->data_[front_];
	}

	template <class T>
	T queue<T>::back() {
		return this->data_[front_ + this->size_ - 1];	//마지막 요소 반환
	}
	
	template <class T>
	void queue<T>::push(T val) {
		if (this->size_ == capacity_) {	//queue가 꽉찼을 경우
			size_t newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2; //capacity가 0이면 크기를 2배 해도 0이기 때문에 0인 경우에는 1이 되도록 예외처리한다.
																		//아닌 경우 queue가 꽉 찬다면 queue의 크기를 2배로 늘린가.
			T* newData = new T[newCapacity];	//정한 capacity 만큼 queue를 할당 받는다

			for (size_t i = 0; i < this->size_; i++) {	//기존의 데이터를 newData queue의 0번쨰 부터로 옮긴다.
				newData[i] = this->data_[front_ + i];
			}

			if (this->data_ != nullptr) {				//기존 queue의 메모리를 반납한다.
				delete[] this->data_;
			}

			this->data_ = newData;						//newData를 기존 data_로 변경해서 data_에 queue를 옮긴다
			capacity_ = newCapacity;					//용량은 new용량으로 갱신
			front_ = 0;
		}

		this->data_[front_ + this->size_] = val;	//용량이 충분한 경우, 마지막 queue에 val 추가
		this->size_++;								//queue size 증가
	}

	template <class T>
	void queue<T>::pop() {
		if (this->size_ > 0) {	//요소가 있을 경우
			front_++;			//맨앞 요소는 무시하기 위해 front 1증가시킨다
			this->size_--;		//요소가 추가되므로 size_도 1증가
		}
	}

	template <class T>
	void queue<T>::swap(queue<T>& other) {	//다른 queue를 매개변수로 가진다.
		T* tempData = this->data_;			//tempData에 기존 queue 데이터 저장
		size_t tempSize = this->size_;		//tempSize에 기존 queue size 저장
		size_t tempFront = front_;			//tempFront에 기존 queue의 front값 저장
		size_t tempCapacity = capacity_;	//tempcapacity에 기존 queue의 capacity값 저장

		this->data_ = other.data_;			//기존 queue Data에 other queue의 데이터 저장
		this->size_ = other.size_;			//기존 queue size_에 other queue의 size_ 저장	
		front_ = other.front_;				//기존 queue front_에 other queue의 fornt_ 저장
		capacity_ = other.capacity_;		//기존 queue capacity에 other queue의 capacity 저장

		other.data_ = tempData;				//other queue Data에 tempData 저장
		other.size_ = tempSize;				//other queue size_에 tempSize 저장
		other.front_ = tempFront;			//other queue Front_에 tempfront 저장
		other.capacity_ = tempCapacity;		//other queue capacity에 tempCapacity 저장
	}

	template <class T>
	void queue<T>::clear() {			//queue 삭제
		if (this->data_ != nullptr) {	//queue가 존재할 경우
			delete[] this->data_;		//data_ 동적 메모리 해제
			this->data_ = nullptr;		//data_를 nullptr로 초기화
		}
		this->size_ = 0;		//size_ 0으로 초기화
		front_ = 0;				//front_ 0으로 초기화
		capacity_ = 0;			//capacity_ 0으로 초기화
	}

	template <class T>
	void queue<T>::save(const std::string& filename) {
		std::ofstream fout(filename);
		if (!fout) {		//파일 열기를 실패했다면 예외처리
			std::cout << "파일 열기 실패: " << filename << std::endl;
			return;
		}

		for (size_t i = 0; i < this->size_; i++) {
			fout << this->data_[front_ + i];	//queue 요소를 순서대로 파일 출력
			fout << " ";
		}
		fout.close();
	}

	template <class T>
	void queue<T>::load(const std::string& filename) {
		std::ifstream fin(filename);
		if (!fin) {
			std::ofstream fout(filename);	//파일이 없으면 빈 파일을 새로 생성한다.
			fout.close();

			clear();	//queue도 초기화함
			return;
		}

		clear();

		T val;
		while (fin >> val) {	//파일에서 공백/줄바꿈으로 구분된 값을 하나씩 읽어온다
			push(val);
		}
		fin.close();
	}

	template class queue<int>;
	template class queue<double>;
	template class queue<char>;
}