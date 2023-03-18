#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
private:
    bool dfs(int node, int col, int color[], vector<int> adj[]){
        color[node] = col;

        for(auto a: adj[node]){
            if(color[a]==-1){
                if(dfs(a, col, color, adj)==false){
                    return false;
                }
            }
            else if(color[a]==col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(int V, vector<int> adj[]){
        int color[V];
        for(int i=0; i<V; i++){
            color[i] = -1;
        }
        for(int i=0; i<V; i++){
            if(color[i]==1){
                if(dfs(i, 0, color, adj)==false){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    

    return 0;
}