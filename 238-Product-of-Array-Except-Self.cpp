class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res;
        int mul = 1;
        int flag = 0;
        int zerFlag = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums.at(i)!=0){
                mul *=nums.at(i);
                flag = 1;
            }
            else{
                zerFlag = 1;
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(zerFlag&&nums.at(i)!=0&&flag){
                res.push_back(0);
            }
            else if(flag==0){
                res.push_back(0);
            }
            else if(nums.at(i)==0&&flag!=0){
                int temp = 1;
                for(int j = 0;j<nums.size();j++){
                    if(i==j){
                       continue; 
                    }
                    else{
                    temp = temp*nums.at(j);
                    }
                }
                res.push_back(temp);
            }
            else{
                res.push_back(mul/nums.at(i));
            }
        }

        return res;
    }

};
