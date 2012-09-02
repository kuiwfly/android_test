#include "SinglyLinkList.h"
void TestSinglyLink()
{
    int a[]={5,4,3,2,1} ;
    SinglyLinkNode *pHead=CreateLinkList(a,sizeof(a)/sizeof(a[0]));
    printf("Origin Link List:\n");
    PrintLinkList(pHead);
    pHead=ReverseLinkList(pHead);
    printf("Reverse Link List:\n");
    PrintLinkList(pHead);

    pHead=InsertNewNode(pHead,0,20) ;
    pHead=InsertNewNode(pHead,2,10) ;
    pHead=InsertNewNode(pHead,7,30) ;
    printf("Inser New Node:\n");
    PrintLinkList(pHead);

    printf("Origin Order:\n");
    PrintLinkNode(pHead) ;
    printf("Bubble Sort Process:\n");
    //pHead=BubbleSort(pHead);
    //pHead=SelectSort(pHead);
    pHead=InsertSort(pHead);
    printf("Bubble Sort Result:\n");
    PrintLinkNode(pHead);

    pHead=RemoveNode(pHead,0) ;
    pHead=RemoveNode(pHead,1) ;
    pHead=RemoveNode(pHead,5);
    printf("Remove Node:\n");
    PrintLinkList(pHead);



    printf("Delete Link List:\n");
    DeleteLinkList(pHead);
}
SinglyLinkNode *CreateLinkList(int *data,int len)
{
    SinglyLinkNode *pHead=(SinglyLinkNode*)malloc(sizeof(SinglyLinkNode));
    SinglyLinkNode *pTmp=pHead ;
    int i=0 ;
    if(pHead==NULL)
    {
        return NULL ;
    }

    for(i=0;i<len-1;i++)
    {
        pTmp->value=data[i];
        pTmp->next=(SinglyLinkNode*)malloc(sizeof(SinglyLinkNode));
        pTmp=pTmp->next ;
    }
    pTmp->value=data[len-1] ;
    pTmp->next=NULL;
    return pHead ;
}
void DeleteLinkList(SinglyLinkNode *pHead)
{
    SinglyLinkNode *pTmp=pHead ;
    SinglyLinkNode *pOld=pTmp ;
    while(pTmp!=NULL)
    {
        pOld=pTmp ;
        pTmp=pTmp->next ;
        printf("delete node:%d\n",pOld->value);
        free(pOld);
    }
    pHead=NULL ;
}
void PrintLinkList(SinglyLinkNode *pHead)
{
    SinglyLinkNode *pTmp =pHead ;
    do
    {
        printf("NODE:%d\n",pTmp->value) ;
        pTmp=pTmp->next ;
    }while(pTmp!=NULL) ;
}
void PrintLinkNode(SinglyLinkNode *pHead)
{
    SinglyLinkNode *pTmp=pHead ;
    printf("Nodes:") ;
    do
    {
        printf("%d,",pTmp->value) ;
        pTmp=pTmp->next ;
    }while(pTmp!=NULL) ;
    printf("\n");
}
SinglyLinkNode *ReverseLinkList(SinglyLinkNode *pHead)
{
    SinglyLinkNode *pTmp=pHead ;
    if(pTmp==NULL)
    {
        return NULL ;
    }
    SinglyLinkNode *pTmp1=pTmp->next ;
    if(pTmp1==NULL)
    {
        return pHead ;
    }
    SinglyLinkNode *pTmp2=pTmp1->next ;
    pTmp->next=NULL ;
    pTmp1->next=pTmp ;
    if(pTmp2==NULL)
    {
        return pTmp1 ;
    }
    while(pTmp2->next!=NULL)
    {
        pTmp=pTmp1 ;
        pTmp1=pTmp2 ;
        pTmp2=pTmp2->next ;
        pTmp1->next=pTmp ;
    }
    pTmp2->next=pTmp1 ;

    return pTmp2 ;
}
SinglyLinkNode *InsertNewNode(SinglyLinkNode *pHead, int pos, int value)
{
    SinglyLinkNode *pTmp=pHead ;
    SinglyLinkNode *pTmp1=pTmp->next ;
    SinglyLinkNode *pTmp2=NULL ;

    if(pos==0)
    {
        pTmp2=(SinglyLinkNode*)malloc(sizeof(SinglyLinkNode));
        pTmp2->value=value ;
        pTmp2->next=pHead ;
        return pTmp2 ;
    }
    int i=1 ;
    while(pTmp1!=NULL)
    {
        if(i==pos)
        {
            pTmp->next=(SinglyLinkNode*)malloc(sizeof(SinglyLinkNode));
            pTmp->next->value=value ;
            pTmp->next->next=pTmp1 ;
            break ;
        }
        i++ ;
        pTmp=pTmp1 ;
        pTmp1=pTmp1->next ;
    }
    if(pTmp1==NULL)
    {
        pTmp->next=(SinglyLinkNode*)malloc(sizeof(SinglyLinkNode));
        pTmp->next->value=value ;
        pTmp->next->next=pTmp1 ;
    }
    return pHead ;
}
SinglyLinkNode *RemoveNode(SinglyLinkNode *pHead,int pos)
{
    SinglyLinkNode *pTmp=pHead ;
    SinglyLinkNode *pTmp1=pTmp->next ;
    if(pos==0)
    {
        free(pTmp) ;
        return pTmp1 ;
    }
    int i=1 ;
    while(pTmp1!=NULL)
    {
        pTmp1=pTmp1->next ;
        if(i==pos)
        {
            free(pTmp->next);
            pTmp->next=pTmp1 ;
            break ;
        }
        pTmp=pTmp->next ;
        i++ ;
    }
    return pHead ;
}
SinglyLinkNode *BubbleSort(SinglyLinkNode *pHead)
{
    SinglyLinkNode *pTmp=(SinglyLinkNode*)malloc(sizeof(SinglyLinkNode));//create a new node as a constant head node
    SinglyLinkNode *pTmp1=NULL ;
    SinglyLinkNode *pTmp2=NULL ;
    SinglyLinkNode *pTmp3=NULL ;
    SinglyLinkNode *pEnd=NULL ;

    pTmp->next=pHead ;
    while(pEnd!=pTmp->next)
    {
        pTmp3=pTmp ;
        pTmp2=pTmp3->next ;
        if(pTmp2==NULL)
        {//if only one node ,return directly
            break ;
        }
        pTmp1=pTmp2->next ;
        while(pTmp1!=pEnd)
        {
            if(pTmp1->value>pTmp2->value)
            {
                pTmp2->next=pTmp1->next ;
                pTmp3->next=pTmp1 ;
                pTmp1->next=pTmp2 ;
            }
            pTmp3=pTmp3->next ;
            pTmp2=pTmp3->next ;
            pTmp1=pTmp2->next ;
        }

        if(pEnd==NULL)
        {
            pTmp2->next=NULL ;
        }
        PrintLinkNode(pTmp->next) ;
        pEnd=pTmp2 ;
    }
    pHead=pTmp->next ;
    free(pTmp) ;
    return pHead ;
}
SinglyLinkNode *SelectSort(SinglyLinkNode *pHead)
{
    SinglyLinkNode *pTmp=(SinglyLinkNode *)malloc(sizeof(SinglyLinkNode));

    SinglyLinkNode *pMaxBefore=NULL ;
    SinglyLinkNode *pEnd=NULL ;
    SinglyLinkNode *pTmp1=NULL ;
    SinglyLinkNode *pTmp2=NULL ;

    pTmp->next=pHead ;
    pEnd=pTmp ;
    while(pEnd->next!=NULL)
    {
        pMaxBefore=pEnd ;
        pTmp1=pEnd ;

        while(pTmp1->next!=NULL)
        {
            if(pMaxBefore->next->value<pTmp1->next->value)
            {
                pMaxBefore=pTmp1 ;
            }
            pTmp1=pTmp1->next ;
        }

        pTmp2=pMaxBefore->next ;
        pMaxBefore->next=pTmp2->next ;
        pTmp2->next =pEnd->next ;
        pEnd->next=pTmp2 ;
        pEnd=pEnd->next ;
        PrintLinkNode(pTmp->next);
    }
    pHead=pTmp->next ;
    free(pTmp) ;
    return pHead ;
}

SinglyLinkNode *InsertSort(SinglyLinkNode *pHead)
{
    SinglyLinkNode *pTmp=(SinglyLinkNode*)malloc(sizeof(SinglyLinkNode)) ;
    SinglyLinkNode *pEnd=NULL ;
    SinglyLinkNode *pTmp1=NULL ;
    SinglyLinkNode *pTmp2=NULL ;
    pTmp->next=pHead ;
    pEnd=pTmp ;
    while(pEnd->next!=NULL)
    {
        pTmp1=pTmp ;
        while(pTmp1->next!=pEnd->next)
        {
            if(pTmp1->next->value<pEnd->next->value)
            {//if the value of pEnd node bigger than the value of pTmp1 node ,insert it
                pTmp2=pEnd->next ;
                pEnd->next=pTmp2->next ;
                pTmp2->next=pTmp1->next ;
                pTmp1->next=pTmp2 ;
                break ;
            }
            pTmp1=pTmp1->next ;
        }
        PrintLinkNode(pTmp->next);
        if(pTmp1->next==pEnd->next)
        {//if not find bigger, insert the pEnd node to the tail
            pEnd=pEnd->next ;
        }
    }
    pHead=pTmp->next ;
    free(pTmp) ;
    return pHead ;
}
