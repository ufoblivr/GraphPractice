#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dis(n, vector<int>(m,0));
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[row][col] = steps;

            for(int i=0; i<4; i++){
                int nbrrow = row + delrow[i];
                int nbrcol = col + delcol[i];

                if(nbrrow>=0 && nbrrow<n && nbrcol>=0 && nbrcol<m && vis[nbrrow][nbrcol]==0){
                    vis[nbrrow][nbrcol]=1;
                    q.push({{nbrrow, nbrcol}, steps+1});
                }
            }
        }
        return dis;
    }
};

int main(){
    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
	Solution obj;
	vector<vector<int>> ans = obj.nearest(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	
    return 0;
}




