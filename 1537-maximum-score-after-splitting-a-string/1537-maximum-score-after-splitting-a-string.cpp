class Solution {
public:
    int maxScore(string s) {
        int ans=0, zero=0;
       for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0') zero++;

            int one=0;
            for(int j=i+1;j<s.length();j++){
              if(s[j]=='1') one++;
            }
            int sum = zero+one;
            ans = max(ans,sum);
        }
      
        return ans;
    }
};