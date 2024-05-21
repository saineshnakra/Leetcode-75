class Solution {
public:
    void rec(set<vector<int>>& res, vector<int>&nums, int it, vector<int>& ans){
        if(it>=nums.size()){
            res.insert(ans);
            return;
        }
        ans.push_back(nums[it]);
        rec(res, nums, it+1,ans);
        ans.pop_back();
        rec(res,nums,it+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       set<vector<int>>res;
       vector<int>curr;
       rec(res,nums,0,curr);
       vector<vector<int>>ans;
       for(auto it: res){
        ans.push_back(it);
       }       
       return ans; 
    }
};