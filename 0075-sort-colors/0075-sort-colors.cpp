class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red_count = 0;
        int blue_count = 0;
        int white_count = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0){
                red_count++;
            }
            else if(nums[i]==1){
                white_count++;
            }
            else{
                blue_count++;
            }
        }
        int k = 0;
        while(red_count!=0){
            nums[k] = 0;
            red_count--;
            k++;
        }
        while(white_count!=0){
            nums[k] = 1;
            white_count--;
            k++;
       
        }
        while(blue_count!=0){
            nums[k] = 2;
            blue_count--;
            k++;
       
        }
        
    }
};