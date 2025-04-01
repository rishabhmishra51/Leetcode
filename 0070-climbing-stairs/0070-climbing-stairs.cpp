class Solution {
public:

int topdown(int n,vector<int>&dp){
  
    // base case
    if(n==1 ){
      return n;
    }
    if(n==0) return 1;

     //step 3 check if answer already exist
    if(dp[n]!=-1) return dp[n];

    //step 2
    dp[n] = topdown(n-1,dp)+topdown(n-2,dp);
    return dp[n];
  }

    int climbStairs(int n) {
       vector<int>dp(n+1,-1);
        int ans =  topdown(n,dp);
        return ans;
    }
};