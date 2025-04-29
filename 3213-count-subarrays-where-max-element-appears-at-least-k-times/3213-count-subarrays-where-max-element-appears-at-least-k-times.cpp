class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE=*max_element(begin(nums),end(nums));
        int i=0;
        int j=0;
        int n=nums.size();
        int maxC=0;
       long long ans=0;
        while(j<n){
            if(nums[j]==maxE){
                maxC++;
            }
            while(maxC>=k){
                ans+=n-j;
                if(nums[i]==maxE) maxC--;

                i++;
            }
            j++;
        }
        return ans;
    }
};