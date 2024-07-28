#include"head.h"
struct SearchTreeNode
{
	int val;
	SearchTreeNode* left, *right;
	SearchTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SearchTreeCpp
{
private:
	SearchTreeNode* root;

	void DestroyTree(SearchTreeNode* current)
	{
		if (current == nullptr)
		{
			return;
		}

		DestroyTree(current->left);
		DestroyTree(current->right);

		delete current;
	}
public:
	SearchTreeCpp() : root(nullptr) {}
	~SearchTreeCpp()
	{
		DestroyTree(root);
	}

	void Insert(int val)
	{
		root = InsertProcess(val, root);
	}

	SearchTreeNode* InsertProcess(int val, SearchTreeNode* current)
	{
		if (current == nullptr)
		{
			current = new SearchTreeNode(val);
		}
		else if (val < current->val)
		{
			current->left = InsertProcess(val, current->left);
		}
		else if (val > current->val)
		{
			current->right = InsertProcess(val, current->right);
		}

		return current;
	}

	SearchTreeNode* Find(int val, SearchTreeNode* current)
	{
		if (current == nullptr)
		{
			return nullptr;
		}
		if (val < current->val)
		{
			return Find(val, current->left);
		}
		else if (val > current->val)
		{
			return Find(val, current->right);
		}
		else
		{
			return current;
		}
	}

	SearchTreeNode* FindMin(SearchTreeNode* current)
	{
		if (current == nullptr)
		{
			return nullptr;
		}
		else if (current->left == nullptr)
		{
			return current;
		}
		else
		{
			return FindMin(current->left);
		}

	}

	SearchTreeNode* FindMax(SearchTreeNode* current)
	{
		if (current != nullptr)
		{
			while (current->right != nullptr)
			{
				current = current->right;
			}
		}

		return current;
	}

	SearchTreeNode* Delete(int val, SearchTreeNode* current)
	{
		SearchTreeNode* TmpCell = nullptr;
		if (current == nullptr)
		{
			perror("Element not found");
		}
		else if (val < current->val)
		{
			current->left = Delete(val, current->left);
		}
		else if (val > current->val)
		{
			current->right = Delete(val, current->right);
		}
		else if (current->left && current->right)
		{
			TmpCell = FindMin(current->right);
			current->val = TmpCell->val;
			current->right = Delete(current->val, current->right);
		}
		else
		{
			TmpCell = current;
			if (current->left == nullptr)
			{
				current = current->right;
			}
			else if (current->right == nullptr)
			{
				current = current->left;
			}
			delete TmpCell;
		}
		return current;
	}

	void PreOrderPrint()
	{
		PreOrderPrintProcess(root);
		cout << '\n';
	}

	SearchTreeNode* PreOrderPrintProcess(SearchTreeNode* current)
	{
		if (current == nullptr)
		{
			return nullptr;
		}
		cout << current->val << " ";
		PreOrderPrintProcess(current->left);
		PreOrderPrintProcess(current->right);
	}

	void InOrderPrint()
	{
		InOrderPrintProcess(root);
		cout << '\n';
	}

	SearchTreeNode* InOrderPrintProcess(SearchTreeNode* current)
	{
		if (current == nullptr)
		{
			return nullptr;
		}
		InOrderPrintProcess(current->left);
		cout << current->val << " ";
		InOrderPrintProcess(current->right);
	}

	void PosOrderPrint()
	{
		PosOrderPrintProcess(root);
		cout << '\n';
	}

	SearchTreeNode* PosOrderPrintProcess(SearchTreeNode* current)
	{
		if (current == nullptr)
		{
			return nullptr;
		}
		PosOrderPrintProcess(current->left);
		PosOrderPrintProcess(current->right);
		cout << current->val << " ";
	}

	void PreOrderUnRecur()
	{
		PreOrderUnRecurProcess(root);
	}
	void PreOrderUnRecurProcess(SearchTreeNode* current)
	{
		stack<SearchTreeNode*> st;
		if (current != nullptr)
		{
			st.push(current);
			while (!st.empty())
			{
				current = st.top();
				st.pop();
				cout << current->val << " ";
				if (current->right != nullptr)
				{
					st.push(current->right);
				}
				if (current->left != nullptr)
				{
					st.push(current->left);
				}
			}
		}
		cout << '\n';
	}

	void InOrderUnRecur()
	{
		InOrderUnRecurProcess(root);
	}

	void InOrderUnRecurProcess(SearchTreeNode* current)
	{
		stack<SearchTreeNode*> stack;
		if (current != nullptr)
		{
			while (!stack.empty() || current != nullptr)
			{
				if (current != nullptr)
				{
					stack.push(current);
					current = current->left;
				}
				else
				{
					current = stack.top();
					stack.pop();
					cout << current->val << " ";
					current = current->right;
				}
			}
		}
		cout << '\n';
	}

	void PosOrderUnRecur()
	{
		PosOrderUnRecurProcess(root);
	}

	void PosOrderUnRecurProcess(SearchTreeNode* current)
	{
		stack<SearchTreeNode*> s1;
		stack<SearchTreeNode*> s2;
		if (current != nullptr)
		{
			s1.push(current);
			while (!s1.empty())
			{
				current = s1.top();
				s1.pop();
				s2.push(current);
				if (current->left != nullptr)
				{
					s1.push(current->left);
				}
				if (current->right != nullptr)
				{
					s1.push(current->right);
				}
			}
			while (!s2.empty())
			{
				cout << s2.top()->val << " ";
				s2.pop();
			}
		}
		cout << '\n';
	}
};
int main()
{
	SearchTreeCpp Stree;
	vector<int> array;
	random_device rd;// 用于获取随机数种子的非确定性随机数生成器 
	mt19937 gen(rd()); // 以 rd() 作为种子的 Mersenne Twister 生成器  
	uniform_int_distribution<> dis(1, 100); // 定义了一个 [1, 100] 区间内的均匀整数分布 
	for (int i = 0; i < 20; i++)
	{
		array.push_back(dis(gen));
	}
	for (auto elem : array)
	{
		Stree.Insert(elem);
	}
	Stree.PreOrderPrint();
	Stree.PreOrderUnRecur();
	return 0;
}