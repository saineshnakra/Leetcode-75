class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int,vector<int>>m;
        for(int i = 0;i<nums.size();i++){
            m[nums.at(i)].push_back(i);
        }
        //dubious value uptil nums.size() will have to check
        for(int i = 0;i<nums.size();i++){
            if(k-nums.at(i)<0){
                continue;;
            }
            if(m.find(k-nums.at(i))!=m.end()&&m.find(nums.at(i))!=m.end()){
                 
                m[k-nums.at(i)].pop_back();
               if(m[nums.at(i)].empty()){
                    m.erase(nums.at(i));
                    continue;
                }
                m[nums.at(i)].pop_back();
                if(m[nums.at(i)].empty()){
                    m.erase(nums.at(i));
                }
                if(m[k-nums.at(i)].empty()){
                    m.erase(k-nums.at(i));
                }
                                cnt++;

            }
            else{
                continue;
            }
        }
        return cnt;
    }
};
