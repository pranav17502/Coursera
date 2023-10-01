#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;

struct Node{
    int parent, rank;
    int x, y;
    Node(int a, int b, int c = -1, int d = 0){
        x = a;
        y = b;
        parent = c;
        rank = d;
    }
};

struct Edge{
    int u, v;
    double weight;
    Edge(int a, int b, double c){
        u = a;
        v = b;
        weight = c;
    }
};

bool comp(Edge a, Edge b){
    return a.weight < b.weight;
}

void make_set(int i, vector<Node> &nodes, vector<int> &x, vector<int> &y){
    nodes.push_back(Node(x[i], y[i], i));
}

double weight(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int Find(int i, vector<Node> &nodes){
    if(i != nodes[i].parent)
        nodes[i].parent = Find(nodes[i].parent, nodes);
    return nodes[i].parent;
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
                nodes[r2].rank ++;
        }
    }
}

double Union_Count(vector<int> &x, vector<int> &y, int d){
    int union_num = 0;
    int n = x.size();
    vector<Node> nodes;
    for(int i = 0 ; i < n ; i ++)
        make_set(i, nodes, x, y);

    vector<Edge> edges;
    for(int i = 0 ; i < n; i++){
        for(int j = i+1 ; j < n ; j ++)
            edges.push_back(Edge(i, j, weight(x[i], y[i], x[j], y[j])));
    }
    sort(edges.begin(), edges.end(), comp);
    for(int i = 0 ; i < edges.size() ; i ++){
        Edge curr_edge = edges[i];
        int u = curr_edge.u, v = curr_edge.v;
        if(Find(u, nodes) != Find(v, nodes)){
            union_num++;
            Union(u, v, nodes);
        }
        if(union_num > n-d)
            return curr_edge.weight;
    }
    return union_num;
}


int main(){
    int n, d;
    cin>>n;
    vector<int> x(n), y(n);
    for(int i = 0 ; i < n ; i ++)
        cin>>x[i]>>y[i];
    cin>>d;
    cout<<setprecision(10)<<Union_Count(x, y, d)<<endl;
    return 0;
}