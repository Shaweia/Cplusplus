#pragma once

#include<memory>
#if 0
//循环引用的场景
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
	//构成死锁
	std::cout << sp1.use_count() << std::endl;
	std::cout << sp2.use_count() << std::endl;
}
#endif


/*
weak_ptr维护的结果，伪代码：

struct count
{
	count()
	{}

	int s;  //share_ptr中的计数
	int w;  //weak_ptr中的计数
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



//库中实现的各个版本的智能指针，默认情况下是用delete来释放的，
//但对于非new出来的空间的指针就会存在问题

//定制的删除器
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

