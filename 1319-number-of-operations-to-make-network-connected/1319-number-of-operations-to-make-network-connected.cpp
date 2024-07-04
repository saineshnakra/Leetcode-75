class Solution {
public:
    vector<int> disjoint_set;
    int find(int v) { return disjoint_set[v]; }
    bool connected(int x, int y) { return find(x) == find(y); }
    void un(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            return;
        }
        for (int i = 0; i < disjoint_set.size(); i++) {
            if (disjoint_set[i] == rooty) {
                disjoint_set[i] = rootx;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables = 0;
        for (int i = 0; i < n; i++) {
            disjoint_set.push_back(i);
        }
        for (int i = 0; i < connections.size(); i++) {
            if (!connected(connections[i][0],connections[i][1])){
                un(connections[i][0],connections[i][1]);
            }
            else{
                cables++;
            }
        }
        set<int>s;
        for(int i = 0;i<disjoint_set.size();i++){
           cout<<disjoint_set[i]<<" ";
           s.insert(disjoint_set[i]);
        }

    return cables>=s.size()-1?s.size()-1:-1;
    }
};