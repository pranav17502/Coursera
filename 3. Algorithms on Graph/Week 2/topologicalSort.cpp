#include<iostream>
#include<vector>
using namespace std;

void explore(vector<vector<int>> &adj, int node, vector<int> &used, vector<int> &order){
    used[node] = 1;
    for(int i = 0 ; i < adj[node].size() ; i ++){
        if(!used[adj[node][i]])
            explore(adj, adj[node][i], used, order);
    }
    order.insert(order.begin(), node);
}

vector<int> topoSort(vector<vector<int>> &adj){
    vector<int> used(adj.size(), 0);
    vector<int> order;
    for(int i = 0 ; i < adj.size() ; i ++){
        if(!used[i])
            explore(adj, i, used, order);
    }
    return order;
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
    vector<int> sorted = topoSort(adj);
    for(int i = 0 ; i < sorted.size() ; i ++){
        cout<<sorted[i]+1<<" ";
    }
    return 0;
}