#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int a[MAX][MAX];

int main() {
	int n,x,y,nowNum=0;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	x = 0,y = 0;
	nowNum = a[x][y] = 1;
	while(nowNum < n*n) {
		while(y+1<n && !a[x][y+1])  a[x][++y] = ++nowNum;
		while(x+1<n && !a[x+1][y])  a[++x][y] = ++nowNum;
		while(y-1>=0 && !a[x][y-1]) a[x][--y] = ++nowNum;
		while(x-1>=0 && !a[x-1][y]) a[--x][y] = ++nowNum;
	}
	for(x=0; x<n; x++) {
		for(y=0; y<n; y++)
			printf("%4d",a[x][y]);
		printf("\n");
	}
	printf("\n\n");
	system("pause");
	return 0;
} 
