#include "head.h"
#include<malloc.h>
#include<stdio.h>


//建立不带头结点的循环链表
Status createJoseList(JoseList &L, int n)
{
	int i;
	LNode* hp;

	hp = (LNode*)malloc(sizeof(LNode));

	L = hp;

	for(i=1; i<n; i++)
	{	
		hp->data = i;
		hp->next = (LNode*)malloc(sizeof(LNode));
		hp = hp->next ;		
	}
	hp->data = n;
	hp->next = L;

	return OK;
}

//按照隔m报数一次的规则输出约瑟夫环解序列
Status printJose(JoseList L, int n, int m)
{
	int i = 0, j;
	LNode *p ,*hp = L  ;

	p=hp;
	for(i = 1; i <= n; i++)
	{  
		for(j = 1; j < m; j++) 
		{
			hp = p;
			p = p->next;  
		}  
		printf("%d\t",p->data );  
		hp->next = p->next ;
		free(p);		
		p=hp->next ;
	}  
	printf("\n");
	return OK;
	
}