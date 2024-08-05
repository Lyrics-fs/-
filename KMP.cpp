#include"head.h"
class KMP
{
public:
	int getIndexOf(string& s, string& m)
	{
		if (s.empty() || m.empty() || m.length() < 1 || s.length() < 1)
		{
			return -1;
		}
		int i1 = 0;
		int i2 = 0;
		vector<int> next = getNextArray(m);
		while (i1 < s.length() && i2 < m.length())
		{
			if (s[i1] == m[i2])
			{
				i1++;
				i2++;
			}
			else if (next[i2] == -1)//i2 == 0
			{
				i1++;
			}
			else
			{
				i2 = next[i2];
			}
		}
		//i1越界或者i2越界
		return i2 == m.length() ? i1 - i2 : -1;
	}

	vector<int> getNextArray(string& ms)
	{
		if (ms.size() == 1)
		{
			return vector<int> {-1};
		}
		vector<int> next(ms.size());
		next[0] = -1;
		next[1] = 0;
		int i = 2;//next数组的位置
		int cn = 0;
		while (i < next.size())
		{
			if (ms[i - 1] == ms[cn])
			{
				next[i++] = ++cn;
			}
			else if (cn > 0)
			{
				cn = next[cn];
			}
			else
			{
				next[i++] = 0;
			}
		}
		return next;
	}
};
