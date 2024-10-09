class Solution {
public:
    void multibfs(vector<vector<int>>& mat, vector<vector<int>>& res, int row, int col ){
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<pair<int, int>, int>>q;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(res[i][j]==0){
                    q.push(make_pair(make_pair(i,j),0));
                }
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int x = curr.first.first;
            int y = curr.first.second;
            int dist = curr.second;
            for(int i = 0;i<4;i++){
                int curr_x = x + dir[i][0];
                int curr_y = y + dir[i][1];
                if(curr_x>=0&&curr_x<row&&curr_y>=0&&curr_y<col&&res[curr_x][curr_y]>dist+1){
                    res[curr_x][curr_y] = dist+1;
                    q.push(make_pair(make_pair(curr_x, curr_y),dist+1));
                }
            }
        }
        return;

    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int row = mat.size();
       int col = mat[0].size();
       vector<vector<int>>res(row, vector<int>(col,INT_MAX));
       for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            if (mat[i][j] == 0) res[i][j] = 0;
        }
       }
       multibfs(mat, res, row, col);
       return res; 
    }
};