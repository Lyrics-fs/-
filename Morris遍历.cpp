#include"head.h"
class Morris
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

	void morris(Node* head)
	{
		if (head == nullptr)
		{
			return;
		}
		Node* cur = head;
		Node* mostRight = nullptr;
		while (cur != nullptr)
		{
			mostRight = cur->left;//mostRight是cur左孩子
			if (mostRight != nullptr)//有左子树
			{
				while (mostRight->right != nullptr && mostRight->right != cur)
				{
					mostRight = mostRight->right;
				}
				//mostRight变成了cur左子树上最右的节点
				if (mostRight->right == nullptr)//第一次到cur
				{
					mostRight->right = cur;
					cur = cur->left;
					continue;
				}
				else//mostRight.right == cur
				{
					mostRight->right = nullptr;
				}
			}
			cur = cur->right;
		}
	}

	void morrisPre(Node* head)
	{
		if (head == nullptr)
		{
			return;
		}
		Node* cur = head;
		Node* mostRight = nullptr;
		while (cur != nullptr)
		{
			mostRight = cur->left;//mostRight是cur左孩子
			if (mostRight != nullptr)//有左子树
			{
				while (mostRight->right != nullptr && mostRight->right != cur)
				{
					mostRight = mostRight->right;
				}
				//mostRight变成了cur左子树上最右的节点
				if (mostRight->right == nullptr)//第一次到cur
				{
					cout << cur->value << " ";
					mostRight->right = cur;
					cur = cur->left;
					continue;
				}
				else//mostRight.right == cur
				{
					mostRight->right = nullptr;
				}
			}
			else//没有左子树
			{
				cout << cur->value << " ";
			}
			cur = cur->right;
		}
	}

	void morrisIn(Node* head)
	{
		if (head == nullptr)
		{
			return;
		}
		Node* cur = head;
		Node* mostRight = nullptr;
		while (cur != nullptr)
		{
			mostRight = cur->left;//mostRight是cur左孩子
			if (mostRight != nullptr)//有左子树
			{
				while (mostRight->right != nullptr && mostRight->right != cur)
				{
					mostRight = mostRight->right;
				}
				//mostRight变成了cur左子树上最右的节点
				if (mostRight->right == nullptr)//第一次到cur
				{
					mostRight->right = cur;
					cur = cur->left;
					continue;
				}
				else//mostRight.right == cur
				{
					mostRight->right = nullptr;
				}
			}
			cout << cur->value << " ";
			cur = cur->right;
		}
	}

	void morrisPos(Node* head)
	{
		if (head == nullptr)
		{
			return;
		}
		Node* cur = head;
		Node* mostRight = nullptr;
		while (cur != nullptr)
		{
			mostRight = cur->left;//mostRight是cur左孩子
			if (mostRight != nullptr)//有左子树
			{
				while (mostRight->right != nullptr && mostRight->right != cur)
				{
					mostRight = mostRight->right;
				}
				//mostRight变成了cur左子树上最右的节点
				if (mostRight->right == nullptr)//第一次到cur
				{
					mostRight->right = cur;
					cur = cur->left;
					continue;
				}
				else//mostRight.right == cur
				{
					mostRight->right = nullptr;
					printEdge(cur->left);
				}
			}
			printEdge(head);
			cur = cur->right;
		}
	}

	void printEdge(Node* x)
	{
		Node* tail = reverseEdge(x);
		Node* cur = tail;
		while (cur != nullptr)
		{
			cout << cur->value << " ";
			cur = cur->right;
		}
		reverseEdge(tail);
	}

	Node* reverseEdge(Node* from)
	{
		Node* pre = nullptr;
		Node* next = nullptr;
		while (from != nullptr)
		{
			next = from->right;
			from->right = pre;
			pre = from;
			from = next;
		}
		return pre;
	}
};