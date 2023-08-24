#include<iostream>
#include<vector>
using namespace std;

void explore(vector<vector<int>> &adj, vector<int> &visited, int node, bool &found){
    visited[node] = 1;
    for(int i = 0 ; i < adj[node].size() ; i ++){
        if(!visited[adj[node][i]])
            explore(adj, visited, adj[node][i], found);
        if(visited[adj[node][i]] == 1)  
            found = true;
    }
    visited[node] = 2;
    return;
}

int acyclic(vector<vector<int>> &adj){
    vector<int> visited(adj.size(), 0);
    vector<int> recStack(adj.size(), 0);
    bool found = true;
    for(int i = 0 ; i < adj.size() ; i ++){
        if(visited[i] == 0)
            found = false;
            explore(adj, visited, i, found);
            if(found)
                return 1;
    }
    return 0;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0 ; i < e ; i ++){
        int x, y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
    }
    cout<<acyclic(adj);
    return 0;
}