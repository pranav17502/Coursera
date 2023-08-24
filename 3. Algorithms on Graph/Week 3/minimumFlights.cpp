#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int minimumFlight(vector<vector<int>> &adj, int a, int b){
    if(a == b)
        return 0;
    vector<int> d(adj.size(), -1);
    queue<int> q;
    q.push(a);
    d[a] = 0;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        for(int i = 0 ; i < adj[n].size() ; i ++){
            if(d[adj[n][i]] == -1){
                q.push(adj[n][i]);
                d[adj[n][i]] = d[n] + 1;
            }
        }
    }
    return d[b];
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
    int a, b;
    cin>>a>>b;
    cout<<minimumFlight(adj, a-1, b-1);
    return 0;
}