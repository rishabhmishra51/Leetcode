class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            //opening brackets
            if(ch=='(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char topch = st.top();
                    if(s[i]==')' && topch=='('){
                        st.pop();
                    }
                    else if(s[i]=='}' && topch=='{'){
                        st.pop();
                    }
                     else if(s[i]==']' && topch=='['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};