class Solution {
public:

   static bool cmp(pair<char,int>&a , pair<char,int>&b){
    return a.second>b.second;
   }
    string frequencySort(string s) {
         unordered_map<char,int>mp;
        for(auto i : s){
            mp[i]++;
        }
        string ans;
       vector<pair<char,int>> arr(mp.begin(),mp.end());
       sort(arr.begin(),arr.end(),cmp);

        for(auto & it:arr){
            for(int i=0;i<it.second;i++){
                ans+=it.first;
            }
        }

        return ans;
    }
};