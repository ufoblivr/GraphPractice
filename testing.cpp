#include<vector>

#include<iostream>
using namespace std;

class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        return(i>=0 && i<n && j>=0 && j<m && grid[i][j]==0);
    }

    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int ans){
        grid[i][j] = 1;
        ans++;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int k=0; k<4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(isValid(nr, nc, n, m, grid)){
                dfs(nr, nc, n, m, grid);
                ans++;
            }
        }

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i*j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==0){
                        dfs(i, j, n, m, grid);
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(i, j, n, m, grid, ans);
                }
            }
        }
        int mini = INT_MIN;
        int ansf = max(ans, mini);

        return ansf;
    }
};

int main(){
    

    return 0;
}