class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long i_result = 0;
        vector<long long>new_list;
        for(int i = 0;i<nums.size();i++){
            long long sum_list = 0;
            for(int j = i;j<nums.size();j++){
                sum_list+=nums[j];
                new_list.push_back(sum_list);
            }
        }
        sort(new_list.begin(),new_list.end());
        for(int i = left-1; i<=right-1&&i<new_list.size();i++){
            i_result += new_list[i];
        }
        return i_result% 1000000007;
    }
};