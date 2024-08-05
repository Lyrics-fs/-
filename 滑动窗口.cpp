#include"head.h"
class SlidingWindowMaxArray
{
private:
	int L, R;
	vector<int> arr;
	deque<int> qmax;
	SlidingWindowMaxArray(vector<int> a) : arr(a), L(-1), R(0) {}
public:
	void addNumFromRight()
	{
		if (R == arr.size())
		{
			return;
		}
		while (!qmax.empty() && arr[qmax.back()] <= arr[R])
		{
			qmax.pop_back();
		}
		qmax.push_back(R);
		R++;
	}

	void removeNumFromLeft()
	{
		if (L >= R - 1)
		{
			return;
		}
		L++;
		if (qmax.front() == L)
		{
			qmax.pop_front();
		}
	}

	int getMax()
	{
		if (!qmax.empty())
		{
			return arr[qmax.front()];
		}
		return -1;
	}
};