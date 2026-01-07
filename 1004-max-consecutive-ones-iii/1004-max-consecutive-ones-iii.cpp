class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Window grows greedily

        // If flips go negative → shrink window

        // At the end, window is the largest valid one
        int n = nums.size();
        int left = 0;
        for(int right=0;right<n;right++){
            if(nums[right]==0)k--;
            
            if(k<0){
                if(nums[left]==0) k++;
                left++;
            }
        }
        return n-left;
    }
};