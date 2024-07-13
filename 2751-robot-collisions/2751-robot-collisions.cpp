class Solution {
  vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // Step 1: Create a vector of indices and sort it based on positions
        int n = positions.size();
        vector<int> indices(n);
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        // Step 2: Initialize the stack and process the robots based on sorted order
        stack<int> st;
        vector<int> sorted_healths(n);
        vector<char> sorted_directions(n);

        for (int i = 0; i < n; ++i) {
            sorted_healths[i] = healths[indices[i]];
            sorted_directions[i] = directions[indices[i]];
        }

        for (int i = 0; i < n; ++i) {
            if (st.empty() || sorted_directions[st.top()] == sorted_directions[i] || sorted_directions[st.top()] == 'L') {
                st.push(i);
            } else {
                while (!st.empty() && sorted_directions[st.top()] == 'R' && sorted_healths[st.top()] < sorted_healths[i]) {
                    sorted_healths[i] -= 1;
                    sorted_healths[st.top()] = 0;
                    st.pop();
                }
                if (st.empty() || sorted_directions[st.top()] != 'R') {
                    if (sorted_healths[i] > 0) {
                        st.push(i);
                    }
                } else if (sorted_healths[st.top()] == sorted_healths[i]) {
                    sorted_healths[st.top()] = 0;
                    sorted_healths[i] = 0;
                    st.pop();
                } else {
                    sorted_healths[st.top()] -= 1;
                    sorted_healths[i] = 0;
                }
            }
        }

        // Step 3: Collect results in the original order
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            if (sorted_healths[i] > 0) {
                result[indices[i]] = sorted_healths[i];
            }
        }

        // Step 4: Filter out the zero health values
        vector<int> final_result;
        for (int i = 0; i < n; ++i) {
            if (result[i] > 0) {
                final_result.push_back(result[i]);
            }
        }

        return final_result;
    }
};