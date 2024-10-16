class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<char> cs;
        int res = 0;
        int curr = 0;
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (cs.find(s[i]) == cs.end()) {
                cs.insert(s[i]);
                curr++;
                res = max(res, curr);
            } else {
                while (left < i && s[left] != s[i]) {
                    cs.erase(s[left]);
                    left++;
                }
                cs.erase(s[left]);
                left++;
                cs.insert(s[i]);
                curr = cs.size();
                res = max(res, curr);
            }
        }
        return res == 0 ? 1 : res;
    }
};