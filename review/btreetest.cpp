#include <iostream>
using namespace std ;
template<typename T>
struct BTreeNode{
	BTreeNode<T> *mLeft ;
	BTreeNode<T> *mRight ;
	BTreeNode<T> *mParent ;
	T mData ;
	BTreeNode(BTreeNode<T> *pLeft=NULL, BTreeNode<T> *pRight=NULL, BTreeNode<T> *pParent=NULL,T data=0):mLeft(pLeft),mRight(pRight),mParent(pParent),mData(data){} ;
};
template <class T>
BTreeNode<T> *CreateBTree(T *data, int len){
	BTreeNode<T> *pParent = new BTreeNode<T> ;
	
	return pParent ;
}
	
int main()
{
	int data[]={20,12 ,32, 45, 24, 47,90,87,23} ;
	int len = sizeof(data)/sizeof(data[0]) ;
	BTreeNode<int> *pTree = new BTreeNode<int> ;
	pTree->mData = 20 ;
	delete pTree ;
	cout<<"hello world!"<<endl ;
}
