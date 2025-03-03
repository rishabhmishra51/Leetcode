class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int lesscount=0;
        int equalcount=0;

        for(int i=0;i<n;i++){
            if(nums[i]==pivot) equalcount++;
            else if(nums[i]<pivot) lesscount++;
        }
        int i=0;
        int j=lesscount;
        int k=equalcount+lesscount;
        vector<int>ans(n);
        for(int &num :nums){
            if(num < pivot){
                ans[i]=num;
                i++;
            }
            else if(num == pivot){
                ans[j]=num;
                j++;
            }
            else{
                ans[k]=num;
                k++;
            }
        }
        return ans;
    }
};