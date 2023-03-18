#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        int indegree[V] = {0};
        for(int i=0; i<V; i++){
            for(auto a: adj[i]){
                indegree[a]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto a: adj[node]){
                indegree[a]--;
                if(indegree[a]==0){
                    q.push(a);
                }
            }
        }
        return topo;
    }
};

int main(){
    

    return 0;
}