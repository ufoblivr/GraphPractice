#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
private:
    // Works for multiple components as well
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
                if(indegree[a]==0) 
                    q.push(a);
            }
        }

        return topo;
    }
public:
    string findOrder(string dict[], int N, int K){
        vector<int> adj[K];
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int ptr = 0; ptr<len; ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for(auto a: topo){
            ans  = ans + char(a + 'a');
        }

        return ans;
    }
};

int main(){
    

    return 0;
}