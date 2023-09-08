#include<iostream>
#include<vector>
#include<limits>
using namespace std;


const int inf = numeric_limits<int>::max();


bool negativeCycle(vector<vector<int>> &adj, vector<vector<int>> &rate){
    vector<int> dist(adj.size(), inf);
    dist[0] = 0;
    for(int i = 0 ; i < adj.size(); i++){
        for(int j = 0 ; j < adj.size() ; j++){
            for(int k = 0 ; k < adj[j].size() ; k++){
                int v = adj[j][k];
                if((dist[j] != inf) && (dist[v] > dist[j] + rate[j][k])){
                    dist[v] = dist[j] + rate[j][k];
                    if(i == adj.size() - 1)
                        return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> rate(n, vector<int>());
    for(int i = 0 ; i < m ; i ++){
        int k, l, w;
        cin>>k>>l>>w;
        adj[k-1].push_back(l-1);
        rate[k-1].push_back(w);
    }    
    cout<<negativeCycle(adj, rate);
    return 0;
}