#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        int nodes;
        int edges;
        graph(int n, int m) : nodes(n) , edges(m) {}

    vector<vector<int>> AdjMatUndirected(){
        vector<vector<int>> adjMat(nodes + 1, vector<int> (nodes + 1));
        cout << "Enter the edges between two nodes with default weight : " << endl;
        for(int i = 0;i < edges;i++){
            int node1, node2;
            cin >> node1 >> node2;
            adjMat[node1][node2] = 1;
            adjMat[node2][node1] = 1;
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

    vector<vector<int>> AdjMatDirected(){
        vector<vector<int>> adjMat(nodes + 1, vector<int> (nodes + 1));
        cout << "Enter the edges between two nodes with default weight : " << endl;
        for(int i = 0;i < edges;i++){
            int node1, node2;
            cin >> node1 >> node2;
            adjMat[node1][node2] = 1;
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

    vector<vector<int>> AdjMatUndirWeighted(){
        vector<vector<int>> adjMat(nodes + 1, vector<int> (nodes + 1));
        cout << "Enter the edges between two nodes with weight : " << endl;
        for(int i = 0;i < edges;i++){
            int node1, node2, weight;
            cin >> node1 >> node2 >> weight;
            adjMat[node1][node2] = weight;
            adjMat[node2][node1] = weight;
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

    vector<vector<int>> AdjMatDirWeighted(){
        vector<vector<int>> adjMat(nodes + 1, vector<int> (nodes + 1));
        cout << "Enter the edges between two nodes with weight : " << endl;
        for(int i = 0;i < edges;i++){
            int node1, node2, weight;
            cin >> node1 >> node2 >> weight;
            adjMat[node1][node2] = weight;
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

    void bfs(int start, vector<vector<int>> &adjMat){
        cout << "BFS Traversal of the given Graph : " << endl;
        vector<bool> visited(nodes + 1, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout << node << " ";
            for(int i = node;i <= nodes;i++){
                if(adjMat[node][i] && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
    void dfsHelper(int start, vector<bool> &visited, vector<vector<int>> &adjMat){
        visited[start] = true;
        cout << start << " ";
        for(int i = start; i <= nodes;i++){
            if(adjMat[start][i] && !visited[i]){
                dfsHelper(i, visited, adjMat);
            }
        }
        return;
    }
    void dfs(int start, vector<vector<int>> &adjMat){
        cout << "DFS Traversal of the given Graph : " << endl;
        vector<bool> visited(nodes + 1, false);
        dfsHelper(start, visited, adjMat);
    }
};
int main(){
    
    int n , m;
    cout << "Enter the number of Nodes & Edges in the graph --> " << endl;
    cin >> n >> m;
    graph g(n, m);

    cout << "Implement a Graph with " << g.nodes << " nodes & " << g.edges << " edges ---> " << endl; 

    cout << "Implementation of Undirected Unweighted Adjacency matrix --> " << endl;
    vector<vector<int>> adjMat1 = g.AdjMatUndirected();
    g.bfs(1, adjMat1);
    g.dfs(1,adjMat1);
    cout << endl;

    cout << "Implementation of Directed Unweighted Adjacency matrix --> " << endl;
    vector<vector<int>> adjMat2 = g.AdjMatDirected();
    g.bfs(1, adjMat2);
    g.dfs(1, adjMat2);
    cout << endl;

    cout << "Implementation of Undirected Weighted Adjacency matrix --> " << endl;
    vector<vector<int>> adjMat3 = g.AdjMatUndirWeighted();
    g.bfs(1, adjMat3);
    g.dfs(1, adjMat2);
    cout << endl;

    cout << "Implementation of Directed Weighted Adjacency matrix --> " << endl;
    vector<vector<int>> adjMat4 = g.AdjMatDirWeighted();
    g.bfs(1, adjMat4);
    g.dfs(1, adjMat2);
    cout << endl;

    

}