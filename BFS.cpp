#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:    
    vector<int> BFSTraversal(int start, int V, vector<int> adj[]){
        int visited[V] = {0};
        visited[start] = 1;
        queue<int> q;
        q.push(start);
        vector<int> bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
    
            for(auto a: adj[node]){
                if(!visited[a]){
                    visited[a] = 1;
                    q.push(a);
                }
            }
        }
        return bfs;
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector<int> adj[5];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.BFSTraversal(3, 5, adj);
    printAns(ans);

    return 0;
}