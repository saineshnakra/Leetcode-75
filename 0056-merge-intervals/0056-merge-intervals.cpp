class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>>pq;
    sort(intervals.begin(),intervals.end(),[&](vector<int>a, vector<int>b){
         if(a[0]<b[0]){
            return true;
         }
         else if(a[0]>b[0]){
            return false;
         }
         return a[1]>b[1];
    });
    for(int i = 0;i<intervals.size();i++){
        if(pq.empty()){
        pq.push(make_pair(intervals.at(i).at(0),intervals.at(i).at(1)));
        }
        else{
            int second = pq.top().second;
            if(second>=intervals.at(i).at(1)){
                continue;
            }
            else if(second<intervals[i][0]){
        pq.push(make_pair(intervals.at(i).at(0),intervals.at(i).at(1)));
            }
            else{
                int first = pq.top().first;
                pq.pop();
        pq.push(make_pair(first,intervals.at(i).at(1)));
            }
        }
    }
        vector<vector<int>>res;
        while(!pq.empty()){
            vector<int>temp;
            temp.push_back(pq.top().first);
            temp.push_back(pq.top().second);
            pq.pop();
            res.push_back(temp);
        }
            return res;

    }
};