#include<iostream>
#include<vector>
using namespace std;

class DisjoinedSet{
    vector<int> rank, parent;
public:
    DisjoinedSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){

    }
};

int main(){
    DisjoinedSet ds(7);

    return 0;
}