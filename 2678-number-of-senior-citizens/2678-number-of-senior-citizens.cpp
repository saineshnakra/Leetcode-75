class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(int i = 0;i<details.size();i++){
            string temp = details[i].substr(11,2);
            int age = stoi(temp);
            if(age>60){
                res++;
            }
        }
        return res;
    }
};