#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <iostream>
#include <string.h>
#include "List.h"
using namespace std ;
template <class T>
class LinkList:public List<T>
{
public:
	LinkList() ;
	LinkList(const LinkList<T> &) ;
	~LinkList() ;

	void ClearAll() ;
	bool Insert(const T&) ;
	bool Append(const T&) ;
	bool Remove(const T&) ;
	T RemoveAt(int index) ;
	T GetAt(int index) ;
	int GetLength() ;

	void Print() ;
	
	void BubbleSort() ;
	void SelectSort() ;
	void InsertSort() ;
	void QuickSort() ;
	void ShellSort() ;
	void HeapSort() ;
	void MergerSort() ;
	
	void ReverseList() ;
private:
	struct LinkNode
	{
		struct LinkNode *next ;
		T data ;
	};

	LinkNode *mHead ;
	LinkNode *mTail ;
	int mLength ;
} ;
#endif
