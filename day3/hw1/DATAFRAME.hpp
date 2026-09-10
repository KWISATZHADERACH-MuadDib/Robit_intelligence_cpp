#ifndef DATAFRAME_HPP
#define DATAFRAME_HPP
template <class T>
class DataFrame {
protected:
	T* data_;
	size_t size_;
public:
	DataFrame() :data_(nullptr), size_(0) {}
	~DataFrame()	
	{
		if (data_ != nullptr) {
			delete[] data_;
		}
	}
	virtual size_t size() = 0;
	virtual void clear() = 0;
};
#endif