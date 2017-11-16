int value[5]＝｛6，3，5，4，6｝；
int weight[5]＝｛2，2，6，5，4｝；



#include <stdio.h>
 int list[200][200];
 int x[15];
 int n;
 int c;
 int s;
int max (int a,int b)
{
   if(a>b)return a;
   else return b;
}

int ks(int n,int weight[],int value[],int x[],int c)
{
  int i,j;
  for(i=0;i<=n;i++)
   list[i][0]=0;
  for(j=0;j<=c;j++)
   list[0][i]=0;
  for(i=0;i<=n-1;i++)
  for(j=0;j<=c;j++)
   if(j<weight[i])
    list[i][j]=list[i-1][j];
   else
    list[i][j]=max(list[i-1][j],list[i-1][j-weight[i]]+value[i]);
   j=c;
   for(i=n-1;i>=0;i--){
    if(list[i][j]>list[i-1][j]){
    x[i]=1;
    j=j-weight[i];
    }else x[i]=0;
   }

printf("背包中的物品序列号:\n");
   for(i=0;i<n;i++)
       printf("%d\n",x[i]);

return list[n-1][c];     } 
void main(){
 int weight[15]={2,2,6,5,4};
 int value[15]={6,3,5,4,6};

c=10;
 n=5;
   
   s=ks(n,weight,value,x,c);

printf("背包中的总价值:\n");
   printf("%d\n",s);

}
投资
#include<stdio.h>
void Investing(int m,int n,int g[100][100]); 
int main(){
	int i,j,n,m,g[100][100]={0};
	printf("请输入要录入的行数与列数（空格隔开） ："); 
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		printf("项目%d投资利润表：",i) ;
		for(j=1;j<=m;j++){
			scanf("%d",&g[i][j]);
		}
	}
	Investing(m,n,g); 
	return 0;
}

void Investing(int m,int n,int g[100][100]){
	int i,j,k,s;
	int h[n+1],d[n+1][m+1];
 	for (i=2; i<=n; i=i+1){
 		for(j=0; j<=m; j=j+1)  
		d[1][j]=j;
		for(j=0; j<=m; j=j+1){
	  		h[j]=0;
      		for( k=0; k<=j; k=k+1){
	   			s=g[i-1][k]+g[i][j-k];
        		if(s>h[j]) {
        			h[j]=s;
            		d[i][j]=j-k;
           		}
    		}
    	}
   		for(j=0; j<=m; j=j+1)  g[i][j]=h[j];
 	}
	s=m;
	h[n]=d[n][m];
	for (k=n-1; k>0; k=k-1)
	{   s=s-h[k+1];
		h[k]=d[k][s];
	}
    for(k=1; k<=n; k=k+1) 
	printf("项目%d：投资额：%d\n",k,h[k]) ;
	printf("可获得最大利润额：%d\n",g[n][m]);
}
吾问无为谓
#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN], int b[][MAXLEN])
{
    int i, j;
    
    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    for(j = 1; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i<= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = -1;
            }
        }
    }
}

void PrintLCS(int b[][MAXLEN], char *x, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 0)
    {
        PrintLCS(b, x, i-1, j-1);
        printf("%c ", x[i-1]);
    }
    else if(b[i][j] == 1)
        PrintLCS(b, x, i-1, j);
    else
        PrintLCS(b, x, i, j-1);
}

int main(int argc, char **argv)
{
    char x[MAXLEN] = {"ABCBDAB"};
    char y[MAXLEN] = {"BDCABA"};
    int b[MAXLEN][MAXLEN];
    int c[MAXLEN][MAXLEN];
    int m, n;
    
    m = strlen(x);
    n = strlen(y);
    
    LCSLength(x, y, m, n, c, b);
    PrintLCS(b, x, m, n);
    
    return 0;
}
