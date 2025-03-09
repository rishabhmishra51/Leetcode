class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string ans;
        int cnt = 0; 

        for (int i = 0; i < n; i++) { 
            if (s[i] == '(') {
                if (cnt > 0) ans.push_back('(');
                cnt++;
            } 
            else if (s[i] == ')') {
                cnt--;
                if (cnt > 0) ans.push_back(')');
            }
        }
        return ans;
    }
};