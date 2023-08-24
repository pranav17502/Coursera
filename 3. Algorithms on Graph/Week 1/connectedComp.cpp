#include<iostream>
#include<vector>
using namespace std;

void explore(vector<vector<int>> adj, int x, vector<int> &visited){
    visited[x] = 1;
    for(int i = 0 ; i < adj[x].size() ; i ++){
        if(!visited[adj[x][i]])
            explore(adj, adj[x][i], visited);
    }
    return;
}

int cc(vector<vector<int>> adj){
    int res = 0;
    vector<int> visited(adj.size());
    for(int i = 0 ; i < adj.size() ; i ++){
        if(!visited[i]){
            res++;
            explore(adj, i, visited);
        }
    }
    return res;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0 ; i < e ; i ++){
        int x, y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    cout<<cc(adj);
    return 0;
}