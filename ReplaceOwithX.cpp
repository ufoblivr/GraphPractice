#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delrow[], int delcol[]){
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<4; i++){
            int nbrrow = row + delrow[i];
            int nbrcol = col + delcol[i];

            if(nbrrow>=0 && nbrrow<n && nbrcol>=0 && nbrcol<m && !vis[nbrrow][nbrcol] && mat[nbrrow][nbrcol]=='O'){
                dfs(nbrrow, nbrcol, vis, mat, delrow, delcol);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int j=0; j<m; j++){
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0, j, vis, mat, delrow, delcol);
            }
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1, j, vis, mat, delrow, delcol);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i, 0, vis, mat, delrow, delcol);
            }
            if(!vis[i][n-1] && mat[i][m-1]=='O'){
                dfs(i, m-1, vis, mat, delrow, delcol);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

int main(){
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };
    
    Solution ob;
    
    vector<vector<char>> ans = ob.fill(5, 4, mat);
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}