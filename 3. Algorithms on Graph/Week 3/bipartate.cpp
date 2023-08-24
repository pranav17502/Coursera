#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool checkBipartate(vector<vector<int>> &adj){
    vector<int> d(adj.size(), -1);
    queue<int> q;
    q.push(0);
    d[0] = 1;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        for(int i = 0 ; i < adj[n].size() ; i ++){
            int v = adj[n][i];
            if(d[v] == -1){
                q.push(v);
                d[v] = 1 - d[n];
            }
            if(d[n] == d[v])
                return false;
        }
    }
    return true;
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
    cout<<checkBipartate(adj);
    return 0;
}