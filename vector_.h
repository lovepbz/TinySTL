//vector
#pragma once
template<typename tp> class vector_
{
public:
	vector_();
	~vector_();
	void push_back(tp& x);
	tp& back();
	tp& pop_back();
	int find(tp& x);
	void reserve(int max);
	int size() { return _size; }
	tp& operator[](int index) { return _arr[index]; }
	vector_<tp>& operator=(vector_<tp>& v)
	{
		if (_arr != nullptr)delete[]_arr;
		_size = v.size();
		reserve(v.size());
		for (int i = 0; i < _size; ++i)
		{
			_arr[i] = v[i];
		}
		return *this;
	}
	bool operator==(vector_<tp>& v)
	{
		if (_size != v.size())return false;
		for (int i = 0; i < _size; ++i)
		{
			if (_arr[i] != v[i])return false;
		}
		return true;
	}


private:
	int _size;
	int _max;
	tp* _arr;
};

template<typename tp> vector_<tp>::vector_()
	:_size(0), _max(0), _arr(nullptr)
{

}

template<typename tp> vector_<tp>::~vector_()
{
	if (_arr != nullptr)
	{
		delete[]_arr;
	}
}

template<typename tp> inline void vector_< tp >::push_back(tp& x)
{
	if (_size == _max)
	{
		tp* temp = new tp[_max * 2 + 1];
		for (int i = 0; i < _size; ++i)
		{
			temp[i] = _arr[i];
		}
		temp[_size] = x;
		++_size;
		_max = _max * 2 + 1;
		if (_arr != nullptr)delete[]_arr;
		_arr = temp;
	}
	else
	{
		_arr[_size++] = x;
	}

}

template<typename tp> inline tp& vector_<tp>::back()
{
	return _arr[_size - 1];
}
template<typename tp> inline tp& vector_<tp>::pop_back()
{
	return _arr[_size--];
}
template<typename tp>inline int vector_<tp>::find(tp& x)
{
	for (int i = 0; i < _size; ++i)
	{
		if (_arr[i] == x)return i;
	}
	return -1;
}

template<typename tp> inline void vector_<tp>::reserve(int max)
{
	if (max > _max)
	{
		tp* temp = new tp[max];
		for (int i = 0; i < _size; ++i)
		{
			temp[i] = _arr[i];
		}
		_max = max;
		if (_arr != nullptr)delete[]_arr;
		_arr = temp;
	}
}

