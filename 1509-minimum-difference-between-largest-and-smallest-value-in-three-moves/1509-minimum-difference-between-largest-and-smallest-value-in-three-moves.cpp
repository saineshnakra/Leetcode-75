class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mv = 3;
        int first = 0;
        int last = nums.size()-1;
        while(first!=last&&mv!=0){
            nums[last] = nums[first];
            last--;
            mv--;
        }
        sort(nums.begin(),nums.end());
        return nums[nums.size()-1]-nums[0];
    }
};