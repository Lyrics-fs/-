#include"head.h"
class Manacher
{
public:
	string manacherString(string& str)
	{
		string res;
		int index = 0;
		for (int i = 0; i != str.size() * 2 + 1; i++)
		{
			res[i] = (i & 1) == 0 ? '#' : str[index++];
		}
		return res;
	}

	int maxLcpsLength(string& s)
	{
		if (s.empty() || s.size() == 0)
		{
			return 0;
		}
		string str = manacherString(s);
		vector<int> pArr(str.size());//���İ뾶����
		int C = -1;//����
		int R = -1;//�����ұ߽��������һ��λ�ã� ���ҵ���Ч������R-1
		int maxv = -0x3f3f3f3f;//�����������ֵ
		for (int i = 0; i != str.size(); i++)
		{//ÿһ��λ�ö�����İ뾶
			//i���ٵĻ��������ȸ�pArr[i]
			pArr[i] = R > i ? min(pArr[2 * C - i], R - i) : 1;
			while (i + pArr[i] < str.size() && i - pArr[i] > -1)
			{
				if (str[i + pArr[i]] == str[i - pArr[i]])
				{
					pArr[i]++;
				}
				else
				{
					break;
				}
			}
			if (i + pArr[i] > R)
			{
				R = i + pArr[i];
				C = i;
			}
			maxv = max(maxv, pArr[i]);

		}
		return maxv - 1;
	}
};