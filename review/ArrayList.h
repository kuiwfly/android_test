#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H
#include <iostream>
#include <string.h>
#include "List.h"
using namespace std ;

#define BUFINC 16 
#define CEILLEN(len) ((len)|0x000F)

template <typename T>//note:template class usage
class ArrayList :public List<T>//note:inheritance usage
{
public:
	ArrayList() ;
	ArrayList(const ArrayList &) ;//note:deep copy and light copy
	~ArrayList() ;

	void ClearAll() ;
	bool Insert(const T& elem) ;//note:const usage and advantage 
	bool Append(const T& elem) ;
	bool Remove(const T& elem) ;
	T RemoveAt(int index) ;
	T GetAt(int index) const ;//note: standard usage 
	int GetLength() const ;
	
	void Print() const ;
	
	void BubbleSort() ;
	void SelectSort() ;
	void InsertSort() ;
	void QuickSort() ;
	void ShellSort() ;
	void HeapSort() ;
	void MergerSort() ;
private:
	T *mArray ;
	int mIndex ;
	int mLength ;
};
template <class T>
ArrayList<T>::ArrayList()
{
//	mArray = NULL ;
	mIndex = 0 ;
//	mLength = 0 ;
	mArray = new T[BUFINC] ;
	mLength = BUFINC ;
}
template <class T>
ArrayList<T>::~ArrayList()
{
	if(mArray != NULL){
		/*note: the differece between delete and delete[]*/
		delete[] mArray ; 
		mArray = NULL ;
	}	
	mIndex = 0 ;
	mLength = 0 ;
}
template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> &arrayList)
{
	mLength = CEILLEN(arrayList.GetLength()) ;
	mArray = new T[mLength]	 ;//note: how to new array 
	memcpy(mArray,arrayList.mArray,mIndex*sizeof(T)) ;
	mIndex = arrayList.mIndex ;
}
template <class T>
void ArrayList<T>::ClearAll()
{
	memset(mArray,0,mLength*sizeof(T)) ;
	mIndex = 0 ;
}
template <class T>
bool ArrayList<T>::Append(const T& elem)
{
	if(mIndex == mLength-1){
		T *tmpArray = new T[mLength+BUFINC] ;
		memcpy(tmpArray,mArray,mLength*sizeof(T)) ;
		delete[] mArray ;
		mArray = tmpArray ;
	}	
	mArray[mIndex++] = elem ;
	return true ;
}
template <class T>
bool ArrayList<T>::Insert(const T& elem)
{
//	cout<<"insert:"<<elem<<endl ;
	if(mIndex == mLength-1) {
		T *tmpArray = new T[mLength+BUFINC] ;
		T *tmpArray1 = tmpArray+1 ;
		memcpy(tmpArray1,mArray,mLength*sizeof(T)) ;
		mLength += BUFINC ;
		mIndex++ ;
		tmpArray[0] = elem ;
		delete[] mArray ;
		mArray = tmpArray ;
		
		return true ;
	}	
	int tmpIndex = mIndex++ ;
	while(tmpIndex--){
		mArray[tmpIndex+1] = mArray[tmpIndex] ;
	}
	mArray[0] = elem ;
	return true ;
}
template <class T>
void ArrayList<T>::Print() const
{
	for(int i=0 ; i<mIndex ; i++){
		cout<<mArray[i]<<',' ;
	}
	cout<<endl ;
}
template <class T>
bool ArrayList<T>::Remove(const T& elem)
{
	
	return true ;
}
template <class T>
T ArrayList<T>::RemoveAt(int index) 
{
	T tmp = mArray[index] ;
	return tmp ;	
}
template <class T>
T ArrayList<T>::GetAt(int index) const
{
	return mArray[index] ;
}
template <class T>
int ArrayList<T>::GetLength() const
{
	return mLength ;
}
template <class T>
void inline swap_T(T& a,T& b)
{
	if(a == b){
		return ;
	}	
	a = a^b ;
	b = a^b ;
	a = a^b ;
}
template <class T>
void ArrayList<T>::BubbleSort()
{
	for(int i=0 ; i<mIndex ; i++){
		for(int j=0 ; j<(mIndex-i-1) ; j++) {
			if(mArray[j]<mArray[j+1]){
				swap_T(mArray[j],mArray[j+1]) ;
			}	
		}
		Print() ;
	}
}
template <class T>
void ArrayList<T>::SelectSort()
{
	for(int i=0 ; i<mIndex ; i++) {
		for(int j=i ; j<mIndex ; j++){
			if(mArray[i]>mArray[j]){
				swap(mArray[i],mArray[j]) ;
			}	
		}
	}	
}
template <class T>
void ArrayList<T>::InsertSort()
{
	for(int i=0 ; i<mIndex ; i++) {
		for(int j=i ; j>0 ; j--) {
			if(mArray[j]<mArray[j-1]){
				swap_T(mArray[j],mArray[j-1]) ;
			}else{
				break ;
			}	
		}
		Print() ;
	}
}
template <class T>
int Partition(T array[], int left, int right)
{
	int index = left;
	int pivot = right ;
	for(int i=left ; i<right ; i++){
		if(array[i]<array[pivot]){
			swap(array[i],array[index++]) ;//put smaller on the left, and note:index
		}	
	}
	swap(array[pivot],array[index]) ;
	return index ;
}
template <class T>
void QuickSort_T(T array[], int left, int right)
{
	int tmp =0 ;
	if(left<right){
		tmp = Partition(array,left,right) ;
		QuickSort_T(array,left,tmp-1) ;
		QuickSort_T(array,tmp+1,right) ;	
	}
	
}
template <class T>
void ArrayList<T>::QuickSort()
{
	QuickSort_T(mArray,0,mIndex-1) ;	
}
template <class T>
void ArrayList<T>::ShellSort()
{
	int inc = mIndex ;
	do {
		inc = inc/3 + 1 ;//compute increment
	
		for(int i=0 ;i<inc ;i++){//group
			for(int j=i ; j<mIndex ; j=j+inc){//insertion sort
				for(int k=j ; k>=inc ; k=k-inc){
					if(mArray[k]<mArray[k-inc]){
						swap_T(mArray[k],mArray[k-inc]) ;	
					}else{
						break ;
					}	
				}
			}
		}
	}while(inc>1) ;//when increment = 1 ,stop	
}
template <class T>
void ArrayList<T>::HeapSort()
{
}
template <class T>
void Merge(T array[] , T tmpArray[],  int left, int right ,int middle)
{
	int i=left ;
	int j=middle+1 ;
	int k=left ;
	for( ; i<=middle && j<=right ;){
		if(array[i]<array[j]){
			tmpArray[k++] = array[i++] ;
		}else{
			tmpArray[k++] = array[j++] ;
		}
	}
	if(i<=middle){
		memcpy(tmpArray+k,array+i,(middle-i+1)*sizeof(T)) ;
	}
	if(j<=right){
		memcpy(tmpArray+k,array+j,(right-j+1)*sizeof(T)) ;
	}
	memcpy(array+left,tmpArray+left,(right-left+1)*sizeof(T)) ;
	
	for(i=left;i<=right;i++){
		cout<<tmpArray[i]<<"," ;
	}
	cout<<endl ;
	
}
template <class T>
void MergerSort_T(T array[],T tmpArray[], int left, int right)
{
	if(left == right){
		tmpArray[left] = array[left] ;
	}else{
		int tmp = (left+right)/2 ;
		MergerSort_T(array,tmpArray,left,tmp) ;
		MergerSort_T(array,tmpArray,tmp+1,right) ;
		Merge(array, tmpArray, left, right, tmp) ;
	}
}
template <class T>
void ArrayList<T>::MergerSort()
{
	T* tmpArray = new T[mIndex] ;
	MergerSort_T(mArray,tmpArray,0,mIndex-1) ;
	delete[] tmpArray ;
}
#endif
