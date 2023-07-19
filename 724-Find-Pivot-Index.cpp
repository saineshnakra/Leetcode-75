class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       vector<int>left(nums.size(),0);
       int tot = nums.at(0);
       for(int i = 1;i<nums.size();i++){
           left.at(i) = nums.at(i-1)+left.at(i-1);
           tot += nums.at(i);
       } 

       for(int i = 0;i<nums.size();i++){
           if(left.at(i)==tot-left.at(i)-nums.at(i)){
               return i;
           }
       }

    return -1;

    }
};
