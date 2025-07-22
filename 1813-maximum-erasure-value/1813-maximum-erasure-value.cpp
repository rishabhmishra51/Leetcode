class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int result=0;
        while(j<n){
            if(!st.count(nums[j])){
                sum+=nums[j];
                result=max(result,sum);
                st.insert(nums[j]);
                j++;
            }
            else{
                while(st.count(nums[j])&&i<n){
                    sum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
        }
        return result;
    }
};