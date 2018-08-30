#pragma once


//禁止使用拷贝构造函数和赋值运算符重载
template<typename T>
class ScopedPtr {
public:
	ScopedPtr(T* ptr = NULL)
		:_ptr(ptr)
	{}

	~ScopedPtr()
	{
		if (_ptr != NULL)
		{
			cout << "析构" << endl;
			delete _ptr;
			_ptr = NULL;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	//拷贝构造
	ScopedPtr(const ScopedPtr& sp);
	//赋值运算符重载
	ScopedPtr& operator=(const ScopedPtr& sp);

	T* _ptr;
};
