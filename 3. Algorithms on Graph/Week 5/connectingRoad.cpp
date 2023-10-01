#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;

struct Node{
    int parent;
    int rank;
    int x, y;
    Node(int a, int b, int c = -1, int d = 0){
        x = a;
        y = b;
        parent = c;
        rank = d;
    }
};

struct Edges{
    int u, v;
    double weight;
    Edges(int a, int b, double c){
        u = a;
        v = b;
        weight = c;
    }
};

bool comp(Edges a, Edges b){
    return a.weight < b.weight;
}

void make_set(int i, vector<Node> &nodes, vector<int> &x, vector<int> &y){
    nodes.push_back(Node(x[i], y[i], i));
}

double weight(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int Find(int u, vector<Node> &nodes){
    if(u != nodes[u].parent)
        nodes[u].parent = Find(nodes[u].parent, nodes);
    return nodes[u].parent;
}

void Union(int u, int v, vector<Node> &nodes){
    int r1 = Find(u, nodes);
    int r2 = Find(v, nodes);
    if(r1 != r2){
        if(nodes[r1].rank > nodes[r2].rank)
            nodes[r2].parent = r1;
        else{
            nodes[r1].parent = r2;
            if(nodes[r1].rank == nodes[r2].rank)
                nodes[r2].rank++;
        }
    }
}

double minimum_dist(vector<int> &x, vector<int> &y){
    double results = 0;
    int n = x.size();
    vector<Node> nodes;
    for(int i = 0 ; i < n ; i ++)
        make_set(i, nodes, x, y);
    
    vector<Edges> edges;
    for(int i = 0 ; i < n ; i ++){
        for(int j = i+1 ; j < n ; j ++)
            edges.push_back(Edges(i, j, weight(x[i], y[i], x[j], y[j])));
    }

    sort(edges.begin(), edges.end(), comp);
    for(int i = 0 ; i < edges.size() ; i ++){
        Edges curr_edge = edges[i];
        int u = curr_edge.u, v = curr_edge.v;
        if(Find(u, nodes) != Find(v, nodes)){
            results += curr_edge.weight;
            Union(u, v, nodes);
        }
    }
    return results;
}

int main(){
    int n;
    cin>>n;
    vector<int> x(n), y(n);
    for(int i = 0 ; i < n ; i ++)
        cin>>x[i]>>y[i];
    
    cout<<setprecision(10)<<minimum_dist(x, y)<<endl;
    return 0;
}