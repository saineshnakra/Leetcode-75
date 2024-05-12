class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        unordered_map<string, bool>m;
        dp[0] = true;
        for(int i = 0;i<wordDict.size();i++){
            m[wordDict[i]] = true;
        }
        for(int i = 1;i<=s.size();i++){
            for(int j = 0;j<i;j++){
                if(dp[j]&&m[s.substr(j,i-j)]){
                    dp[i] = true;
                    continue;
                }
            }
        }
        return dp[s.size()];
    }
};