class Solution {
public:
    int minimumPushes(string word) {
        int res = 0;
        unordered_map<char, int> m;
        
        // Count frequency of each character
        for (char c : word) {
            m[c]++;
        }
        
        // Collect frequencies into a vector
        vector<int> frequencies;
        for (const auto& entry : m) {
            frequencies.push_back(entry.second);
        }
        
        // Sort frequencies in descending order
        sort(frequencies.rbegin(), frequencies.rend());
        
        int count = 1;
        int count_times = 0;
        
        // Calculate minimum pushes
        for (int freq : frequencies) {
            count_times++;
            if (count_times % 8 == 0) {
                count++;
            }
            res += count * freq;
        }
        
        return res;
    }
};