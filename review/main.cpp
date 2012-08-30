#include <iostream>
#include "ArrayList.h"
#include "LinkList.h"
using namespace std ;
int main()
{
	cout<<"hello world!"<<endl ;
	int array[] = {10,21,32,1,4,3,2,9,10,12,25,23,46,78,29,37,53,48,96,77,38,21,17,11} ;
	int arrayLen = sizeof(array)/sizeof(array[0]) ;
	cout<<"array length:"<<arrayLen<<endl ;
	ArrayList<int> arrayList ;
	for(int i=0 ; i<arrayLen ; i++){
		arrayList.Insert(array[i]) ;
	}
//	arrayList.BubbleSort() ;
//	arrayList.InsertSort() ;
//	arrayList.SelectSort() ;
//	arrayList.QuickSort() ;
//	arrayList.ShellSort() ;
	arrayList.MergerSort() ;
	arrayList.Print() ;
/*
	ArrayList<int> arrayList ;
	for(int i=0;i<20;i++) {
		arrayList.Append(i) ;
	}
	arrayList.Print() ;
//*/
	return 0 ;
}
