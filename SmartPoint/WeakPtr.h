#pragma once

#include<memory>
#if 0
//ѭ�����õĳ���
template<typename T>
struct ListNode {
	T _value;
	std::shared_ptr<ListNode> _prev;
	std::shared_ptr<ListNode> _next;
	ListNode(const T & value)
		:_value(value)
		, _prev(NULL)
		, _next(NULL) {}
};
void TestWeekPtr() {
	std::shared_ptr<ListNode<int>> sp1(new ListNode<int>(10));
	std::shared_ptr<ListNode<int>> sp2(new ListNode<int>(20));
	sp1->_next = sp2;
	sp2->_prev = sp1;
	//��������
	std::cout << sp1.use_count() << std::endl;
	std::cout << sp2.use_count() << std::endl;
}
#endif


/*
weak_ptrά���Ľ����α���룺

struct count
{
	count()
	{}

	int s;  //share_ptr�еļ���
	int w;  //weak_ptr�еļ���
};

*/


template<typename T>
struct ListNode {
	T _value;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;
	ListNode(const T value)
		:_value(value)
		, _prev(NULL)
		, _next(NULL) 
	{}
};



//����ʵ�ֵĸ����汾������ָ�룬Ĭ�����������delete���ͷŵģ�
//�����ڷ�new�����Ŀռ��ָ��ͻ��������

//���Ƶ�ɾ����
class Fclose
{
public:
	void operator()(void* ptr)
	{
		cout << "fclose" << endl;
		fclose((FILE*)ptr);
	}
};

class Free
{
public:
	void operator()(void* ptr)
	{
		cout << "free" << endl;
		free(ptr);
	}
};


void Fclosetest()
{
	share_ptr<FILE> P1(fopen("test.txt", "w"), Fclose());
}

