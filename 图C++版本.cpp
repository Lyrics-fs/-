#include"head.h"
struct Edge;
struct GraphNode
{
	int value, in, out;
	list<GraphNode*> nexts;
	list<Edge*> edges;

	GraphNode(int value) : value(value), in(0), out(0) {}
};

class Edge
{
public:
	int weight;
	GraphNode* from, * to;
	bool operator<(const Edge& edge) const
	{
		return weight - edge.weight;
	}
	Edge(int weight, GraphNode* from, GraphNode* to) : weight(weight), from(from), to(to) {}
};

class Graph
{
	unordered_map<int, GraphNode*> nodes;
	unordered_set<Edge*> edges;

public:
	void addEdge(int from, int to, int weight)
	{
		if (nodes.find(from) == nodes.end()) nodes[from] = new GraphNode(from);
		if (nodes.find(to) == nodes.end()) nodes[to] = new GraphNode(to);

		Edge* e = new Edge(weight, nodes[from], nodes[to]);
		nodes[from]->edges.push_back(e);
		nodes[to]->edges.push_back(e);
		nodes[to]->in++;
		nodes[from]->out++;
	}

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
	
	void Kruskal(Graph graph, unordered_set<Edge*> result)
	{
		class Mysets
		{
			unordered_map<GraphNode*, list<GraphNode*>> setMap;

		public:

			Mysets(list<GraphNode*> nodes)
			{
				for (auto cur : nodes)
				{
					list<GraphNode*> set;
					set.push_back(cur);
					setMap.insert(pair<GraphNode*, list<GraphNode*>>(cur, set));
				}
			}

			bool isSameSet(GraphNode* from, GraphNode* to)
			{
				list<GraphNode*> fromset = setMap[from];
				list<GraphNode*> toset = setMap[to];
				return fromset == toset;
			}

			void Union(GraphNode* from, GraphNode* to)
			{
				list<GraphNode*> fromset = setMap[from];
				list<GraphNode*> toset = setMap[to];
				for (auto toNode : toset)
				{
					fromset.push_back(toNode);
					setMap.insert(pair<GraphNode*, list<GraphNode*>>(toNode, fromset));
				}
			}

		};
		list<GraphNode*> values;
		for (auto node : graph.nodes)
		{
			values.push_back(node.second);
		}
		Mysets unionFind(values);

		
		priority_queue<Edge*> PQ;
		for (auto edge : graph.edges)
		{
			PQ.push(edge);
		}
		while (!PQ.empty())
		{
			Edge* edge = PQ.top();
			PQ.pop();
			if (!unionFind.isSameSet(edge->from, edge->to))
			{
				result.insert(edge);
				unionFind.Union(edge->from, edge->to);
			}
		}

	}
	

	void Prim(Graph graph, unordered_set<Edge*> result)
	{
		priority_queue<Edge*, greater<Edge*>> PQ;
		unordered_set<GraphNode*> set;
		for (auto node : graph.nodes)
		{
			if (set.find(node.second) == set.end())
			{
				set.insert(node.second);
				for (auto edge : node.second->edges)
				{
					PQ.push(edge);
				}
				while (!PQ.empty())
				{
					Edge* edge = PQ.top();
					PQ.pop();
					GraphNode* toNode = edge->to;
					if (set.find(toNode) == set.end())
					{
						set.insert(toNode);
						result.insert(edge);
						for (auto nextEdge : toNode->edges)
						{
							PQ.push(nextEdge);
						}
					}
				}
			}
		}
	}

	GraphNode* getMinDistanceAndUnselectedNode(unordered_map<GraphNode*, int>distanceMap, unordered_set<GraphNode*> touchNodes)
	{
		GraphNode* minNode = nullptr;
		int minDistance = 0x3f3f3f3f;
		for (auto entry : distanceMap)
		{
			GraphNode* node = entry.first;
			int distance = entry.second;
			if (touchNodes.find(node) == touchNodes.end() && distance < minDistance)
			{
				minNode = node;
				minDistance = distance;
			}
		}
		return minNode;
	}

	void Dijkstra(GraphNode* head)
	{
		unordered_map<GraphNode*, int> distanceMap;
		distanceMap.insert(pair<GraphNode*, int>(head, 0));
		unordered_set<GraphNode*> selectNodes;
		GraphNode* minNode = getMinDistanceAndUnselectedNode(distanceMap, selectNodes);
		while (minNode != nullptr)
		{
			int distance = distanceMap[minNode];
			for (auto edge : minNode->edges)
			{
				GraphNode* toNode = edge->to;
				if (distanceMap.find(toNode) == distanceMap.end())
				{
					distanceMap.insert(pair<GraphNode*, int>(edge->to, min(distanceMap[toNode], distance + edge->weight)));
				}
			}
			selectNodes.insert(minNode);
			minNode = getMinDistanceAndUnselectedNode(distanceMap, selectNodes);
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
