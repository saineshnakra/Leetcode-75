class Solution {
public:
    vector<int> disjoint_set;
    
    // Initialize disjoint set and rank
    void init(int n) {
        disjoint_set.resize(n);
        for (int i = 0; i < n; ++i) {
            disjoint_set[i] = i;
        }
    }
    
    int find(int v) {
        if (disjoint_set[v] != v) {
            disjoint_set[v] = find(disjoint_set[v]); // Path compression
        }
        return disjoint_set[v];
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    void un(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            disjoint_set[rooty] = rootx; // Union operation
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // Not enough cables
        
        init(n);

        int cables = 0;
        for (const auto& connection : connections) {
            if (!connected(connection[0], connection[1])) {
                un(connection[0], connection[1]);
            } else {
                cables++;
            }
        }

        set<int> unique_parents;
        for (int i = 0; i < n; ++i) {
            unique_parents.insert(find(i));
        }

        int components = unique_parents.size();
        return (cables >= components - 1) ? components - 1 : -1;
    }
};