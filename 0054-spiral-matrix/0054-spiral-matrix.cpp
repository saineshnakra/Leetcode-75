class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int start_i = 0;
        int end_i = matrix.size() - 1;
        int start_j = 0;
        int end_j = matrix[0].size() - 1;
        int n = matrix[0].size() * matrix.size();
        while (res.size() < n) {
            int x = start_i;
            int y = start_j == 0 ? start_j : start_j + 1;
            while (y <= end_j) {
                res.push_back(matrix[x][y]);
                y++;
            }
            if (res.size() >= n) {
                return res;
            }
            y--;
            x++;
            while (x <= end_i) {
                res.push_back(matrix[x][y]);
                x++;
            }
            if (res.size() >= n) {
                return res;
            }
            x--;
            y--;
            while (y >= start_j) {
                res.push_back(matrix[x][y]);
                y--;
            }
            if (res.size() >= n) {
                return res;
            }
            y++;
            start_i++;
            end_j--;
            end_i--;
        }
        return res;
    }
};