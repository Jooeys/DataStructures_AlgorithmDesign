//定义程序中需要的宏
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define LISTINCREMENT 10

//定义程序中用到的数据类型别称
typedef  int Status ;
typedef int ElemType ;

//定义单链表中结点的结构
struct LNode{
	ElemType data;
	struct LNode * next;
};

//对结点及结点指针类型进行重定义，目的是增强程序可读性
typedef struct LNode LNode;
typedef LNode* LinkList;

typedef LinkList JoseList;

Status createJoseList(JoseList &L, int n);
Status printJose(JoseList L, int n, int m);

