class Solution {
public:
    int minimumPushes(string word) {
        int res = 0;
        unordered_map<char, int> m;
        
        for (char c : word) {
            m[c]++;
        }
        
        vector<int> frequencies;
        for (const auto& entry : m) {
            frequencies.push_back(entry.second);
        }
        
        sort(frequencies.rbegin(), frequencies.rend());
        
        int count = 1;
        int assigned = 0;
        
        for (int freq : frequencies) {
            res += count * freq;
            assigned++;
            if (assigned % 8 == 0) {
                count++;
            }
        }
        
        return res;
    }
};
