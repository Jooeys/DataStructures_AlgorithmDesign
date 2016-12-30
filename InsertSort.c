/*
Title:Insert Sort 
author:ZhongJunyi
Date:2016/12/04
*/
#include<stdio.h>
#include<stdio.h>

int main()
{ 
	int i,j,insert;
	int a[6] = {4,1,15,3,6,9};
	printf("Before sort:\n");
	for (i=0;i<6;i++)
	printf("%d,",a[i]);
	printf("\n");
	for (j=1;i<6;j++)
	{
		insert = a[j];
		for (i=j-1;i>=0 && a[i]>insert;i--)
		{
			//all num move to right
			a[i+1] = a[i];
		 } 
		 a[i+1] = insert;
	}
	printf("After sort:\n");
	for(i=0;i<6;i++)
	printf("%d,",a[i]);
	printf("\n");
	//system("pause") 
}
