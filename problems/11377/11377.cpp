#include<cstdio>
#include<vector>
#include<iostream>

using namespace::std;
struct MaximumFlow
{
    struct Edge
    {
        int to;
        int capacity;
        Edge* reverse;

        Edge(int to, int capacity)
            :to(to), capacity(capacity)
        {}
    };

    int source, sink, vertex_num;

    vector<vector<Edge*> > graph;
    vector<bool> check;

    MaximumFlow(int vertex_num, int source, int sink)
        :vertex_num(vertex_num), source(source), sink(sink)
    {
        graph.resize(vertex_num);
        check.resize(vertex_num);
    }

    void add_edge(int u, int v, int capacity)
    {
        Edge* origin = new Edge(v, capacity);
        Edge* reverse = new Edge(u, 0);
        origin->reverse = reverse;
        reverse->reverse = origin;
        graph[u].push_back(origin);
        graph[v].push_back(reverse);
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
        
        if(vertex == sink)
            return capacity;

        
        for(int i = 0; i < graph[vertex].size(); i++)
        {
            if(graph[vertex][i]->capacity > 0)
            {
                int min_capacity = graph[vertex][i]->capacity;
                if(capacity != 0 && capacity < min_capacity)
                    min_capacity = capacity;

                int flowed = dfs(graph[vertex][i]->to, min_capacity);
                if(flowed)
                {
                    graph[vertex][i]->capacity -= flowed;
                    graph[vertex][i]->reverse->capacity += flowed;
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
            int flow = dfs(source, 0);
            if(flow == 0)
                break;
            result+=flow;
        }
        return result;
    }
};

int main(void)
{
    int man_count, work_count;
    scanf("%d %d", &man_count, &work_count);

    int expand;
    scanf("%d",&expand);
    
    int interchange = 1;
    MaximumFlow mf(man_count+work_count+interchange+2, 0, man_count+work_count+interchange+1);

    mf.add_edge(0, interchange, expand);
    for(int i = 1+interchange; i <= man_count+interchange; i++)
    {
        mf.add_edge(interchange, i, 1);
    }

    for(int i = 1+interchange; i <= man_count+interchange; i++)
    {
        int work_amount;
        scanf("%d",&work_amount);

        for(int j = 0; j < work_amount; j++)
        {
            int work;
            scanf("%d",&work);

            mf.add_edge(i, man_count+work+interchange, 1);
        }
    }

    for(int i = 1+interchange; i <= man_count+interchange; i++)
    {
        mf.add_edge_from_source(i, 1);
    }
    for(int i = 1+interchange; i <= work_count+interchange; i++)
    {
        mf.add_edge_to_sink(man_count+i, 1);
    }

    printf("%d",mf.flow());
}