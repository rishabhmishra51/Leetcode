class Solution {
public:
 int usingRecursion(int curr, int prev, vector<int>& nums) {
      
        if (curr >= nums.size()) return 0;

       
        int exclude = usingRecursion(curr + 1, prev, nums);

      
        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + usingRecursion(curr + 1, curr, nums);
        }

    
        return max(include, exclude);
    }

  int usingmemo(int curr, int prev, vector<int>& nums, vector<vector<int>>&dp){
       if (curr >= nums.size()) return 0;


        if (dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }

        // Option 1: Exclude the current element and move to the next
        int exclude = usingmemo(curr + 1, prev, nums, dp);


        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + usingmemo(curr + 1, curr, nums, dp);
        }

        // Store the result in the dp table and return the maximum of include and exclude
        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
  }

  int usingTab(int curr, int prev, vector<int>& nums){
    int n = nums.size();
      vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

      for(int curr = n-1;curr >= 0;curr--){
        for(int prev = curr-1;prev >=-1;prev--){
           
             int exclude = dp[curr + 1][prev+1];

        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + dp[curr + 1][curr+1];
        }
        dp[curr][prev+1] = max(include,exclude);
        }
        
      }
      return  dp[0][0];
  }
    int lengthOfLIS(vector<int>& nums) {
        // return usingRecursion(0, -1, nums); 
     int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

       
        // return usingmemo(0, -1, nums, dp);
          
          return usingTab(0,-1,nums);
    }
};