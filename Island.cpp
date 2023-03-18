#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
private:
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid){
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
        }

        for(int delrow = -1; delrow<=1; delrow++){
            for(int delcol = -1; delcol<=1; delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int countIsland(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        int cnt = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row, col, visited, grid);
                }
            }
        }
        return cnt;
    }
};



// LEETCODE SOLUTION

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};


int main(){
    

    return 0;
}