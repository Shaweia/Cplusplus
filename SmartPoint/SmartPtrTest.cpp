#include<iostream>
using namespace std;

#include"AutoPtr.h"
#include"ScopedPtr.h"
#include"SharedPtr.h"
#include"WeakPtr.h"

void AutoPtrTest()
{
	AutoPtr<int> ap1(new int(10));
	AutoPtr<int> ap2(new int(20));
	AutoPtr<int> ap3(ap1);
	AutoPtr<int> ap4(ap2);
	ap3 = ap4;
}

void ScopedPtrTest()
{
	ScopedPtr<int> sp1(new int(10));
	ScopedPtr<int> sp2(new int(20));
	//ScopedPtr<int> sp3(sp1);
	//ScopedPtr<int> sp4 = sp2;
}


void SharedPtrTest1()
{
	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(new int(20));
	SharedPtr<int> sp3(sp1);
	SharedPtr<int> sp4(new int);
	sp4 = sp2;
}



void WeakPtrTest() {
	shared_ptr<ListNode<int>> sp1(new ListNode<int>(10));
	shared_ptr<ListNode<int>> sp2(new ListNode<int>(20));
	sp1->_next = sp2;
	sp2->_prev = sp1;

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}


int main()
{
	//AutoPtrTest();
	//ScopedPtrTest();
	//SharedPtrTest1();
	WeakPtrTest();

	return 0;
}