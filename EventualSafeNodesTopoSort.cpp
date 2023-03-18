#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]){
        vector<int> adjRev[V];
        int indegree[V] = {0};
        for(int i=0; i<V; i++){
            for(auto a: adj[i]){
                 adjRev[a].push_back(i);
                 indegree[i]++;
            }
        }
    }
};

int main(){
    

    return 0;
}