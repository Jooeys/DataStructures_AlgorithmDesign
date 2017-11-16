#include "head.h"
#include<malloc.h>
#include<stdio.h>
main()
{
	int n,m;
	JoseList L;
	printf("请输入约瑟夫环大小和计数单位（n,m）");
	scanf("%d,%d", &n, &m);
	createJoseList(L,n);
	printJose(L,n, m);
}