class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int res = 0;
        while(left<right){
            int temp = (right-left)*min(height.at(left),height.at(right));
            res = max(res,temp);
            if(height.at(left)<height.at(right)){
                left++;
            }
            else{
                right--;
            }
        }
        return res;
    }
};



/*
o(n2) approach : 
What will be doing here?
It is a very simple approach: run two loops and see the max product of the minimum height and the difference between the positions. However, 
this won't work since it will throw a TLE error. Still, we now have a basic brute force understanding of how to do it.

o(n) approach : 
Will take two pointers and place one at each end. Now we will move whichever pointer has a shorter height since we have seen its max value possible.
For example, if there is one with a height of 10 on the 8th position of the matrix and one with a height of 15 on the 1st position. Then the maximum height and distance 
between has been reached, so we can keep it out of consideration
*/
