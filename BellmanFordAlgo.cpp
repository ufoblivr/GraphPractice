#include<iostream>
#include<vector>

using namespace std;

// Since in a Graph of N nodes, in worst case you will take N-1 edges to 
// reach from first to the last, thereby we iterate for N-1 iterations.

class Solution{
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S){
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for(int i=0; i<V-1; i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    dist[v] = dist[u]+wt; 
                }
            }
        }
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                return {-1};
            }
        }
    }
};