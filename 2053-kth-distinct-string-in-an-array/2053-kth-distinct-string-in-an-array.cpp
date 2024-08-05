class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>m;
        for(int i = 0;i<arr.size();i++){
            if(m.find(arr[i])==m.end()){
                m[arr[i]] = i;
            }
            else{
                m[arr[i]] = -1;
            }
        }
        vector<pair<string,int>>dis_word;
        for(auto word_and_count: m){
            auto [word, count] = word_and_count;
            if(count!=-1){
                dis_word.emplace_back(word, count);
            }
        }
        sort(dis_word.begin(),dis_word.end(),[&](pair<string, int>a, pair<string, int>b){
return a.second<b.second;
        });
        if(dis_word.size()<k){
            return "";
        }
        return dis_word[k-1].first;
    }
};