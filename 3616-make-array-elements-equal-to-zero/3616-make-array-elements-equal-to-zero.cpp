class Solution {
public:
    bool check(vector<int>& nums,int count,int idx,int dir){
        vector<int>temp=nums;
        while(idx>=0&&idx<nums.size()&& count>0){
            if(temp[idx]>0){
                temp[idx]--;
                dir*=-1;
                if(temp[idx]==0) count--;
            }
            idx+=dir;
        }
        return count==0;
    }
    int countValidSelections(vector<int>& nums) {
        int result=0;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) count++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(check(nums,count,i,-1)) result++;
                if(check(nums,count,i,1)) result++;
            }
        }
        return result;
    }
};