#pragma once
#include<cstddef>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include <utility>
#include<random>
#include<ctime>
using namespace std;

void FatalError(const char* message);


struct Node;
typedef struct Node* PtrToNode;
//List是表头，代表整个链表
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int X, List L);
void Delete(int X, List L);
Position FindPrevious(int X, List L);
void Insert(int X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);

struct Node
{
	//ElementType int float ...
	int Element;
	//下一个节点
	Position Next;
};


struct TreeNode;
typedef struct TreeNode* TreePosition;
typedef struct TreeNode* SearchTree;
struct TreeNode
{
	int Element;
	SearchTree Left;
	SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T);
TreePosition Find(int X, SearchTree T);
TreePosition FindMin(SearchTree T);
TreePosition FindMax(SearchTree T);
SearchTree Insert(int X, SearchTree T);
SearchTree Delete(int X, SearchTree T);
int Retrieve(TreePosition P);
void PreOrderPrint(SearchTree T);

void Swap(int* a, int* b);
void generateRandomArray(int MaxSize, int MaxNum, vector<int>& array);
void copyRandomArray(vector<int>& array, vector<int>& NewArray);
bool compareRandomArray(vector<int> a, vector<int> b);
void BubbleSort(vector<int>& arr);
void Print(vector<int>& arr);
void InsertSort(vector<int>& arr);
void SelectSort(vector<int>& arr);
void mergeSort(vector<int>& arr);
void mergeSortprocess(vector<int>& arr, int L, int R);
void merge(vector<int>& arr, int L, int M, int R);
void quickSort(vector<int>& arr);
void quickSortprocess(vector<int>& arr, int L, int R);
void partition(vector<int>& arr, int L, int R, pair<int, int>& p);
void heapSort(vector<int>& arr);
void heapInsert(vector<int>& arr, int index);
void heapify(vector<int>& arr, int index, int heapsize);
void radixSort(vector<int>& arr);
int maxbits(vector<int>& arr);
void radixSortprocess(vector<int>& arr, int L, int R, int digit);
int getDigit(int x, int d);




