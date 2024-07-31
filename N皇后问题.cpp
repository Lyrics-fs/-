#include"head.h"
int num1(int n)
{
	if (n < 1)
	{
		return 0;
	}
	//record[i] i�еĻʺ�����˵ڼ���
	vector<int> record(n);
	return NQueensProcess1(0, record, n);
}
//��i�У� ��֮ǰ�����ڵĻʺ�λ�ã� �ܹ�����������ֵ�ǺϷ��ڷ�������
int NQueensProcess1(int i, vector<int>& record, int n)
{
	if (i == n)
	{
		return 1;
	}
	int res = 0;
	for (int j = 0; j < n; j++)
	{
		//��ǰi�еĻʺ����j�л᲻���֮ǰ�Ļʺ󣬹��й��л�б��
		if (isValid(record, i, j))
		{
			record[i] = j;
			res += NQueensProcess1(i + 1, record, n);
		}
	}
	return res;
}

//i�лʺ����j���Ƿ���Ч
bool isValid(vector<int>& record, int i, int j)
{
	for (int k = 0; k < i; k++)
	{
		if (j == record[k] || abs(record[k] - j) == abs(i - k))
		{
			return false;
		}
	}
	return true;
}

//��Ҫ����32�ʺ�����
int num2(int n)
{
	if (n < 1 || n > 32)
	{
		return 0;
	}
	int limit = n == 32 ? -1 : (1 << n) - 1;
	return NQueensProcess2(limit, 0, 0, 0);
}

int NQueensProcess2(int limit, int colLim, int leftDiaLim, int rightDiaLim)
{
	if (colLim == limit)
	{
		return 1;
	}
	int pos = 0;
	int mostRightOne = 0;
	pos = limit & (~(colLim | leftDiaLim | rightDiaLim));
	int res = 0;
	while (pos != 0)
	{
		mostRightOne = pos & (~pos + 1);
		pos = pos - mostRightOne;
		res += NQueensProcess2(limit, colLim | mostRightOne, (leftDiaLim | mostRightOne) << 1, (rightDiaLim | mostRightOne) >> 1);
	}
	return res;
}