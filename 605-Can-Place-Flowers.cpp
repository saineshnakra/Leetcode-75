class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int no) {
        int n = flowerbed.size();

        vector<bool>left(n,false);
        vector<bool>right(n,false);

        if(no<=0){
            return true;
        }
        left.at(0) = false;
        right.at(n-1) = false;
        for(int i = 1;i<n;i++){
            if(flowerbed.at(i-1)==1){
                left.at(i) = true;
            }
        }
        for(int i = n-2;i>=0;i--){
            if(flowerbed.at(i+1)==1){
                right.at(i) = true;
            }
        }
        
        for(int i = 0;i<n;i++){
            if(left.at(i)==right.at(i)&&right.at(i)==false&&flowerbed.at(i)!=1){
                no--;
                if(i+1<=n-1){
                    left.at(i+1) = true;
                }
                if(i-1>=0){
                    right.at(i-1) = true;
                }
                if(no<=0){
                    return true;
                }
            }
        }
        return false;
    }
};
