#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int nodes;
        int edges;
        bool isDirected;
        Graph() {}
        Graph(int nodes, int edges, bool isDirected){
            this->nodes = nodes;
            this->edges = edges;
            this->isDirected = isDirected;
        }

    //* -------------------------------------- Implementation of graph using Adjacency Matrix --------------------------------------
    
    vector<vector<int>>  AdjacencyMatrix(){
        cout << "Enter the edges between node1 --> node2 :" << endl;
        vector<vector<int>> adjMat(nodes + 1, vector<int> (nodes + 1, 0));
        for(int i = 0;i < edges;i++){
            int u;
            pair<int,int> v;
            cin >> u >> v.first >> v.second;
            if(isDirected){
                adjMat[u][v.first] = v.second;
            }else{
                adjMat[u][v.first] = v.second;
                adjMat[v.first][u] = v.second;
            }
        }
        cout << endl;
        for(int i = 1;i <= nodes;i++){
            for(int j = 1;j <= nodes;j++){
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
        return adjMat;
    }
    
    //* BFS Traversal for Adjacency Matrix
    void BFS_AdjMat(int u, vector<vector<int>> &adjMat){
        cout << "BFS Traversal of given Adjacency Matrix --> " << endl;
        vector<bool> visited(nodes + 1, false);
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            cout << v << " ";
            for(int i = v;i <= nodes;i++){
                if(adjMat[v][i] && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
    
    //* DFS Traversal for Adjacency Matrix
    void dfs1(int u, vector<bool> &visited, vector<vector<int>> &adjMat){
        visited[u] = true;
        cout << u << " ";
        for(int i = u;i <= nodes;i++){
            if(adjMat[u][i] && !visited[i]){
                dfs1(i, visited, adjMat);
            }
        }
        return;
    }
    void DFS_AdjMat(int u, vector<vector<int>> &adjMat){
        cout << "DFS Traversal of given Adjacency Matrix --> " << endl;
        vector<bool> visited(nodes + 1, false);
        dfs1(u, visited, adjMat);
        cout << endl;
    }


    //* -------------------------------------- Implementation of Graph using Adjacency List --------------------------------------

    vector<vector<pair<int,int>>> AdjacencyList(){
        cout << "Enter the edges between node1 --> node2 :" << endl;
        vector<vector<pair<int,int>>> adjList(nodes + 1);
        for(int i = 0;i < edges;i++){
            int u;
            pair<int,int> v;
            cin >> u >> v.first >> v.second;
            if(isDirected){
                adjList[u].push_back({v.first, v.second});
            }else{
                adjList[u].push_back({v.first, v.second});
                adjList[v.first].push_back({u, v.second});
            }
        }
        cout << endl;
        for(int i = 1;i <= nodes;i++){
            cout << i << " --> ";
            for(int j = 0;j < adjList[i].size();j++){
                cout << "{" << adjList[i][j].first << ", " << adjList[i][j].second << "}" << " ";
            }
            cout << endl;
        }
        return adjList;
    }
    //* BFS Traversal of Adjacency List -->
    void BFS_AdjList(pair<int,int> u, vector<vector<pair<int,int>>> &adjList){
        cout << "BFS Traversal of given Adjacency List --> " << endl;
        vector<bool> visited(nodes + 1, false);
        queue<pair<int,int>> q;
        q.push(u);
        visited[u.first] = true;
        while(!q.empty()){
            pair<int,int> v = q.front();
            q.pop();
            cout << v.first << " ";
            for(int i = 0;i < adjList[v.first].size();i++){
                pair<int,int> p = adjList[v.first][i];
                if(!visited[p.first]){
                    visited[p.first] = true;
                    q.push(p);
                }
            }
        }
        cout << endl;
    }
    
    //* DFS Traversal of Adjacency List -->
    void dfs2(pair<int,int> u, vector<bool> &visited, vector<vector<pair<int,int>>> &adjList){
        visited[u.first] = true;
        cout << u.first << " ";
        for(int i = 0;i < adjList[u.first].size();i++){
            pair<int,int> p = adjList[u.first][i];
            if(!visited[p.first]){
                dfs2(p, visited, adjList);
            }
        }
        return;
    }
    void DFS_AdjList(pair<int,int> u, vector<vector<pair<int,int>>> &adjList){
        cout << "DFS Traversal of given Adjacency List --> " << endl;
        vector<bool> visited(nodes + 1, false);
        dfs2(u, visited, adjList);
        cout << endl;
    }
    

    //* Function to Take Input of no.of nodesm edges and isGraphDirected
    void takeInput(int &n, int &m, int &d){
        cout << "Enter the Number of Nodes : " << " ";
        cin >> n;
        cout << "Enter the Number of Edges : " << " ";
        cin >> m;
        cout << "Enter '1' to make graph directed or '0' to make graph undirected :" << " ";
        cin >> d;
    }
};
int main(){
    int n , m, d;
    Graph* g;

    cout << "Enter the Number of nodes and edges to form a Adjacency matrix representaion of Graph --> " << endl; 
    g->takeInput(n, m, d);
    Graph g1(n,m,d);
    vector<vector<int>> adjMat = g1.AdjacencyMatrix();
    g1.BFS_AdjMat(1, adjMat);
    g1.DFS_AdjMat(1, adjMat);

    cout << "Enter the Number of nodes and edges to form a Adjacency List representation of Graph --> " << endl;
    g->takeInput(n, m, d);
    Graph g2(n,m,d);
    vector<vector<pair<int,int>>> adjList = g2.AdjacencyList();
    g2.BFS_AdjList({1, adjList[1][0].second}, adjList);
    g2.DFS_AdjList({1, adjList[1][0].second}, adjList);
    
    return 0;
}