#include"head.h"

template<typename V>
class UnionFind
{
public:
	struct Element
	{
	public:
		V value;

		Element(V value) : value(value) {}
	};

	unordered_map<V, Element*> elementMap;
	//key元素，value为该元素的父
	unordered_map<Element*, Element*> fatherMap;
	//key代表元素，value该集合的大小
	unordered_map<Element*, int> sizeMap;

	UnionFind(list<V> list)
	{
		for (V value : list)
		{
			element = Element(value);
			elementMap.insert(make_pair(value, element));
			fatherMap.insert(pair<Element*, Element*>(element, element));
			sizeMap.insert(pair<Element*, int>(element, 1));
		}
	}

	Element<V> findHead(Element<V> element)
	{
		stack<Element<V>> path;
		while (element != fatherMap[element])
		{
			path.push(element);
			element = fatherMap[element];
		}
		while (!path.empty())
		{
			fatherMap.emplace(path.top(), element);
			path.pop();
		}
		return element;
	}

	bool isSameSet(V a, V b)
	{
		if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
		{
			return findHead(elementMap[a]) == findHead(elementMap[b]);
		}
		return false;
	}

	void Union(V a, V b)
	{
		if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
		{
			Element<V> aF = findHead(elementMap[a]);
			Element<V> bF = findHead(elementMap[b]);
			if (aF != bF)
			{
				Element<V> big = sizeMap[aF] >= sizeMap[bF] ? aF : bF;
				Element<V> small = big == aF ? bF : aF;
				fatherMap.emplace(small, big);
				sizeMap.emplace(big, sizeMap[aF] + sizeMap[bF]);
				sizeMap.erase(small);
			}
		}
	}
};