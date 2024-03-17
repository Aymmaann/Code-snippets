class Solution {
public:
    vector<vector<int> > ways{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // write your code here
        int m=mat.size(), n=mat[0].size();
        vector<vector<int> > ans(m, vector<int>(n,-1));
        queue<pair<int,int> > q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int x=p.first, y=p.second;
            for(auto& way : ways){
                int new_x = x + way[0];
                int new_y = y + way[1];
                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && ans[new_x][new_y]==-1){
                    ans[new_x][new_y] = ans[x][y]+1;
                    q.push({new_x,new_y});
                }
            }
        }
        return ans;
    }
};
