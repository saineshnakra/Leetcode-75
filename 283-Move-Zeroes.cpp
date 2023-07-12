class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while(i<nums.size()&&j<nums.size()){
        while(i<nums.size()&&nums.at(i)!=0){
        i++;
        }
        j = i;
        while(j<nums.size()&&nums.at(j)==0){
        j++;
        }
        if(i<nums.size()&&j<nums.size()&&nums.at(i)==0&&nums.at(j)!=0){
            swap(nums.at(i),nums.at(j));
        }
        }
    }
};

/*
We will use two pointers, i for zero position and j for non-zero position 
we will loop until i or j reaches the end of nums array.
1.first we will find i which is the latest zero 
2. Since we don't want to change the order we will bring the non zero pointer to this point too and then find the next non zero value 
to swap with the zero at i 
3. then we swap 
4. continue until the end
*/
