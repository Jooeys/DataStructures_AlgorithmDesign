 /* main6-3.c ����bo6-3.c�������� */
 #define CHAR 1 /* �ַ��� */
 /*#define CHAR 0 /* ����(����ѡһ) */
 #if CHAR
   typedef char TElemType;
   TElemType Nil=' '; /* �ַ����Կո��Ϊ�� */
 #else
   typedef int TElemType;
   TElemType Nil=0; /* ������0Ϊ�� */
 #endif
 #include"c1.h"
 #include"c6-3.h"
 #include"bo6-3.c"

 Status vi(TElemType c)
 {
 #if CHAR
   printf("%c ",c);
 #else
   printf("%d ",c);
 #endif
   return OK;
 }

 void main()
 {
   BiThrTree H,T;
 #if CHAR
   printf("�밴�������������(��:ab�����ո��ʾaΪ�����,bΪ�������Ķ�����)\n");
 #else
   printf("�밴�������������(��:1 2 0 0 0��ʾ1Ϊ�����,2Ϊ�������Ķ�����)\n");
 #endif
   CreateBiThrTree(&T); /* ��������������� */
   InOrderThreading(&H,T); /* ��������������������������� */
   printf("�������(���)����������:\n");
   InOrderTraverse_Thr(H,vi); /* �������(���)���������� */
   printf("\n");
 }