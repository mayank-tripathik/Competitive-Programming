/*
 * Problem : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3497
 * Solution : Floyd warshall can be used to find distance between every node and calculate max from these distances
 */

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int floyd_warshall(vector<pair<P,int> > &graph, int nodes){
    int dist[nodes][nodes];
    int path[nodes][nodes];
    /*Initialising path and distance matrix*/
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            dist[i][j]=INT_MAX;
            path[i][j]=-1;
        }   
    }
    for(int i=0;i<nodes;i++)
        dist[i][i]=0;
    for(int i=0;i<graph.size();i++){
        int u=graph[i].first.first;
        int v=graph[i].first.second;
        int weight=graph[i].second;
        dist[u][v]=weight;
        path[u][v]=u;
    }
    for(int k=0;k<nodes;k++){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                    continue;
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }
    int max_gl=INT_MIN;
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            if(dist[i][j]>max_gl)
                max_gl=dist[i][j];
        }
    }
    return max_gl;
}
int main()
{
    int test=0;
    while(1)
    {
        int nodes,edges;
        cin>>nodes>>edges;       
        if(nodes==0 && edges==0)
            break;
        test++;
        cout<<"Network "<<test<<": ";
        unordered_map<string,int> mapping;
        int index=-1;
        vector<pair<P,int> > graph;
        for(int i=0;i<edges;i++){
            string u,v;
            cin>>u>>v;
            int x,y;
            if(mapping.find(u)!=mapping.end()){
                auto itr=mapping.find(u);
                x=(*itr).second;
            }
            else{
                index++;
                mapping.insert({u,index});
                x=index;
            }
            if(mapping.find(v)!=mapping.end()){
                auto itr=mapping.find(v);
                y=(*itr).second;
            }
            else{
                index++;
                mapping.insert({v,index});
                y=index;
            }
            graph.push_back({{x,y},1});
            graph.push_back({{y,x},1});
        }
        long long dista=floyd_warshall(graph,nodes);
        if(dista==INT_MAX)
            cout<<"DISCONNECTED"<<endl<<endl;
        else
            cout<<dista<<endl<<endl;
    }
    return 0;
}
