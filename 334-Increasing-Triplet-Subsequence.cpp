class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int fir =   INT_MAX;
      int sec = INT_MAX;
    for(int i = 0;i<nums.size();i++){
        int x = nums.at(i);
        if(x<fir){
            fir = x;
        }
        else if(x>fir&&x<sec){
            sec = x;
        }
        else if(x>sec&&fir<sec){
            return true;
        }
    }
    return false;
    }
};
