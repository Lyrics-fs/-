#include"head.h"

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

TreePosition Find(int X, SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}

	if (X < T->Element)
	{
		return Find(X, T->Left);
	}
	else if (X > T->Element)
	{
		return Find(X, T->Right);
	}
	else
	{
		return T;
	}
}

TreePosition FindMin(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Left == NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->Left);
	}
}

TreePosition FindMax(SearchTree T)
{
	if (T != NULL)
	{
		while (T->Right != NULL)
		{
			T = T->Right;
		}
	}
	return T;
}

SearchTree Insert(int X, SearchTree T)
{
	if (T == NULL)
	{
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if (T == NULL)
		{
			FatalError("Out if space!!!");
		}
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
	}

	return T;
}

SearchTree Delete(int X, SearchTree T)
{
	TreePosition TmpCell;
	if (T == NULL)
	{
		perror("Element not found");
	}
	else if (X < T->Element)
	{
		T->Left = Delete(X, T->Left);
	}
	else if (X > T->Element)
	{
		T->Right = Delete(X, T->Right);
	}
	else if (T->Left && T->Right)
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		TmpCell = T;
		if (T->Left == NULL)
		{
			T = T->Right;
		}
		else if (T->Right == NULL)
		{
			T = T->Left;
		}
		free(TmpCell);
	}
	return T;
}

void PreOrderPrint(SearchTree T)
{
	if (T == NULL)
	{
		return;
	}
	cout << T->Element << " ";
	PreOrderPrint(T->Left);
	PreOrderPrint(T->Right);
}

void InOrderPrint(SearchTree T)
{
	if (T == NULL)
	{
		return;
	}
	InOrderPrint(T->Left);
	cout << T->Element << " ";
	InOrderPrint(T->Right);
}
 
void PosOrderPrint(SearchTree T)
{
	if (T == NULL)
	{
		return;
	}
	PosOrderPrint(T->Left);
	PosOrderPrint(T->Right);
	cout << T->Element << " ";
}

