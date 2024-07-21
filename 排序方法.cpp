#include"head.h"

//����
void Swap(int* a, int* b)
{
	if (a == b) return;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
//��ӡ
void Print(vector<int>& arr)
{
	for (auto elem : arr)
	{
		cout << elem << ' ';
	}
	cout << '\n';
}
//������
//�����������ɵ�����
void generateRandomArray(int MaxSize, int MaxNum, vector<int>& array)
{
	random_device rd;// ���ڻ�ȡ��������ӵķ�ȷ��������������� 
	mt19937 gen(rd()); // �� rd() ��Ϊ���ӵ� Mersenne Twister ������  
	uniform_int_distribution<> dis(1, MaxNum); // ������һ�� [1, 100] �����ڵľ��������ֲ� 
	for (int i = 0; i < MaxSize; i++)
	{
		array.push_back(dis(gen));
	}
}
//��������
void copyRandomArray(vector<int>& array, vector<int>& NewArray)
{
	for (int i = 0; i < array.size(); i++)
	{
		NewArray.push_back(array[i]);
	}
}
//�Ƚ�����
bool compareRandomArray(vector<int> a, vector<int> b)
{
	if (a.size() != b.size()) return false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}
//ð������
void BubbleSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size() - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
//��������
void InsertSort(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
		{
			Swap(&arr[j], &arr[j + 1]);
		}
	}
}
//ѡ������
void SelectSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			minIndex = arr[j] < arr[minIndex] ? j : minIndex;
		}
		Swap(&arr[i], &arr[minIndex]);
		//����ʹ��δ�ж���ַSwap��ԭ��
		//54321 i = 0 j = 1��ʼ
		//14325 i = 1 j = 2��ʼ
		//12345 i = 2 j = 3��ʼ �Ƚ�֮��i == minIndex ������ַ��ͬ
	}
}
//�鲢����
void mergeSort(vector<int>& arr)
{
	mergeSortprocess(arr, 0, arr.size() - 1);
}
void mergeSortprocess(vector<int>& arr, int L, int R)
{
	if (L == R) return;
	int mid = L + ((R - L) >> 1);
	mergeSortprocess(arr, L, mid);
	mergeSortprocess(arr, mid + 1, R);
	merge(arr, L, mid, R);
}
void merge(vector<int>& arr, int L, int M, int R)
{
	vector<int> help;
	int P1 = L, P2 = M + 1;
	while (P1 <= M && P2 <= R)
	{
		help.push_back(arr[P1] < arr[P2] ? arr[P1++] : arr[P2++]);
	}
	while (P1 <= M)
	{
		help.push_back(arr[P1++]);
	}
	while (P2 <= R)
	{
		help.push_back(arr[P2++]);
	}
	for (int i = 0; i < help.size(); i++)
	{
		arr[L + i] = help[i];
	}
}
//��������
void quickSort(vector<int>& arr)
{
	quickSortprocess(arr, 0, arr.size() - 1);
}
void quickSortprocess(vector<int>& arr, int L, int R)
{
	// �������������  
	srand(static_cast<unsigned int>(time(0)));
	if (L < R)
	{
		Swap(&arr[L + rand() % (R - L + 1)], &arr[R]);
		pair<int, int> p;
		partition(arr, L, R, p);
		quickSortprocess(arr, L, p.first - 1);//<��
		quickSortprocess(arr, p.second + 1, R);//>��
	}
}
void partition(vector<int>& arr, int L, int R, pair<int, int>& p)
{
	int less = L - 1, more = R;//<�����ұ߽� >������߽�
	while (L < more)//L��ǰ��λ�� arr[R]������
	{
		if (arr[L] < arr[R])
		{
			Swap(&arr[++less], &arr[L++]);
		}
		else if (arr[L] > arr[R])
		{
			Swap(&arr[--more], &arr[L]);
		}
		else
		{
			L++;
		}
	}
	Swap(&arr[more], &arr[R]);
	p.first = less + 1;
	p.second = more;
}