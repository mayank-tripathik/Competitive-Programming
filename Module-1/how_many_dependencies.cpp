/*
 * Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1867
 * Approach : Simple DFS on every node to calculate each node dependecies and then asnwering node whose dependencies are maximum 
 */


#include <bits/stdc++.h>
using namespace std;

int depth;

void dfs(vector<list<int> > &graph, vector<bool> &visited, int u)
{
    visited[u]=true;
    depth++;
    for(auto itr=graph[u].begin();itr!=graph[u].end();itr++){
        int v=(*itr);
        if(!visited[v])
        {
            dfs(graph,visited,v);
        }
            
    }
}


int main()
{
    while(1)
    {
        int nodes,maxDepth,min_node;
        cin>>nodes;
        if(nodes==0)
            break;
        vector<list<int> > graph(nodes+1);
        for(int i = 1 ; i <=nodes ; i++ )
        {
            int u=i;
            int depen;
            cin>>depen;
            while(depen--){
                int v;
                cin>>v;
                graph[u].push_back(v);
            }
        }
        for(int i = nodes ; i >=1 ; i-- )
        {
            vector<bool> visited(nodes+1,false);
            depth=0;
            dfs(graph,visited,i);
            if(depth>=maxDepth){
                maxDepth=depth;
                min_node=i;
            }
        }
        cout<<min_node<<endl;
    }
}
