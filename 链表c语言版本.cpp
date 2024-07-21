#include"head.h"

//测试链表是否为空
int IsEmpty(List L)
{
	return L->Next == NULL;
}
//测试位置是否为末尾
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
//查找函数
Position Find(int X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	return P;
}
//删除函数
void Delete(int X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}
//查找要删除的元素的上一个节点
Position FindPrevious(int X, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}
//错误返回
void FatalError(const char* message) 
{
	fprintf(stderr, "Fatal Error: %s\n", message);
	exit(EXIT_FAILURE);
}
//插入函数
void Insert(int X, List L, Position P)
{
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
	{
		FatalError("Out of space!!!");
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
//删除函数
void DeleteList(List L)
{
	Position P, Tmp;
	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}
