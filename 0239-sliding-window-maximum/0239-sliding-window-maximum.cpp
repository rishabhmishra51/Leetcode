class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int>res;

        for(int i=0;i<n;i++){
            //make space for new element
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            //for num[i] , no need to smaller element
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            // push i index
            dq.push_back(i);

            if(i>=k-1){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};