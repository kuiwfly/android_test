#ifndef _CSINGLYLIST_H
#define _CSINGLYLIST_H
#include <iostream>

#ifndef BOOL_SUPPORT
#define BOOL_SUPPORT
typedef   enum   boolean { TRUE,FALSE } BOOL;
#endif
using namespace std ;

template <class T>
struct SinglyListNode
{
    T value ;
    struct SinglyListNode<T> *next ;
    SinglyListNode()
    {
        next=NULL ;
    }
}  ;

template <class T>
class SinglyList
{
public:
    SinglyList() ;
    ~SinglyList() ;
    BOOL Insert(T &t, int pos);
    BOOL Remove(int pos) ;
    void RemoveAll() ;

    void BubbleSort() ;
    void SelectSort() ;
    void InsertSort() ;
    void ReverseList() ;
    int GetLength() const;
    void PrintList() const;

private:
    SinglyListNode<T> *pHead ;
};
template<class T>
SinglyList<T>::SinglyList()
{
    pHead=new SinglyListNode<T>();
}
template<class T>
SinglyList<T>::~SinglyList()
{
    RemoveAll() ;//don't forget clear all node that insert before
    delete pHead ;
}

template<class T>
BOOL SinglyList<T>::Insert(T &t,int pos)
{
    if(pos<=0)
    {
        return FALSE ;
    }
    int i=0 ;
    SinglyListNode<T> *pTmp=pHead ;
    SinglyListNode<T> *pTmp1=NULL ;
    while(pTmp->next!=NULL)
    {
        i++ ;
        if(i==pos)
        {
            pTmp1=pTmp->next ;
            pTmp->next=new SinglyListNode<T>() ;
            pTmp->next->next=pTmp1 ;
            pTmp->next->value=t ;
            break ;
        }
        pTmp=pTmp->next ;
    }
    if(pTmp->next==NULL)
    {
        pTmp->next=new SinglyListNode<T>();
        pTmp->next->value=t ;
        pTmp->next->next=NULL ;
    }
    return TRUE ;
}
template <class T>
BOOL SinglyList<T>::Remove(int pos)
{
    if(pos<=0)
    {
        return FALSE ;
    }
    int i=0 ;
    SinglyListNode<T> *pTmp=pHead ;
    SinglyListNode<T> *pTmp1=NULL ;
    while(pTmp->next!=NULL)
    {
        i++ ;
        if(i==pos)
        {
            pTmp1=pTmp->next ;
            pTmp->next=pTmp1->next ;
            delete pTmp1 ;
            break ;
        }
        pTmp=pTmp->next ;
    }
    return TRUE ;
}
template <class T>
void SinglyList<T>::RemoveAll()
{
    SinglyListNode<T> *pTmp=pHead ;
    SinglyListNode<T> *pTmp1=NULL ;
    while(pTmp->next!=NULL)
    {
        pTmp1=pTmp->next ;
        pTmp->next=pTmp1->next ;
        delete pTmp1 ;
    }
}
template <class T>
void SinglyList<T>::BubbleSort()
{
    SinglyListNode<T> *pEnd=NULL ;
    SinglyListNode<T> *pTmp=pHead->next ;
    SinglyListNode<T> *pTmp1=NULL ;
    while(pEnd!=pHead->next)
    {
        pTmp=pHead ;
        if(pTmp->next==NULL||pTmp->next->next==NULL)
        {
            break ;
        }
        while(pTmp->next->next!=pEnd)
        {
            if(pTmp->next->value>pTmp->next->next->value)
            {
                pTmp1=pTmp->next->next ;
                pTmp->next->next=pTmp1->next ;
                pTmp1->next=pTmp->next ;
                pTmp->next=pTmp1 ;
            }
            pTmp=pTmp->next ;
        }
        PrintList();//print sort process
        pEnd=pTmp->next ;
    }
}
template <class T>
void SinglyList<T>::SelectSort()
{

}
template <class T>
void SinglyList<T>::InsertSort()
{

}
template <class T>
void SinglyList<T>::ReverseList()
{
    SinglyListNode<T> *pTmp=pHead ;
    SinglyListNode<T> *pTmp1=NULL ;
    SinglyListNode<T> *pTmp2=NULL ;
    if(pTmp->next==NULL||pTmp->next->next==NULL)
    {
        return ;
    }
    pTmp1=pTmp->next ;
    pTmp2=pTmp1->next ;

    pTmp2->next=pTmp1 ;
    pTmp->next=pTmp2 ;
    pTmp1->next=NULL ;

    while(pTmp2!=NULL)
    {

    }


}
template <class T>
void SinglyList<T>::PrintList() const
{
    SinglyListNode<T> *pTmp=pHead->next ;
    cout<<"NODES:" ;
    while(pTmp!=NULL)
    {
        cout<<pTmp->value<<',' ;
        pTmp=pTmp->next ;
    }
    cout<<'\n' ;
}
#endif
