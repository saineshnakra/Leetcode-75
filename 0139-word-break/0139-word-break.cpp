class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool>m;
        if(s.size()==0){
            return true;
        }
        for(int i = 0;i<wordDict.size();i++){
            m[wordDict[i]] = true;
        }
        int start = 0;
        int finish = s.size();
        while(start<s.size()){
            cout<<s.substr(start,finish)<<endl;
            if(m[s.substr(start,finish)]){
                s = s.substr(finish,s.size());
                finish = s.size();
                if(s.size()==0){
                    cout<<"Exit here and true";
                    return true;
                }
            }
            else{
                if(start>=finish){
                    cout<<start<<" "<<finish<<endl;
                    cout<<"Exit here and false";
                    return false;
                }
                finish--;
            }
        }
        return false;
    }
};