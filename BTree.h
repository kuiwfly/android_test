#ifndef _BTREE_H
#define _BTREE_H
#include <iostream>
#include <string.h>
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
#endif 
