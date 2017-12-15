#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdio>

using namespace::std;

struct MaximumFlow{
	struct Edge{
		int to;
		int capacity;
		Edge* reverse;
		Edge(int to, int capacity)
			:to(to), capacity(capacity)
		{
		}
	};

	int vertex_num;
	int source, sink;

	vector<vector<Edge*> > graph;
	vector<bool> check;

	MaximumFlow(int n, int source, int sink)
		:vertex_num(n), source(source), sink(sink)
	{
		graph.resize(n);
		check.resize(n);
	};

	void add_edge(int u, int v, int capacity)
	{
		Edge* src = new Edge(v, capacity);
		Edge* sink = new Edge(u, 0);
		src->reverse = sink;
		sink->reverse = src;
		graph[u].push_back(src);
		graph[v].push_back(sink);
	}
	void add_edge_from_source(int v, int capacity)
	{
		add_edge(source, v, capacity);
	}
	void add_edge_to_sink(int u, int capacity)
	{
		add_edge(u, sink, capacity);
	}

	int dfs(int vertex, int capacity)
	{
		if(check[vertex])
			return 0;
		check[vertex] = true;
		if(vertex == sink)	//reached to end, return capacity
			return capacity;
		for(int i = 0; i < graph[vertex].size(); i++)
		{
			if(graph[vertex][i]->capacity > 0)	//if it's possible to flow the edge
			{
				int minCap = graph[vertex][i]->capacity;
				if(capacity != 0 && capacity < minCap)
					minCap = capacity;			//find minimum flow

				int flowed = dfs(graph[vertex][i]->to, minCap);
				if(flowed)	//if flowed
				{
					graph[vertex][i]->capacity -= flowed;	//subtract from
					graph[vertex][i]->reverse->capacity += flowed;	//add to
					return flowed;
				}
			}
		}
		return 0;
	}

	int flow()
	{
		int result = 0;
		while(true)
		{
			fill(check.begin(), check.end(), false);
			int flowed = dfs(source, 0);
			if(flowed == 0)
				break;
			result += flowed;
		}

		return result;	//flowed result
	}
};

int main(void)
{
	int man_count, work_count;
	scanf("%d %d", &man_count, &work_count);
	
	MaximumFlow mf(man_count+work_count+2, 0, man_count+work_count+1);
	//index 0 is source, index man_count+work_count+1 is sink
	
	for(int i = 1; i <= man_count; i++)
	{
		int work_amount;
		scanf("%d",&work_amount);
	
		for(int j = 0; j < work_amount; j++)
		{
			int work;
			scanf("%d",&work);
			mf.add_edge(i, man_count+work, 1);	
		}
	}

	for(int i = 1; i <= man_count; i++)
	{
		mf.add_edge_from_source(i, 2);
	}
	for(int i = 1; i <= work_count; i++)
	{
		mf.add_edge_to_sink(man_count+i, 1);
	}
	printf("%d",mf.flow());
}