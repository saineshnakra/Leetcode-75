class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int>pos(n);
        iota(pos.begin(),pos.end(),0);
        sort(pos.begin(),pos.end(),[&](int a, int b){
            return heights[a]>heights[b];
        });
        vector<string>res;
        for(int i = 0;i<pos.size();i++){
            res.push_back(names[pos[i]]);
        }
        return res;
    }
};