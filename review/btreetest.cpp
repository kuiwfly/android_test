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
	BTreeNode<T> *pParent = NULL ;
	int i = 0 ;
	for(i=0 ; i<len ; i++){
		InsertNode(&pParent,data[i],pParent) ;
	}
	
	return pParent ;
}
template <class T>
int InsertNode(BTreeNode<T> **pParent,T data,BTreeNode<T> *parent){
/*note: the parameter of this function is double pointer and
the priority of "->" operator is lower than "*" operator */

	if(*pParent == NULL){
		*pParent = new BTreeNode<T> ;
		(*pParent)->mData = data ;
		(*pParent)->mParent = parent ;
		return 1 ;
	}		
	if((*pParent)->mData > data){
		return InsertNode(&(*pParent)->mLeft,data,*pParent) ;
	}else{
		return InsertNode(&(*pParent)->mRight,data,*pParent) ;
	}
}
template <typename T>
void PreTraverse(BTreeNode<T> *pRoot){
	if(pRoot != NULL){
		cout<<pRoot->mData<<"," ;
		PreTraverse(pRoot->mLeft) ;
		PreTraverse(pRoot->mRight) ;
	}
}
template <typename T>
void MidTraverse(BTreeNode<T> *pRoot){
/*this function can output the values of tree in order 
*/
	if(pRoot != NULL){
		MidTraverse(pRoot->mLeft) ;
		cout<<pRoot->mData<<"," ;
		MidTraverse(pRoot->mRight) ;
	}
}
template <class T>
void PostTraverse(BTreeNode<T> *pRoot){
	if(pRoot != NULL){
		PostTraverse(pRoot->mLeft) ;
		PostTraverse(pRoot->mRight) ;
		cout<<pRoot->mData<<"," ;
	}
}
	
template <class T>
int CalculateNodeNums(BTreeNode<T> *pRoot){
/*Caculate the node numbers of this tree*/
	if(pRoot == NULL){
		return 0 ;
	}
	return 1 + CalculateNodeNums(pRoot->mLeft) + CalculateNodeNums(pRoot->mRight) ;
}
template <class T>
int CalculateHeight(BTreeNode<T> *pRoot){
/*Calculate the height of tree*/
	if(pRoot == NULL){
		return 0 ;
	}
	int leftHeight = CalculateHeight(pRoot->mLeft)+1 ;
	int rightHeight = CalculateHeight(pRoot->mRight)+1 ;
	return leftHeight>rightHeight ? leftHeight : rightHeight ;
}

template <class T>
BTreeNode<T>* IsInBTree(BTreeNode<T> *pRoot, T data){
	if(pRoot==NULL){
		return NULL ;
	}
	if(pRoot->mData == data){
		return pRoot ;
	}	
	if(pRoot->mData > data){
		return IsInBTree(pRoot->mLeft,data) ;
	}else{
		return IsInBTree(pRoot->mRight,data) ;
	}
}
template <typename T>
int DeleteNode(BTreeNode<T> *pRoot, T data){
	if(pRoot == NULL){
		return 0 ;
	}
	BTreeNode<T> *pTmp = IsInBTree(pRoot,data) ;
	if(pTmp == NULL) {
		return 0 ;
	}
	if(pTmp == pRoot){/*if it is root node*/
		
	}
	return 1 ;
}
int main()
{
	int data[]={20,12 ,32, 45, 24, 47,90,87,23} ;
	int len = sizeof(data)/sizeof(data[0]) ;
	BTreeNode<int> *pRoot = CreateBTree(data,len) ;
	PreTraverse(pRoot) ;
	cout<<endl ;
	MidTraverse(pRoot) ;
	cout<<endl ;
	PostTraverse(pRoot) ;
	cout<<endl ;
	cout<<"TreeNodes:"<<CalculateNodeNums(pRoot)<<endl ;
	cout<<"Tree Height:"<<CalculateHeight(pRoot)<<endl ;
	cout<<"Is Node:20 in btree"<<endl ;
	if(IsInBTree(pRoot,20)!=NULL){
		cout<<"YES"<<endl ;
	}else{
		cout<<"NO"<<endl ;
	}
	cout<<"Is Node: 39 in btree"<<endl ;
	if(IsInBTree(pRoot,39)!=NULL){
		cout<<"YES"<<endl ;
	}else{
		cout<<"NO"<<endl ;
	}
}
