#include<iostream>
#include<queue>
using namespace std;

// FASTER ONE

class Solution{
private:
    bool check(int start, int V, vector<int> adj[], int color[]){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto a: adj[node]){
                if(color[a] == -1){
                    color[a] = !color[node];
                    q.push(a);
                }
                else if(color[a] == color[node]){
                    return false;
                }
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
            if(color[i] == -1){
                if(check(i, V, adj, color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    vector<int> adj[4];

    addEdge(adj, 0, 2);
   	addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

	Solution obj;
	bool ans = obj.isBipartite(4, adj);    
	if(ans)cout << "1\n";
	else cout << "0\n"; 

    return 0;
}




// LEETCODE SOLUTION

  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n); // 0: uncolored; 1: color A; -1: color B
        
    queue<int> q; // queue, resusable for BFS    
	
    for (int i = 0; i < n; i++) {
      if (color[i]) continue; // skip already colored nodes
      
      // BFS with seed node i to color neighbors with opposite color
      color[i] = 1; // color seed i to be A (doesn't matter A or B) 
      for (q.push(i); !q.empty(); q.pop()) {
        int cur = q.front();
        for (int neighbor : graph[cur]) 
		{
          if (!color[neighbor]) // if uncolored, color with opposite color
          { color[neighbor] = -color[cur]; q.push(neighbor); } 
		  
          else if (color[neighbor] == color[cur]) 
            return false; // if already colored with same color, can't be bipartite!
        }        
      }
    }
    
    return true;
  }