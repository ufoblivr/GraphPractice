#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[]){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for(auto a: adj[node]){
            if(!vis[a]){
                if(dfsCheck(a, adj, vis, pathVis, check)==true){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[a]){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]){
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safeNodes;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }
        for(int i=0; i<V; i++){
            if(check[i]==1)
                safeNodes.push_back(i);
        }
    }
};

int main(){
    

    return 0;
}