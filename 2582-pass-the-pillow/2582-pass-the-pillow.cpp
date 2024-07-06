class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        bool front = true;
        while(time!=0){
            
            time--;
           
            if(front){
                i++;
                if(i==n){
                    front = false;
                }
            }
            else{
                i--;
                if(i==1){
                    front = true;
                }
            }
             if(time==0){
             return i;   
            }
        }
        return i;
    }
};