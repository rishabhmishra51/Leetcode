class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(begin(nums),end(nums));
        long long n=nums.size();
        for(int i=1;i<nums.size();i=i+3){
            if(nums[i]!=nums[i-1])
            return nums[i-1];
        }
        return nums[n-1];
    }
};