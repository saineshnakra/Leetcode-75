class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string temp1,temp2;
        string res;
        if(str1.size()>str2.size()){
            temp1 = str2;
            temp2 = str1;
        }
        else{
            temp1 = str1;
            temp2 = str2;
        }
        string temp = "";
        for(int i = 0;i<temp1.size();i++){
            temp = temp + temp1.at(i);
            string finalTemp = temp;
            if(temp1.size()%temp.size()!=0){
                continue;
            }
            int n = temp1.size()/temp.size();
            string newTemp = temp;
            temp = "";
            while(n>0){
                
                temp = temp + newTemp;
            n--;
            }

            if(temp==temp1){

            temp = newTemp;
            if(temp2.size()%temp.size()!=0){
                continue;
            }
            n = temp2.size()/temp.size();
            temp = "";
           
            while(n>0){
                temp = temp + newTemp;
                n--;
            }

            if(temp==temp2){
                res = finalTemp;
            }   
            }
                            temp = newTemp;

        }
        return res;
    }
};
