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
	
	void Print() const ;
	
	void BubbleSort() ;
	void SelectSort() ;
	void InsertSort() ;
	void QuickSort() ;
private:
	T *mArray ;
	int mIndex ;
	int mLength ;
};
template <class T>
ArrayList<T>::ArrayList()
{
	mArray = NULL ;
	mIndex = 0 ;
	mLength = 0 ;
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
		
	}	
	mArray[++mIndex] = elem ;
	return true ;
}

