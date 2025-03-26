class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;
      while(i<j && s[i]==s[j]){
            char ch=s[i];
           while(s[i]==ch && i<j){
              i++;
            }
            while(s[j]==ch && j>= i){
                j--;
            }
        }
        return j-i+1;
    }
};