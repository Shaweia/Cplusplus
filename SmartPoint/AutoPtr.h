#pragma once

//转移权限的方式
template<typename T>
class AutoPtr {
public:
	AutoPtr(T* ptr = NULL)
		:_ptr(ptr)
	{
		cout << "构造" << endl;
	}

	AutoPtr(AutoPtr& ap)
	{
		//转移管理权
		_ptr = ap._ptr;
		ap._ptr = NULL;
	}

	AutoPtr& operator=(AutoPtr& ap)
	{
		if (ap._ptr != _ptr)
		{
			AutoPtr tmp(ap);
			std::swap(_ptr, tmp._ptr);
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

	~AutoPtr()
	{
		if (_ptr != NULL)
		{
			cout << "析构" << endl;
			delete _ptr;
			_ptr = NULL;
		}
	}
private:
	T * _ptr;
};

