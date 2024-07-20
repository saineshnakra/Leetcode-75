class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
            int m = rowSum.size();
            int n = colSum.size();
            vector<vector<int>>res(m,vector<int>(n,0));
            for(int i = 0;i<rowSum.size();i++){
                for(int j = 0;j<colSum.size();j++){
                    if(rowSum[i]==0||colSum[j]==0){
                        res[i][j] = 0;
                    }
                    else{
                        res[i][j] = min(rowSum[i],colSum[j]);
                        rowSum[i] -= res[i][j];
                        colSum[j] -= res[i][j];
                    }
                }
            }
            return res;
    }
};