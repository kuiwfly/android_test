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
void ArrayList<T>::QuickSort()
{
}
template <class T>
void ArrayList<T>::ShellSort()
{
}
