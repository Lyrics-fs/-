#include"��ͷ.h"

//���������Ƿ�Ϊ��
int IsEmpty(List L)
{
	return L->Next == NULL;
}
//����λ���Ƿ�Ϊĩβ
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
//���Һ���
Position Find(int X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	return P;
}
//ɾ������
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
//����Ҫɾ����Ԫ�ص���һ���ڵ�
Position FindPrevious(int X, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}
//���󷵻�
void FatalError(const char* message) 
{
	fprintf(stderr, "Fatal Error: %s\n", message);
	exit(EXIT_FAILURE);
}
//���뺯��
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
//ɾ������
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