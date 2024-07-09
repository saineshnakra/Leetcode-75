class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
       double res = 0;
       int chef_time = 0;
       vector<int>wait_time;
       for(int i = 0;i<customers.size();i++){
        chef_time = max(chef_time,customers[i][0]) + customers[i][1];
        wait_time.push_back(chef_time-customers[i][0]);
       }
       for(int i = 0;i<wait_time.size();i++){
        res += wait_time[i];
       } 
       return (double)res/wait_time.size();
    }
};