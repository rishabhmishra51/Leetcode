class Solution {
public:
    int numberOfSubstrings(string s) {
        //If the domain is fixed and small — NEVER use a map. Use an array.
        vector<int>freq(3,0);
        int left=0,ans=0;
        for(int right=0;right<s.length();right++){
            freq[s[right]-'a']++;

            while(freq[0]>0&&freq[1]>0&& freq[2]>0){
                ans += (s.length()-right);
                freq[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};