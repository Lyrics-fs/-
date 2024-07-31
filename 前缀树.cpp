#include"head.h"
struct TrieNode
{
	int pass, end;
	vector<TrieNode*> nexts;
	TrieNode() : pass(0), end(0), nexts(26) {}
	~TrieNode()
	{
		for (auto node : nexts)
		{
			delete node;
		}
	}
};

class TrieTree
{
private:
	TrieNode* root;
	TrieTree() : root(nullptr) {}
	~TrieTree()
	{
		delete root;
	}
	void deleteNodeIfEmpty(TrieNode*& node) 
	{
		if (node == nullptr) return;
		for (int i = 0; i < 26; ++i) 
		{
			deleteNodeIfEmpty(node->nexts[i]);
		}
		if (node->pass == 0 && node->end == 0 && all_of(node->nexts.begin(), node->nexts.end(), [](TrieNode* n) { return n == nullptr; })) 
		{
			delete node;
			node = nullptr;
		}
	}
public:
	void Insert(string* world)
	{
		if (world == nullptr)
		{
			return;
		}
		TrieNode* node = root;
		node->pass++;
		int index = 0;
		for (auto i : *world)
		{
			index = i - 'a';
			if (node->nexts[index] == nullptr)
			{
				node->nexts[index] = new TrieNode;
			}
			node = node->nexts[index];
			node->pass++;
		}
		node->end++;
	}

	//查询加入过几次
	int Search(const string& word)
	{
		TrieNode* node = root;
		int index = 0;
		for (auto i : word)
		{
			index = i - 'a';
			if (node->nexts[index] == nullptr)
			{
				return 0;
			}
			node = node->nexts[index];
		}
		return node->end;
	}

	//加入字符串中有几个是以pre作为前缀的
	int prefixNumber(string* pre)
	{
		if (pre == nullptr)
		{
			return;
		}
		TrieNode* node = root;
		int index = 0;
		for (auto i : *pre)
		{
			index = i - 'a';
			if (node->nexts[index] == nullptr)
			{
				return 0;
			}
			node = node->nexts[index];
		}
		return node->pass;
	}

	void Delelte(const string& word)
	{
		if (Search(word) != 0)
		{
			TrieNode* node = root;
			TrieNode* prev = nullptr;
			node->pass--;
			int index = 0;
			for (auto i : word)
			{
				index = i - 'a';
				if (--node->nexts[index]->pass == 0)
				{
					node->nexts[index] = nullptr;
					delete node;
					return;
				}
				node = node->nexts[index];
			}
			node->end--;

			if (node->pass == 0 && node->end == 0) 
			{
				prev->nexts[word.back() - 'a'] = nullptr; // Disconnect the node from its parent  
				deleteNodeIfEmpty(node); // Recursively delete the subtree, including 'node' if it's empty  
			}
		}
	}
};