#ifndef _LINK_H
#define _LINK_H
template <class T>
class List 
{
	/*Common operation*/
	virtual void ClearAll() = 0 ;
	virtual bool Insert(const T&) = 0 ;
	virtual bool Append(const T&) = 0 ;
	virtual bool Remove(const T&) = 0 ;
	virtual T RemoveAt(int index) = 0 ;
	virtual T GetAt(int index) const = 0 ;
	virtual int GetLength() const = 0 ;

	/*Print all elements*/
	virtual void Print() const = 0 ;
	/*Sort by all kinds of common method*/
	virtual void BubbleSort() = 0 ;
	virtual void SelectSort() =0 ;
	virtual void InsertSort() = 0 ;
	virtual void QuickSort() = 0 ;
	virtual void ShellSort() = 0 ;
	virtual void HeapSort() = 0 ;
	virtual void MergerSort() = 0 ;
};
#endif
