class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float, pair<int, int>>,vector<pair<float, pair<int, int>>>,greater<pair<float, pair<int, int>>>>work;
        for(int j = 0;j<arr.size();j++){
            for(int i = 0;i<j;i++){
                float temp  = (float)arr[i]/arr[j];
                work.push(make_pair(temp,make_pair(i,j)));
            }
        }
        while(k>1){
            work.pop();
            k--;
        }
        auto [top, bottom] = work.top().second; 
        vector<int>res;
        res.push_back(arr[top]);
        res.push_back(arr[bottom]);
        return res;
        
    }
};