#include"head.h"
int num1(int n)
{
	if (n < 1)
	{
		return 0;
	}
	//record[i] i行的皇后放在了第几列
	vector<int> record(n);
	return NQueensProcess1(0, record, n);
}
//第i行， 在之前行所摆的皇后位置， 总共行数，返回值是合法摆放种类数
int NQueensProcess1(int i, vector<int>& record, int n)
{
	if (i == n)
	{
		return 1;
	}
	int res = 0;
	for (int j = 0; j < n; j++)
	{
		//当前i行的皇后放在j列会不会和之前的皇后，共行共列或共斜线
		if (isValid(record, i, j))
		{
			record[i] = j;
			res += NQueensProcess1(i + 1, record, n);
		}
	}
	return res;
}

//i行皇后放在j列是否有效
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

//不要超过32皇后问题
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