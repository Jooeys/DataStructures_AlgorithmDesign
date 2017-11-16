/*输入一个4位自然数，调用函数输出该自然数数字组成的最大数*/
#include"stdio.h" 
void fun(int a)
{
	int i,j,buf,x[4];
	for (i=0;i<4;i++)
{
	x[i]=a%10;
	a/=10;//除等于得十位 
}
	for (i=0;i<4;i++)// 外部循环 
{
	for (j=0;j<3;j++)
{
	if (x[j]>x[j+1])// 
{
	buf = x[j+1];
	x[j+1] = x[j];
	x[j] = buf;
}
}
	printf("%d",x[3]);
	x[3] = -1;
}
	printf("\n");
}
	int main() 
{ 
	int a;
	scanf("%d",&a); 
	fun(a);
}
