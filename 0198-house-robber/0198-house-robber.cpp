class Solution {
public:
int helper(vector<int>& arr,int i,vector<int>&dp){
      if(i>=arr.size()) return 0;
      if(dp[i]!=-1) return dp[i];
      int incl=0,excl=0;
      incl = arr[i] + helper(arr,i+2,dp);
       excl = helper(arr,i+1,dp);
       return dp[i]=max(incl,excl);
  }
    int rob(vector<int>& arr) {
         int n=arr.size();
      vector<int>dp(n+1,-1);
      return helper(arr,0,dp);  
    }
};