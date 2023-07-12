class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        if(s==t){
            return true;
        }
        while(j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
            if(i==s.size()){
                return true;
            }
        }
        return false;
    }
};

/*
We will maintain two pointers one in s and one in t, we will increment according to the if statement defined. 
If i reaches the end of s, we know that it is a subsequence, thus return true 
*/
