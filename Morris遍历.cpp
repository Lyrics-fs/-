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
			mostRight = cur->left;//mostRight��cur����
			if (mostRight != nullptr)//��������
			{
				while (mostRight->right != nullptr && mostRight->right != cur)
				{
					mostRight = mostRight->right;
				}
				//mostRight�����cur�����������ҵĽڵ�
				if (mostRight->right == nullptr)//��һ�ε�cur
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
			mostRight = cur->left;//mostRight��cur����
			if (mostRight != nullptr)//��������
			{
				while (mostRight->right != nullptr && mostRight->right != cur)
				{
					mostRight = mostRight->right;
				}
				//mostRight�����cur�����������ҵĽڵ�
				if (mostRight->right == nullptr)//��һ�ε�cur
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
			else//û��������
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
			mostRight = cur->left;//mostRight��cur����
			if (mostRight != nullptr)//��������
			{
				while (mostRight->right != nullptr && mostRight->right != cur)
				{
					mostRight = mostRight->right;
				}
				//mostRight�����cur�����������ҵĽڵ�
				if (mostRight->right == nullptr)//��һ�ε�cur
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
			mostRight = cur->left;//mostRight��cur����
			if (mostRight != nullptr)//��������
			{
				while (mostRight->right != nullptr && mostRight->right != cur)
				{
					mostRight = mostRight->right;
				}
				//mostRight�����cur�����������ҵĽڵ�
				if (mostRight->right == nullptr)//��һ�ε�cur
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