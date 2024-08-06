#include"head.h"
//求树上最远两点距离
class MaxDistanceInTree
{
public:
	class Node
	{
	public:
		int value;
		Node* left;
		Node* right;
		Node(int data) : value(data), left(nullptr), right(nullptr) {}
	};

	int maxDistance(Node* head)
	{
		return process(head).maxDistance;
	}

	class Info
	{
	public:
		int maxDistance;
		int height;
		Info(int dis, int h) : maxDistance(dis), height(h) {}
	};

	Info process(Node* x)
	{
		if (x == nullptr)
		{
			return Info(0, 0);
		}
		Info leftInfo = process(x->left);
		Info rightInfo = process(x->right);

		int p1 = leftInfo.maxDistance;
		int p2 = rightInfo.maxDistance;
		int p3 = leftInfo.height + 1 + rightInfo.height;
		int maxDistance = max(p3, max(p1, p2));
		int height = max(leftInfo.height, rightInfo.height) + 1;
		return Info(maxDistance, height);
	}
};