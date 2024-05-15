class Solution {
public:
    int myAtoi(string s) {
        bool flag = false;
        bool digitStarted = false;
        bool sign = true;
        int res = 0;
        for(int i = 0;i<s.size();i++){
            if(flag==false&&s.at(i)==' '){
                continue;
            }
            else if(digitStarted&&(s.at(i)-'0'>9||s.at(i)-'0'<0)){
                return res;
            }
            else if(s.at(i)=='+'&&flag==false){
                sign = true;
                flag = true;
            }
            else if(s.at(i)=='+'&&flag==true){
                return 0;
            }
            else if(s.at(i)=='-'&&flag==true){
                return 0;
            }
            else if(s.at(i)=='-'&&flag==false){
                sign = false;
                flag = true;

            }
            else if(s.at(i)==' '&&flag!=false){
                break;
            }
            else if(s.at(i)-'0'>=0&s.at(i)-'0'<=9){
            int digit = s[i] - '0';
            if (sign && res > (INT_MAX - digit) / 10) return INT_MAX;
            if (!sign && res < (INT_MIN + digit) / 10) return INT_MIN;
                if(sign){
                res = res*10 + digit;
                }
                else{
                    res = res*10-digit;
                }
                flag = true;
                digitStarted = true;
            }
            else{
                break;
            }
        }
        return res;
    }
};