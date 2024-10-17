#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        int nodes;
        int edges;
        graph(int n, int m) : nodes(n), edges(m) {}

    vector<vector<pair<int,int>>> AdjListUndirected(){
        vector<vector<pair<int,int>>> adjList(nodes+1);
        cout << "Enter the edges between two nodes with default weight : " << endl;
        for(int i = 0;i < edges;i++){
            int node1, node2;
            cin >> node1 >> node2;
            adjList[node1].push_back({node2, 1});
            adjList[node2].push_back({node1, 1});
        }
        cout << endl;
        for(int i = 1;i < adjList.size();i++){
            cout << i << "-->";
            for(int j = 0;j < adjList[i].size();j++){
                cout << " {" << adjList[i][j].first << ", " << adjList[i][j].second << "}" << " ";
            }
            cout << endl;
        }
        return adjList;
    }

    vector<vector<pair<int,int>>> AdjListDirected(){
        vector<vector<pair<int,int>>> adjList(nodes+1);
        cout << "Enter the edges between two nodes with default weight : " << endl;
        for(int i = 0;i < edges;i++){
            int node1, node2;
            cin >> node1 >> node2;
            adjList[node1].push_back({node2, 1});
        }
        cout << endl;
        for(int i = 1;i <= nodes;i++){
            cout << i << "-->";
            for(int j = 0;j < adjList[i].size();j++){
                cout << " {" << adjList[i][j].first << ", " << adjList[i][j].second << "}" << " ";
            }
            cout << endl;
        }
        return adjList;
    }

    vector<vector<pair<int,int>>> AdjListUndirWeighted(){
        vector<vector<pair<int,int>>> adjList(nodes + 1);
        cout << "Enter the edges between two nodes with weight : " << endl;
        for(int i = 0;i < edges;i++){
            int node1, node2, weight;
            cin >> node1 >> node2 >> weight;
            adjList[node1].push_back({node2, weight});
            adjList[node2].push_back({node1, weight});
        }
        cout << endl;
        for(int i = 1;i <= nodes;i++){
            cout << i << "-->";
            for(int j = 0;j < adjList[i].size();j++){
                cout << " {" << adjList[i][j].first << ", " << adjList[i][j].second << "}" << " ";
            }
            cout << endl;
        }
        return adjList;
    }

    vector<vector<pair<int,int>>> adjListDirWeighted(){
        vector<vector<pair<int,int>>> adjList(nodes + 1);
        cout << "Enter the edges between two nodes with weight : " << endl;
        for(int i = 0;i < edges;i++){
            int node1, node2, weight;
            cin >> node1 >> node2 >> weight;
            adjList[node1].push_back({node2, weight});
        }
        cout << endl;
        for(int i = 1;i <= nodes;i++){
            cout << i << "-->";
            for(int j = 0;j < adjList[i].size();j++){
                cout << " {" << adjList[i][j].first << ", " << adjList[i][j].second << "}" << " "; 
            }
            cout << endl;
        }
        return adjList;
    }

    void bfs(pair<int,int> start, vector<vector<pair<int,int>>> &adjList){
        cout << "BFS Traversal of the given Graph : " << endl;
        vector<bool> visited(nodes+1, false);
        queue<pair<int,int>> q;
        q.push(start);
        visited[start.first] = true;
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            cout << node.first << " ";
            for(int i = 0;i < adjList[node.first].size();i++){
                pair<int,int> val = adjList[node.first][i];
                if(!visited[val.first]){
                    visited[val.first] = true;
                    q.push(val);
                }
            }
        }
        cout << endl;
    }
    void dfsHelper(pair<int,int> start, vector<bool> &visited, vector<vector<pair<int,int>>> &adjList){
        visited[start.first] = true;
        cout << start.first << " ";
        for(int i = 0;i < adjList[start.first].size();i++){
            pair<int,int> val = adjList[start.first][i];
            if(!visited[val.first]){
                dfsHelper(val, visited, adjList);
            }
        }
        return;
    }
    void dfs(pair<int,int> start, vector<vector<pair<int,int>>> &adjList){
        cout << "DFS Traversal of the given Graph : " << endl;
        vector<bool> visited(nodes + 1, false);
        dfsHelper(start, visited, adjList);
    }
};
int main(){

    int n , m;
    cout << "Enter the number of Nodes & Edges in the graph --> " << endl;
    cin >> n >> m;
    graph g(n, m);

    cout << "Implement a Graph with " << g.nodes << " nodes & " << g.edges << " edges ---> " << endl;

    cout << "Implementation of Undirected Unweighted Adjacency List --> " << endl;
    vector<vector<pair<int,int>>> adjList1 = g.AdjListUndirected();
    g.bfs({1,adjList1[1][0].second}, adjList1);
    g.dfs({1,adjList1[1][0].second}, adjList1);
    cout << endl;

    // cout << "Implementation of Directed Unweighted Adjacency List --> " << endl;
    // vector<vector<pair<int,int>>> adjList2 = g.AdjListDirected();
    // cout << endl;

    // cout << "Implementation of Undirected Weighted Adjacency List --> " << endl;
    // vector<vector<pair<int,int>>> adjList3 = g.AdjListUndirWeighted();
    // cout << endl;

    // cout << "Implementation of Directed Weighted Adjacency List --> " << endl;
    // vector<vector<pair<int,int>>> adjList4 = g.adjListDirWeighted();
    // cout << endl;

}