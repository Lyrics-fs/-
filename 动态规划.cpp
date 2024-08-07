#include"head.h"
class RobotWalk
{
	int walkWays1(int N, int E, int S, int K)
	{
		return f1(N, E, K, S);
	}

	//һ����1~N��ô��λ�� �̶�����
	//���յ�Ŀ����E �̶�����
	//��ǰ��curλ��
	//��ʣrest��
	//���ط�����
	int f1(int N, int E, int rest, int cur)
	{
		if (rest == 0)
		{
			return cur == E ? 1 : 0;
		}
		if (cur == 1)
		{
			return f1(N, E, rest - 1, 2);
		}
		if (cur == N)
		{
			return f1(N, E, rest - 1, N - 1);
		}
		return f1(N, E, rest - 1, cur - 1) + f1(N, E, rest - 1, cur + 1);
	}

	//���仯�����汾
	int walkWays2(int N, int E, int S, int K)
	{
		vector<vector<int>> dp(K + 1, vector<int>(N + 1, -1));
		return f2(N, E, K, S, dp);
	}

	
	int f2(int N, int E, int rest, int cur, vector<vector<int>>& dp)
	{
		if (dp[rest][cur] != -1)
		{
			return dp[rest][cur];
		}

		if (rest == 0)
		{
			dp[rest][cur] = E ? 1 : 0;
		}
		else if (cur == 1)
		{
			dp[rest][cur] = f1(N, E, rest - 1, 2);
		}
		else if (cur == N)
		{
			dp[rest][cur] = f1(N, E, rest - 1, N - 1);
		}
		else
		{
			dp[rest][cur] = f1(N, E, rest - 1, cur - 1) + f1(N, E, rest - 1, cur + 1);
		}
		
		return dp[rest][cur];
	}

	//��̬�滮�汾
	int dpWay(int N, int P, int M, int K)
	{
		vector<vector<int>> dp(K + 1, vector<int>(N + 1));
		dp[0][1] = 1;
		for (int rest = 1; rest <= K; rest++)
		{
			for (int cur = 1; cur <= N; cur++)
			{
				if (cur == 1)
				{
					dp[rest][cur] = dp[rest - 1][2];
				}
				else if (cur == N)
				{
					dp[rest][cur] = dp[rest - 1][N - 1];
				}
				else
				{
					dp[rest][cur] = dp[rest - 1][cur - 1] + dp[rest - 1][cur + 1];
				}
			}
		}
		return dp[M][K];
	}
};

class CoinsMin
{
	int minCoins1(vector<int>& arr, int aim)
	{
		return process1(arr, 0, aim);
	}

	
	int process1(vector<int>& arr, int index, int rest)
	{
		if (rest < 0)
		{
			return -1;
		}
		if (rest == 0)
		{
			return 0;
		}
		if (index == arr.size())
		{
			return -1;
		}
		int p1 = process1(arr, index + 1, rest);
		int p2Next = process1(arr, index + 1, rest - arr[index]);
		if (p1 == -1 && p2Next == -1)
		{
			return -1;
		}
		else
		{
			if (p1 == -1)
			{
				return p2Next + 1;
			}
			if (p2Next == -1)
			{
				return p1;
			}
			else
			{
				return min(p1, p2Next + 1);
			}
		}
	}

	int minCoins2(vector<int>& arr, int aim)
	{
		vector<vector<int>> dp((int)arr.size() + 1, vector<int>((aim + 1), -2));
		return process2(arr, 0, aim, dp);
	}


	int process2(vector<int>& arr, int index, int rest, vector<vector<int>>& dp)
	{
		if (rest < 0)
		{
			return -1;
		}
		if (dp[index][rest] != -2)
		{
			return dp[index][rest];
		}

		if (rest == 0)
		{
			dp[index][rest] = 0;
		}
		if (index == arr.size())
		{
			dp[index][rest] = -1;
		}
		else
		{
			int p1 = process2(arr, index + 1, rest, dp);
			int p2Next = process2(arr, index + 1, rest - arr[index], dp);
			if (p1 == -1 && p2Next == -1)
			{
				dp[index][rest] = -1;
			}
			else
			{
				if (p1 == -1)
				{
					dp[index][rest] = p2Next + 1;
				}
				if (p2Next == -1)
				{
					dp[index][rest] = p1;
				}
				else
				{
					dp[index][rest] = min(p1, p2Next + 1);
				}
			}
		}
		
	}

	int minCoins3(vector<int>& arr, int aim)
	{
		int N = arr.size();
		vector<vector<int>> dp(N + 1, vector<int>(aim + 1));
		for (int row = 0; row < N; row++)
		{
			dp[row][0] = 0;
		}
		for (int col = 1; col <= aim; col++)
		{
			dp[N][col] = -1;
		}

		for (int index = N - 1; index >= 0; index--)
		{
			for (int rest = 1; rest <= aim; rest++)
			{
				int p1 = dp[index + 1][rest];
				int p2Next = -1;
				if (rest - arr[index] >= 0)
				{
					p2Next = dp[index + 1][rest - arr[index]];
				}
				if (p1 == -1 && p2Next == -1)
				{
					dp[index][rest] = -1;
				}
				else
				{
					if (p1 == -1)
					{
						dp[index][rest] = -1;
					}
					if (p2Next == -1)
					{
						dp[index][rest] = p1;
					}
					dp[index][rest] = min(p1, p2Next + 1);
				}
			}
		}
		return dp[0][aim];
	}
};

class CardsInLine
{
	int win1(vector<int>& arr)
	{
		if (&arr == nullptr || arr.size() == 0)
		{
			return 0;
		}
		return max(f(arr, 0, arr.size() - 1), s(arr, 0, arr.size() - 1));
	}

	//���ֺ���
	//��ǰ�����ã�arr[i..j]
	//���������÷���
	int f(vector<int>& arr, int i, int j)
	{
		if (i == j)
		{
			return arr[i];
		}

		return max(arr[i] + s(arr, i + 1, j), s(arr, i, j - 1));
	}

	//���ֺ���
	//��ǰ�㲻���ã��ǶԷ���arr[i..j]��Χ����
	//���������÷���
	int s(vector<int>& arr, int i, int j)
	{
		if (i == j)
		{
			return 0;
		}
		return min(f(arr, i + 1, j), f(arr, i, j - 1));
	}
};

class HorseJump
{
	int getWays(int x, int y, int k)
	{
		return process(x, y, k);
	}

	//Ҫ�����λ�ú�ʣ��Ĳ���
	int process(int a, int b, int step)
	{
		if (a < 0 || a > 8 || b < 0 || b > 9)
		{
			return 0;
		}
		if (step == 0)
		{
			return (a == 0 && b == 0) ? 1 : 0;
		}
		return process(a - 1, b + 2, step - 1)
			+ process(a + 1, b + 2, step - 1)
			+ process(a + 2, b + 1, step - 1)
			+ process(a + 2, b - 1, step - 1)
			+ process(a + 1, b - 2, step - 1)
			+ process(a - 1, b - 2, step - 1)
			+ process(a - 2, b - 1, step - 1)
			+ process(a - 2, b + 1, step - 1);
	}

	int dpWays(int x, int y, int step)
	{
		if (x < 0 || x > 8 || y < 0 || y > 9 || step < 0)
		{
			return 0;
		}
		vector<vector<vector<int>>> dp(9, vector<vector<int>>(10, vector<int>(step + 1)));
		dp[0][0][0] = 1;
		for (int h = 1; h <= step; h++)
		{
			for (int r = 0; r < 9; r++)
			{
				for (int c = 0; c < 9; c++)
				{
					dp[r][c][h] += getValue(dp, r - 1, c + 2, h - 1);
					dp[r][c][h] += getValue(dp, r + 1, c + 2, h - 1);
					dp[r][c][h] += getValue(dp, r + 2, c + 1, h - 1);
					dp[r][c][h] += getValue(dp, r + 2, c - 1, h - 1);
					dp[r][c][h] += getValue(dp, r + 1, c - 2, h - 1);
					dp[r][c][h] += getValue(dp, r - 1, c - 2, h - 1);
					dp[r][c][h] += getValue(dp, r - 2, c - 1, h - 1);
					dp[r][c][h] += getValue(dp, r - 2, c + 1, h - 1);

				}
			}
		}
		return dp[x][y][step];
	}

	int getValue(vector<vector<vector<int>>>& dp, int row, int col, int step)
	{
		if (row < 0 || row > 8 || col < 0 || col > 9)
		{
			return 0;
		}
		return dp[row][col][step];
	}
};

class CoinWays
{
	//arr�ﶼ��������û���ظ�ֵ��ÿһ��ֵ����һ�ֻ��ң�ÿһ�ֿ�����������
	//����Ҫ����Ǯ����aim
	//���㷽��������
	int way1(vector<int>& arr, int aim)
	{
		return process(arr, 0, aim);
	}

	//��������ʹ��arr[index...]���е���ֵ
	//��Ҫ�㶨��Ǯ����rest
	//��������ķ�����
	int process(vector<int>& arr, int index, int rest)
	{
		if (index == arr.size())
		{
			return rest == 0 ? 1 : 0;
		}
		//arr[index] 0�ţ�1��... ��Ҫ����rest��Ǯ��
		int ways = 0;
		for (int zhang = 0; arr[index] * zhang <= rest; zhang++)
		{
			ways += process(arr, index + 1, rest - arr[index] * zhang);
		}
		return ways;
	}

	int way2(vector<int>& arr, int aim)
	{
		if (&arr == nullptr || arr.size() == 0)
		{
			return 0;
		}
		int N = arr.size();
		vector<vector<int>> dp(N + 1, vector<int>(aim + 1));
		dp[N][0] = 1;
		for (int index = N - 1; index >= 0; index--)
		{
			for (int rest = 0; rest <= aim; rest++)
			{
				int ways = 0;
				for (int zhang = 0; arr[index] * zhang <= rest; zhang++)
				{
					ways += dp[index + 1][rest - arr[index] * zhang];
				}
				dp[index][rest] = ways;
			}
		}
		return dp[0][aim];
	}

	int way3(vector<int>& arr, int aim)
	{
		if (&arr == nullptr || arr.size() == 0)
		{
			return 0;
		}
		int N = arr.size();
		vector<vector<int>> dp(N + 1, vector<int>(aim + 1));
		dp[N][0] = 1;
		for (int index = N - 1; index >= 0; index--)
		{
			for (int rest = 0; rest <= aim; rest++)
			{
				dp[index][rest] = dp[index + 1][rest];
				if (rest - arr[index] >= 0)
				{
					dp[index][rest] += dp[index][rest - arr[index]];
				}
			}
		}
		return dp[0][aim];
	}
};