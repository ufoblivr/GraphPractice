#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
private:

public:
    int countRottenOranges(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        int visited[n][m];
        int cntFresh = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else{
                    visited[i][j] = 0;
                }
                if(grid[i][j]==1)
                    cntFresh++;
            }
        }

        int tm = 0;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        int cnt=0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow, ncol}, t+1});
                    visited[nrow][ncol] = 2;
                    cnt++;
                }
            }
        } 
        if(cnt!=cntFresh) return -1;

        return tm;
    }
};

int main(){
    
    
    return 0;
}