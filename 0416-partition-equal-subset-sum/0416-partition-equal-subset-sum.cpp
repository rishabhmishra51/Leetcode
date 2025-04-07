class Solution {
public:
bool usingrecusion(int index,vector<int>& nums,int target){
    int n=nums.size();
    if(index >= n) return false;

    if(target < 0) return false;

    if(target == 0) return true;
   
   bool include = usingrecusion(index+1,nums,target-nums[index]);
    bool exclude = usingrecusion(index+1,nums,target);

    return (include || exclude);
}

bool usingmemo(int index,vector<int>& nums,int target, vector<vector<int>>&dp){
      int n=nums.size();
    if(index >= n) return false;

    if(target < 0) return false;

    if(target == 0) return true;

    if(dp[index][target] != -1){
        return dp[index][target];
    }
   
   bool include = usingmemo(index+1,nums,target-nums[index],dp);
    bool exclude = usingmemo(index+1,nums,target,dp);

  dp[index][target] = (include || exclude);
     return dp[index][target];
}

bool usingtabulation(int index,vector<int>& nums,int target){
     int n=nums.size();
     vector<vector<int>>dp(n+1,vector<int>(target+1,0));
      
       for(int i=0;i<n;i++){
        dp[i][0]= 1; 
       }
       for(int index=n-1;index>=0;index--){
        for(int t =1; t <= target;t++){
          bool include=0;
            if(t - nums[index] >= 0){
                include = dp[index+1][t-nums[index]];
            }
         bool exclude = dp[index+1][t];
               dp[index][t] = (include || exclude);
        }
       }
         return dp[0][target];
       }
      

bool usingSO(vector<int>& nums,int target){
    int n = nums.size();
    vector<int>curr(target+1,0);
     vector<int>next(target+1,0);
     curr[0]=1;
     next[0]=1;

     for(int index=n-1;index>=0;index--){
        for(int t=1;t<=target;t++){
  bool include=0;
   if(t - nums[index] >= 0){
     include = next[t - nums[index]];
   }
 bool exclude = next[t];
   curr[t] = (include||exclude);

     }
     //shift karna h
     next=curr ;
     }
    return next[target];
}
    bool canPartition(vector<int>& nums) {
       
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum & 1) return false;
        
         int target =   sum /2;

     
        // return usingrecusion(0,nums,target);


    //   vector<vector<int>>dp(n,vector<int>(target+1,-1));
      
    //     return usingmemo(0,nums,target,dp);

    // return usingtabulation(0, nums , target );
         
         return usingSO(nums,target);
    }
};