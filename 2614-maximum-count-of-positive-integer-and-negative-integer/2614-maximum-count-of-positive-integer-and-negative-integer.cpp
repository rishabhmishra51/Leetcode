class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posc=0;
        int negc=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) posc++;
            else if(nums[i]< 0) negc++;
        }
        return max(posc,negc);
    }
};