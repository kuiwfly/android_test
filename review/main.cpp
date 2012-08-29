#include <iostream>
#include "ArrayList.h"
using namespace std ;
int main()
{
	cout<<"hello world!"<<endl ;
//*
	ArrayList<int> arrayList ;
	for(int i=0;i<20;i++) {
		arrayList.Append(i) ;
	}
	arrayList.Print() ;
//*/
	return 0 ;
}
