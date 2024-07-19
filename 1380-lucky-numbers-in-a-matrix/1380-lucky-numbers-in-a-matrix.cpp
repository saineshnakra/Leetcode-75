class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>res;
        int n = matrix.size();
        if(n==0){
            return res;
        }
        int m = matrix[0].size();
        
        vector<int>min_row(n,INT_MAX);
        vector<int>max_col(m,INT_MIN);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<matrix[i].size();j++){
            min_row.at(i) = min(min_row.at(i),matrix[i][j]);
            }
        }
        for(int i = 0;i<m;i++){
            int temp = -1;
            for(int j = 0;j<n;j++){
            if(max_col.at(i)<matrix[j][i]){
            max_col.at(i) = matrix[j][i];
            temp = j;
            }
            }
            if(min_row.at(temp)==max_col.at(i)){
                res.push_back(min_row.at(temp));
            }
        }
        return res;
    }
};