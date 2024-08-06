#include"head.h"
//��ȡһ���������������ұߵ�1
//int eor = 55;
//00110111   eor
//11001000   ~eor
//11001001   ~eor+1
//00000001   eor & (~eor + 1)
//int ans = eor & (~eor + 1);

//����32λ�з������������ֵ��ʹ���καȽ�
class GetMax
{
	//��֤��������1����0�� 1��0�� 0��1
	int flip(int n)
	{
		return n ^ 1;
	}

	//n�ǷǸ�������1
	//n�Ǹ�������0
	int sign(int n)
	{
		return flip((n >> 31) & 1);
	}

	//c�п������
	int getMmax1(int a, int b)
	{
		int c = a - b;
		int scA = sign(c);//a-bΪ�Ǹ��� scAΪ1�� a-bΪ���� scAΪ0
		int scB = flip(scA);//scAΪ0�� scBΪ1�� scAΪ1�� scBΪ0
		//scAΪ0�� scB��Ϊ1�� scAΪ1�� scB��Ϊ0
		return a * scA + b * scB;
	}

	int getMax2(int a, int b)
	{
		int c = a - b;
		int sa = sign(a);
		int sb = sign(b);
		int sc = sign(c);
		int difSab = sa ^ sb;//a��b�ķ��Ų�һ����Ϊ1��һ����Ϊ0
		int sameSab = flip(difSab);//a��b�ķ���һ��Ϊ1����һ��Ϊ0
		int returnA = difSab * sa + sameSab * sc;
		int returnB = flip(returnA);
		return a * returnA + b * returnB;
	}
};

//�ж�һ�����ǲ���2���ݻ�4����
class Power
{
	bool is2Power(int n)
	{
		return (n & (n - 1)) == 0;
	}
	bool is4Power(int n)
	{
		return (n & (n - 1)) == 0 && (n & 0x55555555) != 0;//...1010101
	}
};

class AddMinusMultiDivideByBit
{
	int add(int a, int b)
	{
		int sum = a;
		while (b != 0)
		{
			sum = a ^ b;
			b = (a & b) << 1;
			a = sum;
		}
		return sum;
	}

	int negNum(int n)
	{
		return add(~n, 1);
	}

	int minus(int a, int b)
	{
		return add(a, negNum(b));
	}

	int multi(int a, int b)
	{
		int res = 0;
		while (b != 0)
		{
			if ((b & 1) != 0)
			{
				res = add(res, a);
			}
			a <<= 1;
			b >>= 1;
		}
		return res;
	}

	bool isNeg(int n)
	{
		return n < 0;
	}

	int div(int a, int b)
	{
		int x = isNeg(a) ? negNum(a) : a;
		int y = isNeg(b) ? negNum(b) : b;
		int res = 0;
		for (int i = 31; i > -1; i = minus(i, 1))
		{
			if ((x >> i) >= y)
			{
				res |= (1 << i);
				x = minus(x, y << i);
			}
		}
		return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
	}
};