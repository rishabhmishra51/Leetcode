class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        // int lesscount=0;
        // int equalcount=0;

        // for(int i=0;i<n;i++){
        //     if(nums[i]==pivot) equalcount++;
        //     else if(nums[i]<pivot) lesscount++;
        // }
        // int i=0;
        // int j=lesscount;
        // int k=equalcount+lesscount;
        // vector<int>ans(n);
        // for(int &num :nums){
        //     if(num < pivot){
        //         ans[i]=num;
        //         i++;
        //     }
        //     else if(num == pivot){
        //         ans[j]=num;
        //         j++;
        //     }
        //     else{
        //         ans[k]=num;
        //         k++;
        //     }
        // }
        // return ans;
        //O(n) tc and O(1) sc


        int i=0;
        int j=n-1;
        int i_=0;
        int j_=n-1;
        vector<int>ans(n);
        while(i<n && j>=0){
            if(nums[i]<pivot){
                ans[i_]=nums[i];
                i_++;
            }
            if(nums[j]>pivot){
                ans[j_]=nums[j];
                j_--;
            }
            i++;
            j--;
        }
        while(i_<=j_){
            ans[i_]=pivot;
            i_++;
        }
        return ans;
    }
};