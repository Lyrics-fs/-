#include"head.h"
struct Edge;
struct GraphNode
{
	int value, in, out;
	list<GraphNode*> nexts;
	list<Edge*> edges;

	GraphNode(int value) : value(value), in(0), out(0) {}
};

struct Edge
{
	int weight;
	GraphNode* from, * to;
	Edge(int weight, GraphNode* from, GraphNode* to) : weight(weight), from(from), to(to) {}
};

class Graph
{
	unordered_map<int, GraphNode*> nodes;
	unordered_set<Edge*> edges;

public:
	void BFS(GraphNode* Node)
	{
		if (Node == nullptr)
		{
			return;
		}

		queue<GraphNode*> queue;
		unordered_set<GraphNode*> set;

		queue.push(Node);
		set.insert(Node);

		while (!queue.empty())
		{
			GraphNode* cur = queue.front();
			queue.pop();
			cout << cur->value << " ";
			for (auto next : cur->nexts)
			{
				if (set.find(next) != set.end())
				{
					set.insert(next);
					queue.push(next);
				}
			}
		}
	}

	void DFS(GraphNode* Node)
	{
		if (Node == nullptr)
		{
			return;
		}

		stack<GraphNode*> stack;
		unordered_set<GraphNode*> set;
		stack.push(Node);
		set.insert(Node);
		cout << Node->value << " ";
		while (!stack.empty())
		{
			GraphNode* cur = stack.top();
			stack.pop();
			for (auto next : cur->nexts)
			{
				if (set.find(next) != set.end())
				{
					stack.push(cur);
					stack.push(next);
					set.insert(next);
					cout << next->value << " ";
					break;
				}
			}
		}
	}

	void TopologySort(Graph graph, list<GraphNode*> result);
};


void Graph :: TopologySort(Graph graph, list<GraphNode*> result)
{
	unordered_map<GraphNode*, int> inMap;
	queue<GraphNode*> zeroInQueue;
	for (auto& node : graph.nodes)
	{
		inMap.insert(pair<GraphNode*, int>(node.second, node.second->in));
		if (node.second->in == 0)
		{
			zeroInQueue.push(node.second);
		}
	}
	while (!zeroInQueue.empty())
	{
		GraphNode* cur = zeroInQueue.front();
		zeroInQueue.pop();
		result.push_back(cur);
		for (auto next : cur->nexts)
		{
			inMap.insert(pair<GraphNode*, int>(next, inMap[next] - 1));
			if (inMap[next] == 0)
			{
				zeroInQueue.push(next);
			}
		}
	}
}
