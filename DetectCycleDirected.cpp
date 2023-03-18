#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
    bool isCyclic(int V, vector<int> adj[]){
        int indegree[V] = {0};
        for(int i=0; i<V; i++){
            for(auto a: adj[i]){
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto a: adj[node]){
                indegree[a]--;
                if(indegree[a]==0){
                    q.push(a);
                }
            }
        }
        if(cnt==V) return false;

        return true;
    }
};

int main(){
    

    return 0;
}