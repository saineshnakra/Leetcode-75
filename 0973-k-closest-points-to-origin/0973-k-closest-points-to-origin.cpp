class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        vector<pair<float,int>>dis;
        for(int i = 0;i<points.size();i++){
            float d = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
            dis.push_back(make_pair(d,i));
        }
        sort(dis.begin(),dis.end(),[&](pair<float,int>a, pair<float,int> b){
            return a.first<b.first;
        });

        for(int i = 0;i<k&&i<points.size();i++){
            res.push_back(points[dis[i].second]);
        }
        return res;
    }
};