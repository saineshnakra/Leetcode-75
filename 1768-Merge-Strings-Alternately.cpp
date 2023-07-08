    class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0,j = 0;
        string res ="";
        bool flag = 0;
        while(i<word1.size()&&j<word2.size()){
            if(!flag){
            res += word1[i];
            i++;
            flag = 1;
            }
            else{
                res +=word2[j];
                j++;
                flag = 0;
            }
        }
        while(i<word1.size()){
            res += word1[i];
            i++;
        }
        while(j<word2.size()){
            res += word2[j];
            j++;
        }
        return res;
    }
};
