class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>res;
        unordered_map<int,int>m;
               if(score.size()==0){
            return res;
        }
        for(int i = 0;i<score.size();i++){
            m[score.at(i)] = i;  
        }
        for(int i = 0;i<score.size();i++){
            res.push_back(to_string(i));
        }
        sort(score.begin(),score.end(), greater<int>());
        res[m[score.at(0)]] = "Gold Medal";
        if(score.size()==1){
            return res;
        }
        res[m[score.at(1)]] = "Silver Medal";
                if(score.size()==2){
            return res;
        }
        res[m[score.at(2)]] = "Bronze Medal";
         if(score.size()<=3){
            return res;
        }
        for(int i = 3;i<score.size();i++){
            res[m[score.at(i)]] = to_string(i+1);
        }
        return res;
    }
};
