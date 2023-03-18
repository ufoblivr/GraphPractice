#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
    int cheapestFlights(int n, vector<vector<int>>& flights, int src, int dst, int K){
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        // {stops, {node, cost}}
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > K) continue;
            for(auto iter: adj[node]){
                int adjNode = iter.first;
                int edgWt = iter.second;
                
                if(cost + edgWt < dist[adjNode] && stops<=K){
                    dist[adjNode] = cost + edgWt;
                    q.push({stops+1, {adjNode, cost+edgWt}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};

int main(){
    

    return 0;
}