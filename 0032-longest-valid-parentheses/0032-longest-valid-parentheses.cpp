class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int maxlen=0;
        st.push(-1);
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(s[i]=='('){
                st.push(i);  //push index 
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i-st.top();
                    maxlen = max(len,maxlen);
                }
            }
        }
        return maxlen;
    }
};