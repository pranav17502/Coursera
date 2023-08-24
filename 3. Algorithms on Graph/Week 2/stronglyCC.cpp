#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<vector<int>> reverseEdge(vector<vector<int>> adj){
    vector<vector<int>> radj(adj.size(), vector<int>());
    for(int i = 0 ; i < adj.size() ; i ++){
        for(int j = 0 ; j < adj[i].size() ; j ++)
            radj[adj[i][j]].push_back(i);
    }
    return radj;
}

void explore(vector<vector<int>> &adj, int node, vector<int> &visited, stack<int> &ts){
    visited[node] = 1;
    for(int i = 0 ; i < adj[node].size() ; i ++){
        if(!visited[adj[node][i]])
            explore(adj, adj[node][i], visited, ts);
    }
    ts.push(node);
    return;
}

int SCC(vector<vector<int>> &adj){
    stack<int> ts;
    int results = 0;
    vector<int> visited(adj.size(), 0);
    for(int i = 0 ; i < adj.size() ; i ++)
        if(!visited[i])
            explore(adj, i, visited, ts);
    
    for(int i = 0 ; i < adj.size() ; i ++)
        visited[i] = 0;
    vector<vector<int>> radj = reverseEdge(adj);
    
    while(!ts.empty()){
        int node = ts.top();
        ts.pop();
        if(!visited[node]){
            stack<int> s;
            explore(radj, node, visited, s);
            results++;
        }
    }
    return results;
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
    cout<<SCC(adj);
    return 0;
}