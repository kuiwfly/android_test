#ifndef _BTREE_H
#define _BTREE_H
#include <iostream>
#include <string.h>
#include <deque>
using namespace std ;
template <class DataType>
struct BTreeNode {
	DataType mData ;
	BTreeNode<DataType> *mLeft ;
	BTreeNode<DataType> *mRight ;
	BTreeNode<DataType> *mParent ;
	BTreeNode(BTreeNode<DataType> *pParent=NULL ,
			BTreeNode<DataType> *pLeft = NULL ,
			BTreeNode<DataType> *pRight = NULL ,
			DataType &data) ;
		
} ;
BTreeNode::BTreeNode(BTreeNode<DataType> *pParent=NULL, 
		BTreeNode<DataType>* pLeft=NULL,
		BTreeNOde<DatatType>* pRight=NULL ,
		DataType &data):
		mParent(pParent),
		mLeft(pLeft),
		mRight(pRight),
		mData(data) 
{
	;
}
template <class DataType>
class BTree{
public :
	BTree() ;
	BTree(DataType *data, int len) ;
	~BTree() ;
	
	void PreOrder() const ;
	void PostOrder() const ;
	void MidOrder() const ;
	bool bRecursive ;
private :
	/*create or destroy btree*/
	BTreeNode<DataType> *CreateBTreeRecursive(DataType *data, int index, int len) ;
	BTreeNode<DataType> *CreateBTreeNonRecursive(DataType *data , int len) ;
	void DestroyBTreeRecursive(BTreeNode<DataType> *root,int index) ;
	void DestroyBTreeRecursive(BTreeNode<DataType> *root) ;
	
	/*traverse btree*/
	void PreOrderRecursive(BTreeNode<DataType> *pRoot) ;
	void PreOrderNonRecursive(BTreeNode<DataType> *pRoot) ;
	void PostOrderRecursive(BTreeNode<DataType> *pRoot) ;
	void PostOrderNonRecursive(BTreeNode<DataType> *pRoot) ;
	void MidOrderRecursive(BTreeNode<DataType> *pRoot) ;
	void MidOrderNonRecursive(BTreeNode<DataType> *pRoot) ;

	void Print(BTreeNode<DataType> *pRoot) const ;
	
	BTreeNode<DataType> *mRoot ;
} ;
template <class DataType>
BTree<DataType>::BTree() 
{
	mRoot = NULL ;
}

template <class DataType>
BTree<DataType>::BTree(DataType *data, int len)
{
	if(bRecursive){
		mRoot = CreateBTreeRecursive(data,0,len) ;
	}else{
		mRoot = CreateBTreeNonRecursive(data, len) ;	
	}
}
template <class DataType>
BTree<DataType>::~BTree()
{
	if(mRoot!=NULL){
		if(bRecursive){
			DestroyBTreeRecursive(mRoot) ;
		}else{
			DestroyBtreeNonRecursive(mRoot) ;
		}
	}
}
template <class DataType>
void  BTree<DataType>::PreOrder() const 
{
	if(bRecursive){
		PreOrderRecursive(mRoot,0) ;		
	}else{
		PreOrderNonRecursive(mRoot) ;
	}
}

template <class DataType>
void BTree<DataType>::PostOrder() const
{
	if(bRecursive){
		PostOrderRecursive(mRoot,0) ;
	}else{
		PostOrderNonRecursive(mRoot) ;
	}
}
template <class DataType>
void BTree<DataType::MidOrder() const
{
	if(bRecursive){
		MidOrderRecursive(mRoot,0) ;
	}else{
		MidOrderNonRecursive(mRoot) ;
	}
}
template <class DataType>
BTreeNode<DataType> * BTree::CreateBTreeRecursive(DataType *data, int index, int len) 
{
	if(index>=len){
		return NULL ;
	}
	BTreeNode *pRoot = new BTreeNode(data[index]) ;
	pRoot->mLeft = CreateBTreeRecursive(data,index*2+1,len) ;
	pRoot->mRight = CreateBTreeRecursive(data,index*2+2,len) ;
	pRoot->mLeft->mParent = pRoot ;
	pRoot->mRight->mParent = pRoot ;

	return pRoot ;
}
template <class DataType>
BTreeNode <DataType> *BTree<DataType>::CreateBTreeNonRecursive(DataType *data, int len)
{
	BTreeNode *pRoot = new BTreeNode(data[0]) ;
	int index = 0 ;

	/*two stacks,one is for node and the other is for index*/
	deque<DataType> tmpStack  ;
	deque<int> indexStack ;

	tmpStack.push_front(pRoot) ;
	indexStack.push_front(index) ;

	BTreeNode *tmpNode = NULL ;
	while(!tmpStack.empty()){
		tmpNode = tmpStack.pop_front() ;	
		index = indexStack.pop_front() ;

		if(2*index+1<len){
			tmpNode->mLeft = new BTreeNode(data[2*index+1]) ;
			tmpStack.push_front(tmpNode->mLeft) ;
			indexStack.push_front(2*index+1) ;
		}else{
			tmpNode->mLeft = NULL ;
		}

		if(2*index+2<len){
			tmpNode->mRight = new BTreeNode(data[2*index+2]) ;
			tmpStack.push_front(tmpNode->mRight) ;
			indexStack.push_front(2*index+1) ;
		}else{
			tmpNode->mRight = NULL ;
		}
	}
	return pRoot ;
}
template <class DataType>
void BTree<DataType>::PreOrderRecursive(BTreeNode<DataType> *pRoot)
{
	if(pRoot!=NULL){
		Print(pRoot) ;
		PreOrderRecursive(pRoot->mLeft) ;
		PreOrderRecursive(pRoot->mRight) ;
	}
}
template <class DataType>
void BTree<DataType>::PreOrderNonRecursive(BTreeNode<DataType> *pRoot)
{

}
#endif 
