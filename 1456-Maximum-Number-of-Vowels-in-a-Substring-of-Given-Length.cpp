class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int res = 0;
        int temp = 0;
        for(int i = 0;i<k;i++){
            if(isVowel(s.at(i))){
                temp++;
            }
        }
        res = temp;
        for(int i = k;i<s.size();i++){
            if(isVowel(s.at(i))){
            temp++;
            }
            if(isVowel(s.at(i-k))){
                temp--;
            }
            res = max(res,temp);
        }
        return res;
    }
};
