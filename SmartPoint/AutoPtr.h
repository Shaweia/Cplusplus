#pragma once

//ת��Ȩ�޵ķ�ʽ
template<typename T>
class AutoPtr {
public:
	AutoPtr(T* ptr = NULL)
		:_ptr(ptr)
	{
		cout << "����" << endl;
	}

	AutoPtr(AutoPtr& ap)
	{
		//ת�ƹ���Ȩ
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
			cout << "����" << endl;
			delete _ptr;
			_ptr = NULL;
		}
	}
private:
	T * _ptr;
};

