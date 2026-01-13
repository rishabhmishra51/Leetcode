class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlen=0,start=0;

        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
            start=max(mp[s[i]]+1,start);
            }
            mp[s[i]]=i;
            maxlen=max(maxlen,i-start+1);
        }
        return maxlen;
    }
};