class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       vector<bool>res;
       int m = 0;
       for(int i = 0;i<candies.size();i++){
           m = max(m,candies.at(i));
       }
       for(int i = 0;i<candies.size();i++){
           res.push_back(candies.at(i)+extraCandies>=m);
       } 
       return res;
    }
};
