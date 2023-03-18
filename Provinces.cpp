#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    void dfs(int node, vector<int> adjList[], int visited[]){
        visited[node] = 1;
        for(auto a: adjList[node]){
            if(!visited[a]){
                dfs(a, adjList, visited);
            }
        }
    }
public:
    int countProvinces(int V, vector<vector<int>> adj){
        vector<int> adjList[V];

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        int visited[V] = {0};
        int cnt = 0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, adjList, visited);
            }
        }
        return cnt;
    }
};

int main(){
    vector<vector<int>> adj {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

        
    Solution ob;
    cout << ob.countProvinces(3, adj) << endl;
        
    return 0;
}