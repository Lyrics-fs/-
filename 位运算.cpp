#include"head.h"
//提取一个数二进制下最右边的1
//int eor = 55;
//00110111   eor
//11001000   ~eor
//11001001   ~eor+1
//00000001   eor & (~eor + 1)
//int ans = eor & (~eor + 1);

//两个32位有符号整数的最大值不使用任何比较
class GetMax
{
	//保证参数不是1就是0， 1变0， 0变1
	int flip(int n)
	{
		return n ^ 1;
	}

	//n是非负数返回1
	//n是负数返回0
	int sign(int n)
	{
		return flip((n >> 31) & 1);
	}

	//c有可能溢出
	int getMmax1(int a, int b)
	{
		int c = a - b;
		int scA = sign(c);//a-b为非负， scA为1， a-b为负， scA为0
		int scB = flip(scA);//scA为0， scB为1， scA为1， scB为0
		//scA为0， scB必为1， scA为1， scB必为0
		return a * scA + b * scB;
	}

	int getMax2(int a, int b)
	{
		int c = a - b;
		int sa = sign(a);
		int sb = sign(b);
		int sc = sign(c);
		int difSab = sa ^ sb;//a和b的符号不一样，为1，一样，为0
		int sameSab = flip(difSab);//a和b的符号一样为1，不一样为0
		int returnA = difSab * sa + sameSab * sc;
		int returnB = flip(returnA);
		return a * returnA + b * returnB;
	}
};

//判断一个数是不是2的幂或4的幂
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