class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<int>ans;
        unordered_map<char,int>freqtxt,freqpat;
        for(int i=0;i<m;i++){
            freqpat[p[i]]++;
        }
        for(int i=0;i<n;i++){
            freqtxt[s[i]]++;

            if(i>=m){
                freqtxt[s[i-m]]--;
                if(freqtxt[s[i-m]]==0){
                    freqtxt.erase(s[i-m]);
                }
            }

            if(i>=m-1&& freqtxt==freqpat){
                ans.push_back(i-m+1);
            }
        }
    return ans;
    }
};