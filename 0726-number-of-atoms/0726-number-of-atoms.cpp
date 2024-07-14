class Solution {
public:
        string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> st;
        unordered_map<string, int> current;
        int n = formula.size();
        
        for (int i = 0; i < n;) {
            if (formula[i] == '(') {
                st.push(current);
                current.clear();
                ++i;
            } else if (formula[i] == ')') {
                int iStart = ++i, multiplicity = 0;
                while (i < n && isdigit(formula[i])) {
                    multiplicity = multiplicity * 10 + (formula[i++] - '0');
                }
                if (multiplicity == 0) multiplicity = 1;
                for (auto &p : current) {
                    p.second *= multiplicity;
                }
                if (!st.empty()) {
                    auto top = st.top();
                    st.pop();
                    for (auto &p : current) {
                        top[p.first] += p.second;
                    }
                    current = top;
                }
            } else {
                int iStart = i++;
                while (i < n && islower(formula[i])) ++i;
                string name = formula.substr(iStart, i - iStart);
                int multiplicity = 0;
                while (i < n && isdigit(formula[i])) {
                    multiplicity = multiplicity * 10 + (formula[i++] - '0');
                }
                if (multiplicity == 0) multiplicity = 1;
                current[name] += multiplicity;
            }
        }
        
        map<string, int> sortedAtoms(current.begin(), current.end());
        string result;
        for (const auto &p : sortedAtoms) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        
        return result;
    }
};