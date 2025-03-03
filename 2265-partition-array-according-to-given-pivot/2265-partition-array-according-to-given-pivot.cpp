class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>lesspivot;
        vector<int>equalpivot;
        vector<int>greaterpivot;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                greaterpivot.push_back(nums[i]);
            }
        }
          for(int i=0;i<n;i++){
            if(nums[i]==pivot){
                equalpivot.push_back(nums[i]);
            }
        }
          for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                lesspivot.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<lesspivot.size();i++){
            ans.push_back(lesspivot[i]);
        }
         for(int i=0;i<equalpivot.size();i++){
            ans.push_back(equalpivot[i]);
        }
         for(int i=0;i<greaterpivot.size();i++){
            ans.push_back(greaterpivot[i]);
        }
        return ans;
    }
};