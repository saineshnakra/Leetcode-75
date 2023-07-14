class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double result = INT_MIN, temp = 0;
        for(int i = 0;i<k;i++){
            temp+=nums.at(i);
        }
        result = max(result,temp);
        for(int i = k;i<nums.size();i++){
            temp = temp - nums.at(i-k) + nums.at(i);
            result = max(temp,result);
        }
        return result/k;
    }
};
