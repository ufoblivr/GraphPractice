#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
public:
    bool isPossible(int V, vector<pair<int, int>>& prereq){
        vector<int> adj[V];
        for (auto a : prereq) {
			adj[a.first].push_back(a.second);
		}

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

        if(topo.size()==V) return true;

        return false;
    }
};

int main(){
    

    return 0;
}