#pragma once

//ʹ�����ü����ķ�ʽ

template<typename T>
class SharedPtr {
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		,_count(new int(1))
	{}

	//��������
	SharedPtr(const SharedPtr& sp)
		:_ptr(sp._ptr)
		,_count(sp._count)
	{
		++(*_count);
	}
	//��ֵ���������
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
			cout << "����" << endl;
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

