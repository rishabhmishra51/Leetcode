
class Solution {
public:
   
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>result;
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size();i++){
             if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                long long k = j+1;
               long long l = nums.size()-1;
                while(k<l){
                   long long sum = nums[i];
                   sum +=nums[j];
                    sum +=nums[k];
                     sum +=nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                      result.push_back(temp);
                        k++,l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                     else if (sum < target) k++;
                     else l--;
                }
            }
        }
        return result;
    }
};