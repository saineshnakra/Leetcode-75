class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string res = "";
        stack<string>st;
        for(int i = 0;i<s.size();i++){
            if(s.at(i)==' '&&temp.size()!=0){
                st.push(temp);
                temp = "";
            }
            else if(s.at(i)==' '){
                continue;
            }
            else{
                temp = temp + s.at(i);
            }
        }
        if(temp.size()!=0){
        st.push(temp);
        }
        while(st.empty()!=true){
            res = res +" ";
            res = res + st.top();
            st.pop();
        }
        res.erase(0,1);
        return res;
    }
};
