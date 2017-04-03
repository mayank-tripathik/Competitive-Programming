/*
 * Problem : https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2021
 * Solution: Simple bipartite problem where we have to first search for odd cycle. If odd cycle is there then
 * no solution is possible. Odd cycle can be checked by checking if graph is not bipartite. If it is bipartite then return
 * the minimum among number of black and white nodes
 */


/*
 * In this solution number of nodes at each level is calculated and they are summed at odd and even positions. 
 * Minimum of both is answer if no odd cycle exist
 */
 
#include<bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
vector<int> n_nodes;
bool bfs1(vector<vector<int> > &graph, int u){
    int n=graph.size();
    vector<bool> visited(n,false);
    vector<int> color(n,-1);
    queue<int> q;
    q.push(u);
    visited[u]=false;
    color[u]=0;
    bool has_odd_cycle=false;
    while(!q.empty() && !has_odd_cycle){
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            if(color[v]==color[u]){
                has_odd_cycle=true;
                break;
            }
            else{
                if(!visited[v]){
                    q.push(v);
                    color[v]=color[u] xor 1;
                    visited[v]=true;
                }
            }
        }
    }
    if(has_odd_cycle)
        return true;
    else
        return false;
}

int bfs2(vector<vector<int> > &graph, int u,vector<bool> &visited){
    int n=graph.size();
    vector<int> level(n,0);
    n_nodes.clear();
    n_nodes.resize(200,0);
    queue<int> q;
    q.push(u);
    visited[u]=true;
    level[u]=0;
    n_nodes[0]++;
    int max_level=0;
    while(!q.empty()){
        int u=q.front();
        //cout<<"popped:"<<u<<endl;
        q.pop();
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            if(!visited[v]){
                q.push(v);
                //cout<<"pushed:"<<v<<endl;
                level[v]=level[u]+1;
                visited[v]=true;
                if(level[v]>max_level)
                    max_level=level[v];
                n_nodes[level[v]]++;
            }
        }
    }
    return max_level;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int nodes,edges;
        cin>>nodes>>edges;
        vector<vector<int> > graph(nodes);
        vector<int> degree(nodes,0);
        for(int i=0;i<edges;i++){
            int u,v;
            cin>>u>>v;
            degree[u]++;
            degree[v]++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }        
        if(!bfs1(graph,0))
        {
            int counter=0;
            vector<bool> visited(nodes,false);
            for(int i=0;i<nodes;i++){
                if(!visited[i]){
                    int max_level=bfs2(graph,i,visited);
                    if(max_level==0){
                        counter++;
                    }
                    else
                    {
                        int l=0,m=1,sum1=0,sum2=0;
                        while(l<=max_level){
                            sum1+=n_nodes[l];
                            //cout<<"s1:"<<sum1<<endl;
                            l=l+2;
                        }
                        while(m<=max_level){
                            sum2+=n_nodes[m];
                            //cout<<"s2:"<<sum2<<endl;
                            m=m+2;
                        }
                        counter+=min(sum1,sum2);
                    }
                    
                }
            }
            cout<<counter<<endl;
        }
        else
            cout<<"-1"<<endl;
    }
}
 
