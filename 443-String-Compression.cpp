class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;

        for(int j = 1, count = 1;j<=chars.size();j++,count++){
            if(j==chars.size()||chars.at(j)!=chars.at(j-1)){
                chars[i++] = chars[j-1];
                if(count>1){
                for(char x: to_string(count)){
                    chars[i++] = x;
                }
                }
                count = 0;
            }
        }
        return i;
    }
};

/*
We are supposed to do it in constant space, therefore we can use two pointers -> one for traversing and one for maintaining the output array
We will also maintain a count, to push in the array once we reach a new character. 
At the end we will return the value of i, because it stores position + 1 of the result array.
*/
