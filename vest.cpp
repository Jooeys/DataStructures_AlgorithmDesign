#include<stdio.h> 
int main() 
{ 
     void jie(int,int,int d[][9]);
     void Invest(int m,int n,int f[][9],int g[][9],int d[][9]);
     int m=8,n=3,f[4][9],d[4][9];
     int g[4][9]={{0},{0,5,15,40,80,90,95,98,100},{0,5,15,40,60,70,73,74,75},{0,4,26,40,45,50,51,53,53}}; 
     Invest(m,n,f,g,d);
     printf("可获得的最大收益为：%d\n",f[3][8]); 
     jie(m,n,d);
}
void Invest(int m,int n,int f[][9],int g[][9],int d[][9])
{
     int i,j,k,s; 
     for(j=0;j<=m;j++) 
	 { 
        f[1][j]=g[1][j];d[1][j]=j;  }
        for(i=2;i<=n;i++) 
            for(j=0;j<=m;j++) 
			{ 
                f[i][j]=0; 
                for(k=0;k<=j;k++) 
				{
                    s=f[i-1][j-k]+g[i][k]; 
                    if(s>f[i][j]) 
					{ 
                       f[i][j]=s; 
                       d[i][j]=k; 
					} 
				} 
			} 
} 
void jie(int m,int n,int d[][9]){ 
     int s=m; 
     int k[4]; 
     int i; 
     k[n]=d[n][m]; 
     for(i=n-1;i>0;i--) 
	 {     
         s = s-k[i+1]; 
         k[i] = d[i][s]; 
	 }  
     for(i=1;i<=3;i++) 
    printf("%5d",k[i]);  
printf("\n");
}

