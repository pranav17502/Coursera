#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

const int inf = numeric_limits<int>::max();

struct Node {
  int index, d;
  Node(int a = 0, int b = 0): index(a), d(b) {}
};

struct cmp{
    bool operator()(Node a, Node b){
        return a.d > b.d;
    }
};

int distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t){
    vector<int> dist(adj.size(), inf);
    dist[s] = 0;
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push(Node(s, dist[s]));
    while(!pq.empty()){
        Node a = pq.top();
        pq.pop();
        int a_index = a.index, a_d = a.d;
        for(int i = 0 ; i < adj[a_index].size() ; i ++){
            int v = adj[a.index][i];
            if(dist[v] > dist[a_index] + cost[a_index][i]){
                dist[v] = dist[a_index] + cost[a_index][i];
                pq.push(Node(v, dist[v]));
            }
        }
    }
    if(dist[t] == inf)
        return -1;
    return dist[t];
}


int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> cost(n, vector<int>());
    for(int i = 0 ; i < m ; i ++){
        int k, l, w;
        cin>>k>>l>>w;
        adj[k-1].push_back(l-1);
        cost[k-1].push_back(w);
    }    
    int s, t;
    cin>>s>>t;
    s--;
    t--;
    cout<<distance(adj, cost, s, t);
    return 0;
}