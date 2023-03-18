#include<iostream>
#include<vector>
using namespace std;

class Solution {
  private:
    void dfs(int node, vector<int> adj[], int visited[], vector<int> &list){
        visited[node] = 1;
        list.push_back(node);

        for(auto a: adj[node]){
            if(!visited[a]){
                dfs(a, adj, visited, list);
            }
        }
    }
  public:
    vector<int> DFSTraversal(int start, int V, vector<int> adj[]){
        int visited[V] = {0};
        vector<int> list;
        dfs(start, adj, visited, list);
        return list;
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
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector <int> ans = obj.DFSTraversal(2, 5, adj);
    printAns(ans);

    return 0;
}