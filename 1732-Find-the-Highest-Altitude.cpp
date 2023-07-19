class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int m = 0;
        int alt = 0;
        for(int i = 0;i<gain.size();i++){
            alt+=gain.at(i);
            m = max(m,alt);
        }
        return m;
    }
};
