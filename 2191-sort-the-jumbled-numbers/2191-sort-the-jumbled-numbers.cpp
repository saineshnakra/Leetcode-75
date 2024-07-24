class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int>hidden_val(nums.size(),0);
        for(int i = 0;i<nums.size();i++){
            string temp  = to_string(nums[i]);
            int new_no = 0;
            int temp_size=0;
            while(temp_size!=temp.size()){
                new_no = mapping[(temp[temp_size]-'0')] + new_no*10; 
                temp_size++;
            }
            hidden_val[i] = new_no; 
            cout<<hidden_val[i]<<" ";
        }
        vector<int>pos(nums.size(),0);
        iota(pos.begin(),pos.end(),0);
        sort(pos.begin(),pos.end(),[&](int a, int b){
           return hidden_val[a]<hidden_val[b];
        });
        for(int i = 0;i<pos.size();i++){
            pos[i] = nums[pos[i]];
        }
        return pos;
    }
};