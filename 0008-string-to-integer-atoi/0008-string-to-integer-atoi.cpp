class Solution {
public:
    int myAtoi(string s) {
        string trim_s = s;
        string res = "";
        char sign = 'n';
        int k = 0;
            while(k<trim_s.size()&&trim_s[k]-'0'<0||trim_s[k]-'0'>9){
                if(trim_s[k]!=' '&&trim_s[k]!='+'&&trim_s[k]!='-'){
                    return 0;
                }
                else{
                    if(sign!='n'){
                            return 0;
                        }
                    if(trim_s[k]=='+'||trim_s[k]=='-'){
                        sign = trim_s[k];
                    }
                }
                k++;
            }
            while(k<trim_s.size()&&trim_s[k]-'0'>=0&&trim_s[k]-'0'<=9){
                res += trim_s[k];
                k++;
            }
            cout<<res;
            unsigned long long ans = 0;
            for(int i = 0;i<res.size();i++){
                if (ans >= pow(2,31) and sign=='-'){   
                ans = pow(2,31);
            } 
            else if (ans >= pow(2,31)){
            ans = pow(2,31)-1;
            }
                ans = ans*10 + (res[i]-'0');
            }
            if (ans >= pow(2,31) and sign=='-'){   
                ans = pow(2,31);
            } 
            else if (ans >= pow(2,31)){
            ans = pow(2,31)-1;
            } 
            return sign=='+'||sign=='n'?ans:-ans;
           
    }
};