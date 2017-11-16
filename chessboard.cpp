#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10000
int board[N][N];//棋盘的布局
int team;//用方块覆盖，相当于分组
int loc;//key(x,y)的方位（返回值为1、2、3、4分别指1、2、3、4象限）
int witk(int m,int x,int y,int a,int b){//where is the key(x,y)?  m为棋盘的边长，x，y为黑点的坐标，a，b为棋盘左上角的坐标，
    int n;
    n=m/2;
    if(x<n+a&&y>=n+b)
        return 1;
    else if(x<n+a&&y<n+b)
        return 2;
    else if(x>=n+a&&y<n+b)
        return 3;
    else if(x>=n+a&&y>=n+b)
        return 4;
}
void cover(int m,int a,int b){
    int i;
    int j;
    int x,y;
    int n;
    if(m==2){//若m==2，直接覆盖
        for(i=a;i<m+a;i++)
            for(j=b;j<m+b;j++)
                if(board[i][j]==-1)
                    board[i][j]=team;
        team++;
    }
    else{//m>2
        for(i=a;i<m+a;i++){//找出黑点的位置x，y
            for(j=b;j<m+b;j++)
                if(board[i][j]!=-1){
                    x=i;
                    y=j;
                }
        }
        n=m/2;
        loc=witk(m,x,y,a,b);//where is the key(x,y)?
        for(i=a+n-1;i<=a+n;i++)//遍历棋盘中部四个格，判断其方位，若不和黑点在同一个方位则将其覆盖；
            for(j=b+n-1;j<=b+n;j++)
                if(witk(m,i,j,a,b)!=loc)
                    board[i][j]=team;
        team++;
        cover(n,a,b);//覆盖四个分区域，递归调用
        cover(n,a,b+n);
        cover(n,a+n,b);
        cover(n,a+n,b+n);
    }
}
int main(){
    int i,j,k;
    int n,m;
    int x,y;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        team=1;
        memset(board,-1,sizeof(board));//将棋盘全部置为-1
        scanf("%d%d%d",&m,&x,&y);
        board[x+1][y+1]=0;
        cover(m,1,1);
        printf("CASE:%d\n",i+1);
        for(j=1;j<=m;j++){
            for(k=1;k<=m;k++)
                printf("%-3d",board[j][k]);
            printf("\n");
        }
    }
    return 0;
}
