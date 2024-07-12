class Solution {
public:
    int maximumGain(string s, int x, int y) {
       int res = 0;
       int aCount = 0;
       int bCount = 0;
       int lesser = min(x,y);
       for(int i = 0;i<s.size();i++){
        char c = s[i];
        if(c>'b'){
            res+= min(aCount,bCount)*lesser;
            aCount = 0;
            bCount = 0;
        }
        else if(c=='a'){
            if(y>x&&bCount!=0){
                bCount--;
                res+=y;
            }
            else{
                aCount++;
            }
        }
        else{
            if(y<x&&aCount!=0){
                aCount--;
                res+=x;
            }
            else{
                bCount++;
            }
        }
       }
        res += min(aCount,bCount)*lesser;
       return res; 
    }
};