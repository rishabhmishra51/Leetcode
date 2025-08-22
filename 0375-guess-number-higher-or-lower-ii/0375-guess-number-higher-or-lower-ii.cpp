class Solution {
public:
    int usingrec(int s,int e){
        if(s>=e) return 0;
        int ans=INT_MAX;
        for(int i=s;i<e;i++){
            ans = min(ans,i+max(usingrec(s,i-1),usingrec(i+1,e)));
        }
        return ans;
    }
    int usingmemo(int s,int e , vector<vector<int>>&dp){
         if(s>=e) return 0;
         if(dp[s][e] != -1) return dp[s][e];
        int ans=INT_MAX;
        for(int i=s;i<=e;i++){
          ans= min(ans,i+ max(usingmemo(s,i-1,dp),usingmemo(i+1,e,dp)));
          
        }
        dp[s][e]=ans;
        return dp[s][e];
    }
   int usingtab(int n) {
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    
    for (int s = n; s >= 1; s--) {
        for (int e = s+1; e <= n; e++) {
            int ans = INT_MAX;
            for (int i = s; i <= e; i++) {
                int left = (i > s) ? dp[s][i-1] : 0;
                int right = (i < e) ? dp[i+1][e] : 0;
                ans = min(ans, i + max(left, right));
            }
            dp[s][e] = ans;
        }
    }
    return dp[1][n];
}

int getMoneyAmount(int n) {
    return usingtab(n);
}
};