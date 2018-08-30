#pragma once


//��ֹʹ�ÿ������캯���͸�ֵ���������
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
			cout << "����" << endl;
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
	//��������
	ScopedPtr(const ScopedPtr& sp);
	//��ֵ���������
	ScopedPtr& operator=(const ScopedPtr& sp);

	T* _ptr;
};
