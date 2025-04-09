class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>s(nums.begin(),nums.end());
        int ops=0;
        for(auto x : s){
            if(x>k) ops++;
            else if(x<k) return -1;
        }
        return ops;
    }
};