#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// DFS

class Solution{
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        return(i>=0 && i<n && j>=0 && j<m && grid[i][j]==0);
    }

    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        grid[i][j] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int k=0; k<4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(isValid(nr, nc, n, m, grid)){
                dfs(nr, nc, n, m, grid);
            }
        }

    }

    int closedIslands(vector<vector<int>>& grid){
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
                    dfs(i, j, n, m, grid);
                }
            }
        }

        return ans;
    }
};



// BFS

class Solution{
private:
    bool isClosedIsland(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(grid[i][j]==-1 || grid[i][j]==1) return true;

        if(isOnPerimeter(i, j, n, m)) return false;

        grid[i][j] = -1;
        bool left = isClosedIsland(grid, i, j-1, n, m);
        bool right = isClosedIsland(grid, i, j+1, n, m);
        bool up = isClosedIsland(grid, i-1, j, n, m);
        bool down = isClosedIsland(grid, i+1, j, n, m);

        return left && right && up && down;
    }

    bool isOnPerimeter(int i, int j, int n, int m){
        return i==0 || j==0 || i==n-1 || j==m-1;
    }
public:
    int closedIslands(vector<vector<int>>& grid){
        if(grid.size()==0) return 0;

        int ans=0, n = grid.size(), m = grid[0].size();

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j]==0){
                    if(isClosedIsland(grid, i, j, n, m)){
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};


// DFS LEETCODE

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();

        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    int res = 1;
                    grid[i][j] = 1;
                    
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    
                    while(!q.empty()){
                        auto p = q.front();
                        q.pop();
                        
                        int x = p.first;
                        int y = p.second;
                   
                        for(int i=0; i<4; i++){
                            int nr = x + delr[i];
                            int nc = y + delc[i];

                            if(nr < 0 || nc >= m || nc < 0 || nr >= n){
                                res = 0;
                            }
                            else if(grid[nr][nc] == 0){
                                grid[nr][nc] = 1;
                                q.push({nr,nc});
                            }
                        }
                    }
                    
                    ans += res;
                }
            }
        }
        
        return ans;
    }
};



int main(){
    

    return 0;
}



