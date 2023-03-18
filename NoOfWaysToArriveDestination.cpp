#include<iostream>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution{
public:
    int countPaths(int n, vector<vector<int>>& roads){
        vector<pair<int, int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e9), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)(1e9 + 7);
        pq.push({0, 0}); 
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgWt = it.second;

                if(dis+edgWt < dist[adjNode]){
                    dist[adjNode] = dis + edgWt;
                    pq.push({dis+edgWt, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis+edgWt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

int main(){
    

    return 0;
}