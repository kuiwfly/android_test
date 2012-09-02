#ifndef _SINGLYLINKLIST_H
#define _SINGLYLINKLIST_H
#include <stdio.h>
#include <stdlib.h>
#ifndef BOOL_SUPPORT
#define BOOL_SUPPORT
typedef   enum   boolean { TRUE,FALSE } BOOL;
#endif
typedef struct _singly_link_node {
    int value ;
    struct _singly_link_node *next ;
}SinglyLinkNode ;

SinglyLinkNode *CreateLinkList(int* a,int len) ;
SinglyLinkNode *InsertNewNode(SinglyLinkNode *pHead,int pos,int data);
SinglyLinkNode *RemoveNode(SinglyLinkNode *pHead,int pos);

void DeleteLinkList(SinglyLinkNode *pHead);
SinglyLinkNode *ReverseLinkList(SinglyLinkNode *pHead);
SinglyLinkNode *BubbleSort(SinglyLinkNode *pHead);
SinglyLinkNode *SelectSort(SinglyLinkNode *pHead) ;
SinglyLinkNode *InsertSort(SinglyLinkNode *pHead);
void PrintLinkList(SinglyLinkNode *pHead);
void PrintLinkNode(SinglyLinkNode *pHead);
void TestSinglyLink() ;
#endif
