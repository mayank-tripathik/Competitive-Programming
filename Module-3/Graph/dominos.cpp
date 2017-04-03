/*
 * Problem :
 * Solution : Use topological sort to get those domino that are not dependent on anyone. Now apply dfs on each domino one by one
 * to sort out all dominos that would fall and increase the count for every domino on which dfs is applied.
 * /
 
 #include<bits/stdc++.h>
using namespace std;

vector<int> topo;
void dfs1(vector<vector<int> > &graph, int u, vector<bool> &visited){
    visited[u]=true;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(!visited[v])
            dfs1(graph,v,visited);
    }
    topo.push_back(u);
}
void dfs2(vector<vector<int> > &graph, int u, vector<bool> &visited){
    visited[u]=true;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(!visited[v])
            dfs2(graph,v,visited);
    }
}

void topological(vector<vector<int> > &graph){
    int nodes=graph.size();
    vector<bool> visited(nodes,false);
    topo.clear();
    int counter=0;
    for(int i=1;i<nodes;i++){
        if(!visited[i]){
            dfs1(graph,i,visited);
        }           
    }
    visited.clear();
    visited.resize(nodes,false);
    for(int i=topo.size()-1;i>=0;i--){
        int v=topo[i];
        if(!visited[v]){
            counter++;
             dfs2(graph,v,visited);
        }           
    }
    cout<<counter<<endl;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        vector<vector<int> > graph(n+1);
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
        }
        topological(graph);
    }
}
