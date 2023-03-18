#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
    int numberOfEnclaves(vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m] = {0};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};

        while(q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr = row + delr[i];
                int newc = col + delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0 && grid[newr][newc]==1){
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0) cnt++;
            }
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}