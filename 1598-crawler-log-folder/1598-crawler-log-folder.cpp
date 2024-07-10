class Solution {
public:
    int num_of_moves(string str){
        if(str=="./"){
            return 0;
        }
        if(str == "../"){
            return -1;
        }
        return 1;
    }
    int minOperations(vector<string>& logs) {
        int res = 0;
        for(int i = 0;i<logs.size();i++){
            res +=num_of_moves(logs[i]);
            res = max(0,res);
        }
        return res;
    }
};