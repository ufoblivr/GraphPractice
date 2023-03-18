#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// FUNCTION TO DETECT CYCLE IN AN UNDIRECTED GRAPH
bool detect(int src, vector<int> adj[], int visited[]){
    visited[src] = 1;
    queue<pair<int, int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode: adj[node]){
            if(!visited[adjacentNode]){
                visited[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if(parent != adjacentNode){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    int visited[V] = {0};
    for(int i=0; i<V; i++){
        if(!visited[i]){
            if(detect(i, adj, visited)) return true;
        }
    }
    return false;
}

int main(){
    

    return 0;
}