#pragma once

//使用引用计数的方式

template<typename T>
class SharedPtr {
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		,_count(new int(1))
	{}

	//拷贝构造
	SharedPtr(const SharedPtr& sp)
		:_ptr(sp._ptr)
		,_count(sp._count)
	{
		++(*_count);
	}
	//赋值运算符重载
	SharedPtr& operator=(const SharedPtr& sp)
	{
		if (_ptr != sp._ptr)
		{
			SharedPtr tmp(sp);
			std::swap(_ptr, tmp._ptr);
			std::swap(_count, tmp._count);
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~SharedPtr()
	{
		if (*_count == 0)
		{
			cout << "析构" << endl;
			delete _ptr;
			delete _count;
			_ptr = NULL;
			_count = NULL;
		}
		else
		{
			(*_count)--;
		}
	}
private:
	T * _ptr;
	int *_count;
};

