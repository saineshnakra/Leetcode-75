class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        int right = mid+1;
        int left = low;
        vector<int>temp;
        while(low<=mid&&right<=high){
            if(nums.at(low)<nums.at(right)){
                temp.push_back(nums.at(low));
                low++;
            }
            else{
                temp.push_back(nums.at(right));
                right++;
            }
        }
        while(low<=mid){
            temp.push_back(nums.at(low));
            low++;
        }
        while(right<=high){
            temp.push_back(nums.at(right));
            right++;
        }
        low = left;
        for(int i = low;i<=high;i++){
            nums.at(i) = temp.at(i-low);
        }
        
        return;
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if(low>=high){
            return;
        }
        int mid = (low+high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};