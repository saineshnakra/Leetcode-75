class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int size = nums.size();
        int zeroCount = 0;
        int left=0,right = 0;
        
        while(right<size){
            if(zeroCount<k){
                if(nums.at(right)==0){
                    zeroCount++;
                }
                right++;
                res = max(res,(right-left));
            }
            else{
                if(nums.at(left)==0){
                    zeroCount--;
                }
                left++;
            }
        }
        
        return res;
    }
};

