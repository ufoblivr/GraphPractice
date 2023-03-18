#include<iostream>
#include<vector>
// #include<queue>
// using namespace std;

// class Solution{
// public:
//     int spanningTree(int V, vector<vector<int>>& adj[]){
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         vector<int> vis(V, 0);
//         // {wt, node}
//         pq.push({0, 0});
//         int sum = 0;
//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
//             int node = it.second;
//             int wt = it.first;

//             if(vis[node]==1) continue;

//             vis[node] = 1;
//             sum += wt;

//             for(auto iter: adj[node]){
//                 int adjNode = iter[0];
//                 int edWt = iter[1];
//                 if(!vis[adjNode]){
//                     pq.push({edWt, adjNode});
//                 }
//             }
//         }
//         return sum;
//     }
// };

int main(){
    

    return 0;
}