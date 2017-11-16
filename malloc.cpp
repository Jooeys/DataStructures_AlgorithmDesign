#include <stdio.h>
#include <malloc.h>
 int main()
 {
 	int a[5]={4,10,2,8,6};
 	int len;
 	printf("请输入你需要分配数组的长度：len=");
 	scanf("%d",len);
 	int *pArr=(int *)malloc(sizeof(int)* len);
	 *pArr = 4;//类似于a[0]=4
	 pArr[1]=10;//类似于a[1]=10
	 printf("%d %d\n",*pArr,pArr[1]);
	 
	 //把pArr当作一个普通数组来使用
	 int i;
	 for (int i=0;i<len;i++)
	 scanf("%d",&pArr[i]);
	 
	 for(i=0; i<len; ++i)
	 printf("%d\n",*(pArr+i)); 
	 
	 free(pArr);
	 return 0;
	 
 };
 