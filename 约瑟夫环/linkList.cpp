#include"head.h"
#include<stdlib.h>

Status InitList_L(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL)	exit(OVERFLOW);
	L->next = NULL;
	return OK;
}


int ListLength_L(LinkList L)
{
	LNode *p = L->next ;
	int num = 0;
	while(p != NULL)
	{
		num++;
		p = p->next;
	}
	return num;
}

Status GetElem_L(LinkList L, int i, ElemType &e)
{
	LNode *p = L->next ;
	int j = 1;
	
	while(p != NULL && j<i)
	{
		j++;
		p = p->next ;
	}
	if(p == NULL)	return ERROR;
	else e =  p->data;
	return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e)
{
	LNode *p,*s;
	int j ;

	p=L;	  //p初始指向头结点
	j = 0;     // j表示前结点在表中的位置，初值为0 

	//获得第i-1个元素的地址
	while(p&&j<i-1)	
	{	p=p->next;	j++;	}
	if(!p)	return ERROR;
	//在第i个元素前插入元素e	
	s=(LNode*)malloc(sizeof(LNode));
	s->data=e;	
	s->next=p->next;	p->next=s;
	return  OK;

}
Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
	LNode *p,*q;
	int j ;

	p=L;	  //p初始指向头结点
	j = 0;     // j表示前结点在表中的位置，初值为0 

	//获得第i-1个元素的地址
	while(p &&j<i-1)	
	{	p=p->next;	j++;	}
	if(!p )	return ERROR;

	//删除第i个元素	
	q = p->next ;
	p->next = q->next ;	
	e = q->data ;
	free(q);	
	return  OK;

}	