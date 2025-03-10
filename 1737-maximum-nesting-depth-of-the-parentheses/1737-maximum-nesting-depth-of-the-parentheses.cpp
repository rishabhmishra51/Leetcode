class Solution {
public:
    int maxDepth(string s) {
        int ans = INT_MIN;
          int c=0;
        for(int i=0;i<s.length();i++){
          
            if(s[i]=='('){
                c++;
                 ans = max(ans,c);
            }
          
            else if(s[i]==')'){
                c--;
            }
            else {
                continue;
            }
           
        }
        if(ans == INT_MIN) return 0;
        return ans;
    }
};